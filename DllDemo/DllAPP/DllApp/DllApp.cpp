// DllApp.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdlib.h>

#include "husky.h"

//指定使用哪个库
#pragma comment(lib, "DllDemo1.lib")

#define dllimp __declspec(dllimport) 

//声明使用到的函数。
dllimp int Add(int a, int b);


int _tmain(int argc, _TCHAR* argv[])
{
	int res = Add(11 , 22);
	printf("res=%d",res);

	printf("FLY=%d",GetFly());

	system("pause");
	return 0;
}

