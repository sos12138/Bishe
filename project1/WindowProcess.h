#pragma once
#include<cstdlib>
class WindowProcess
{
public:
	WindowProcess();
	bool StartProcess(const std::string& exe_path, const std::vector<std::string>& cmd_args = {});
private:
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
};

