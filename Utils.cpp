//=================================
// included dependencies

#include "Utils.h"
#include <Windows.h>

std::string utils::getWorkingDir()
{
	char buf[256];
	GetCurrentDirectoryA(256, buf);
	return std::string(buf) + '\\';

}
