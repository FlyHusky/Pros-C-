// HelloWorld.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

using namespace std;

void BitDo();
struct Person
{
	int id;
	char sex;
	char name[16];
};

int main()
{
	printf("Hello C++ World!\n");

	Person p1 = { 1001,'m',"Haha" };

	BitDo();

    return 0;
}

//位操作(只对无符号数进行操作)

void BitDo() {
	
	unsigned int udi = 13;
	int cc;
	cc =  udi << 1;  //uc 左边 1位，相当于乘以2
	printf("cc=%d", cc);

	//右移 >>  不在演示，相当于除法2

	//取反  ~  

	udi = 0;
	unsigned int ud2 = ~udi;

	cout << ud2 << endl;

	printf("ud2=%x \n", ud2);   // 从运行结果可以看出，其类型是64位的int.

	// & | 与或运行，不在解释了。简单。

	udi = 0b1001;  //用2进制的方式给udi 赋值。
	ud2 = 0b1100;  

	cout << "udi=0b1001=" << udi << endl;

	cc = udi && ud2;  //=1  &&  按值 做 与运算
	cout << "udi && ud2 = " << cc << endl;

	cc = udi & ud2;   //=8  &  按位 做 与运算
    cout << "udi & ud2 = " << cc << endl;

	cc = udi | ud2; //=13  |  按位 做 或运算
	cout << "udi & ud2 = " << cc << endl;
}


// 演示 base64 编码
void  ShowBase64() {


}

//演示字符集， 不想去了解啥GBK，直接搞utf-8,全球通用
//Unicode 用数字0-0x10ffff来表示字符 (3个字节)

//编码方法：
//utf-32  用四个字节(int) 来表示字符，简单，但浪费空间
//utf-16  用1~2个 short，即1或2个字节，16位来存储字符
//utf-8	  用1~4个字节来表示字符，有个算法，


void ShowCharSet() {
	char name[] = "哈士奇";

	
}
