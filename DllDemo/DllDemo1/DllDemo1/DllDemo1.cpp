// DllDemo1.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"

#define MYDLL_EXPORTS

//����Ϳ���д�����ˣ�д�ú���Ŀ����dll, ����������Ե�������ĺ�����
//������ͷҪ���� �ؼ���  __declspec(dllexprot)

__declspec(dllexport) int Add(int a, int b)
{
	return a + b;
}



  int PingFang(int a)
{
	return a*a;
}