#ifndef _MY_SCAN_H
#define _MY_SCAN_H

// 输入一个字符串, 存到output里(左右的空白字符会被自动去掉)
char* AfGetString(char* output);

// 获取一个整数, 如果输入为空则返回默认值defValue
int AfGetInt(int defValue);

// 获取一个小数, 如果输入为空则返回默认值defValue
double AfGetDouble(double defValue);

// 获取单字符输入, 如果输入为空则返回默认值defValue
char AfGetChar(char defValue);

// 获取bool型输入, 如果输入为空则返回默认值defValue
// 支持"yes", "no" | "1", "0" | "true", "false"
bool AfGetBool(bool defValue);


#endif