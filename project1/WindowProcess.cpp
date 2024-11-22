#include "stdafx.h"
#include "WindowProcess.h"

WindowProcess::WindowProcess()
{
	// 初始化STARTUPINFO结构体
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	si.dwFlags |= STARTF_USESTDHANDLES;
	si.hStdOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	si.hStdInput = GetStdHandle(STD_INPUT_HANDLE);
	ZeroMemory(&pi, sizeof(pi));
}

bool WindowProcess::StartProcess(const std::string & exe_path, const std::vector<std::string>& cmd_args)
{
	if (!fs::exists(exe_path))
	{
		ERR_LOG("程序路径不存在:%s\n",exe_path);
	}
	std::string full_path = "";
	// 要启动的程序路径和参数
	for (int i = 0; i < cmd_args.size(); i++)
	{
		full_path += " ";
		full_path += cmd_args[i];
	}
	LPCSTR szCmdline = full_path.c_str();

	// 创建进程
	if (!CreateProcess(
		const_cast<LPSTR>(exe_path.c_str()),           // 应用程序名称
		const_cast<LPSTR>(szCmdline), // 命令行
		NULL,           // 进程安全属性
		NULL,           // 线程安全属性
		TRUE,          // 句柄继承选项
		0,              // 创建标志
		NULL,           // 使用父进程的环境块
		NULL,           // 使用父进程的当前目录
		&si,            // STARTUPINFO指针
		&pi             // 接收PROCESS_INFORMATION
	)) {
		ERR_LOG("创建进程失败\n");
		return false;
	}

	// 关闭进程和线程句柄
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
	return false;
}
