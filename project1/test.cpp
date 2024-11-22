#include"stdafx.h"
#include<iostream>
#include"WindowProcess.h"

int main()
{
	WindowProcess cmd;
	cmd.StartProcess("D:\\ffmpeg\\ffmpeg-2024-08-01-git-bcf08c1171-full_build\\bin\\ffmpeg.exe", {"-h"});
	return 0;
}