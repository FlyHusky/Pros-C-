#include"My_Scan.h"
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* �ӿ���̨����������͵�����ʾ�� 
   �﷨ƪ18�º������ȫ����scanf��ֱ��ʹ����һ��API
*/

// ȥ��ͷβ�Ŀհ��ַ�, ����һ��C����ַ���ָ��
// ע�� �������µ�buffer�������ڴ濽�����ƶ�
// �������Ϊ�㣬�򷵻�NULL
char* AfTrim(char* src)
{
	char* pStart = NULL;
	char* pEnd = NULL;
	char* p;
	
	// �ӵ�1���ַ���ʼɨ��
	for(p=src ; *p != '\0'; p ++ )
	{
		if(*p == ' ' || *p == '\t' || *p== '\n')
			;	
		else
		{
			pStart = p; // ��ͷ
			break;
		}
	}
	// ȫ��Ϊ�հ��ַ�
	if(pStart == NULL) 
	{
		*src = '\0';
		return NULL ;
	}
	// ����ɨ��
	bool nonBlank = true;
	for( ; ; p ++ ) 
	{
		if(*p == ' ' || *p == '\t' || *p== '\n' ||*p=='\0')
		{
			if(nonBlank)
			{
				pEnd = p;
				nonBlank = false;
			}
			if(*p == '\0') break;
		}
		else
		{
			nonBlank = true;
		}
	}

	// �ض�ĩβ�Ŀհ�
	*pEnd = '\0'; 

	// ��Ч����Ϊ0�����ؿ�ָ��
	if(pEnd == pStart) return NULL;

	return pStart; 
}

// ����һ���ַ���, ���ؽ��յ��ĳ���
char* AfGetString(char* output)
{
	char buf[512];
	gets_s(buf);
	char* str = AfTrim(buf);
	if(str == NULL)
	{
		output[0] = '\0';
		return NULL;
	}
	else
	{
		int n = strlen(str);
		memcpy(output, str, n + 1);
		return output;
	}
}

// ��ȡһ������
int AfGetInt(int defValue)
{
	char buf[512];
	char* str = AfGetString(buf);
	if(str == NULL)
		return defValue;
	else
		return atoi(str);
}

// ��ȡһ��С��
double AfGetDouble(double defValue)
{
	char buf[512];
	char* str = AfGetString(buf);
	if(str == NULL)
		return defValue;
	else
		return atof(str);
}

// ��ȡ���ַ�����
char AfGetChar(char defValue)
{
	char buf[512];
	char* str = AfGetString(buf);
	if(str == NULL)
		return defValue;
	else
		return str[0];
}

// ��ȡbool������
// ��ȡ���ַ�����
bool AfGetBool(bool defValue)
{
	char buf[512];
	char* str = AfGetString(buf);
	if(str == NULL)
		return defValue;
	else
	{
		if(strcmp(str, "YES") == 0
			|| strcmp(str, "yes") == 0
			|| strcmp(str, "1") == 0
			|| strcmp(str, "true") == 0
			|| strcmp(str, "TRUE") == 0)
			return true;
		return false;
	}
}



