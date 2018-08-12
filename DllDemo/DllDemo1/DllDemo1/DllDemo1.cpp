// DllDemo1.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"

#define MYDLL_EXPORTS

//这里就可以写函数了，写好后，项目生产dll, 其它程序可以调用这里的函数，
//函数的头要加上 关键字  __declspec(dllexprot)

__declspec(dllexport) int Add(int a, int b)
{
	return a + b;
}



  int PingFang(int a)
{
	return a*a;
}