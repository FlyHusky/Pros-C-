// DllApp.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdlib.h>

#include "husky.h"

//ָ��ʹ���ĸ���
#pragma comment(lib, "DllDemo1.lib")

#define dllimp __declspec(dllimport) 

//����ʹ�õ��ĺ�����
dllimp int Add(int a, int b);


int _tmain(int argc, _TCHAR* argv[])
{
	int res = Add(11 , 22);
	printf("res=%d",res);

	printf("FLY=%d",GetFly());

	system("pause");
	return 0;
}

