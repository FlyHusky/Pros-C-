#ifndef _MY_SCAN_H
#define _MY_SCAN_H

// ����һ���ַ���, �浽output��(���ҵĿհ��ַ��ᱻ�Զ�ȥ��)
char* AfGetString(char* output);

// ��ȡһ������, �������Ϊ���򷵻�Ĭ��ֵdefValue
int AfGetInt(int defValue);

// ��ȡһ��С��, �������Ϊ���򷵻�Ĭ��ֵdefValue
double AfGetDouble(double defValue);

// ��ȡ���ַ�����, �������Ϊ���򷵻�Ĭ��ֵdefValue
char AfGetChar(char defValue);

// ��ȡbool������, �������Ϊ���򷵻�Ĭ��ֵdefValue
// ֧��"yes", "no" | "1", "0" | "true", "false"
bool AfGetBool(bool defValue);


#endif