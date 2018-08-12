#include"My_Scan.h"
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* 从控制台输入各种类型的数据示例 
   语法篇18章后可以完全不用scanf，直接使用这一套API
*/

// 去除头尾的空白字符, 返回一个C风格字符串指针
// 注： 不创建新的buffer，不作内存拷贝和移动
// 如果长空为零，则返回NULL
char* AfTrim(char* src)
{
	char* pStart = NULL;
	char* pEnd = NULL;
	char* p;
	
	// 从第1个字符开始扫描
	for(p=src ; *p != '\0'; p ++ )
	{
		if(*p == ' ' || *p == '\t' || *p== '\n')
			;	
		else
		{
			pStart = p; // 开头
			break;
		}
	}
	// 全部为空白字符
	if(pStart == NULL) 
	{
		*src = '\0';
		return NULL ;
	}
	// 继续扫描
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

	// 截断末尾的空白
	*pEnd = '\0'; 

	// 有效长度为0，返回空指针
	if(pEnd == pStart) return NULL;

	return pStart; 
}

// 输入一个字符串, 返回接收到的长度
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

// 获取一个整数
int AfGetInt(int defValue)
{
	char buf[512];
	char* str = AfGetString(buf);
	if(str == NULL)
		return defValue;
	else
		return atoi(str);
}

// 获取一个小数
double AfGetDouble(double defValue)
{
	char buf[512];
	char* str = AfGetString(buf);
	if(str == NULL)
		return defValue;
	else
		return atof(str);
}

// 获取单字符输入
char AfGetChar(char defValue)
{
	char buf[512];
	char* str = AfGetString(buf);
	if(str == NULL)
		return defValue;
	else
		return str[0];
}

// 获取bool型输入
// 获取单字符输入
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



