// DLL_01.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"


__declspec(dllexport) int PingFang(int a)
{
	return a*a;
}