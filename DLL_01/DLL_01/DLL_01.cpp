// DLL_01.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"


__declspec(dllexport) int PingFang(int a)
{
	return a*a;
}