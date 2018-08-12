// DLL_02.cpp : 定义控制台应用程序的入口点。
//

//本文用于演示dll 类的导出

#include "stdafx.h"
#include "MyObject.h"  //这个是动态库my 的头文件，加入到这里。
//类 MyObject 在myObject.h 中定义。
 

#pragma comment(lib, "my.lib")

 
int _tmain(int argc, _TCHAR* argv[])
{
   MyObject obj(123);
   obj.Print();

   double x = 123.456;

   printf("x=%.2f \n",x);

	return 0;
}

