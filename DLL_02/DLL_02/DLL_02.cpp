// DLL_02.cpp : �������̨Ӧ�ó������ڵ㡣
//

//����������ʾdll ��ĵ���

#include "stdafx.h"
#include "MyObject.h"  //����Ƕ�̬��my ��ͷ�ļ������뵽���
//�� MyObject ��myObject.h �ж��塣
 

#pragma comment(lib, "my.lib")

 
int _tmain(int argc, _TCHAR* argv[])
{
   MyObject obj(123);
   obj.Print();

   double x = 123.456;

   printf("x=%.2f \n",x);

	return 0;
}

