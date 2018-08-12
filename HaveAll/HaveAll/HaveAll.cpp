// HaveAll.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <stdlib.h>  //用于system("PAUSE"),防止程序在调试运行时一闪而过。

#include <string.h>  //服务于string

#include"My_Scan.h"

#include <time.h>
 

#include <iostream> // C++ 标准库
using std::cout;	//将iostream库中的cout导出，如果导出，则在程序中要写std::cout
using std::endl;



//1：-----------演示结构体-----------
struct UserInfo 
{
	unsigned short id;
	char name[20];
	char phoneNumber[11];
	UserInfo* next;  //下一个地址。
};

//结构体中，变量的存储会有对其问题。比如char和int在一起时，char会占用4个字节。C++没有要求对其，是编译器搞得事情。
struct Object
{
	char a;	//
	char i; // a, i 是一字节对其
	int b; // b 是4字节对其。  
};

// void func(Object obj)  结构体传值方式
// void func(Object* obj) 结构体传指针方式



void ScanTest();
void ShowType();
void ShowArray();
void ShowZuanYi();
void ShowOperateBit();
void BiaoDaShi();
void ShowFor();		//演示For循环

void ShowPointer(); //演示指针
int avg(const int* arr, int len);
void StringCopy();
void ShowScan();

int AddUserInfo(UserInfo* user);

void ShowMalloc();	//演示malooc
	
void ShowLianBiao(); //演示链表

void ShowTime();	//时间演示
time_t time_convert(int year, int month, int day, int hour, int minute, int second);

extern void MyPrinter();	//从其它文件引用函数。

void ShowFile();

 
int number = 0; //全局变量


//返回引用类型
int& test(){
	return number;
}



int _tmain(int argc, _TCHAR* argv[])
{

//----------------演示函数返回引用类型--------------
/*	int& r=test();

	r=111;  //此时number也是111
	printf("%d,%d \n",r,number);

	//返回值还可以作为左值，很腻害啊

	test()=333;
	printf("%d,%d \n",r,number); */
//-------------------------------------------------
	srand(100);	//设置随机数种子
	//rand() 返回0-RAND_MAX 之间的数。  RAND_MAX定义在stdlib.h 中，值至少是3万多吧。
	//rand()%n  就可以得到0-n之间的数。
	for(int k=0;k<5;k++){
		printf("%d \n",rand()%50);
	}


    //演示sprintf 函数，格式化输入到字符数组。
	/*
	char na[100];
	sprintf(&na[0],"haha%d",rand()%50);
	printf("%s \n",na);
	*/







	
	//cout << "iostream 是C++的标准库" << endl;			//在前面使用了 using std::cout;
	//std::cout<< "iostream 是C++的标准库" << std::endl;	//也可以这样写。
	
	//const 常量演示, 常量通常用大写字母表示

/*	const double PI=3.1415926;

	//pi=3.144; 错误不能给pi赋值
	printf("double pi=%lf \n",PI);


	printf("Hello C++ World! \n");   //printf打印函数是C语言中 stdio 库的函数
	//C++ 是C语言的升级，所以C++，包含C。


	//整数站位输出
	printf("the number is:%4d \n",6);
	printf("the number is:%4d \n",53);
	printf("the number is:%4d \n",231);
	printf("the number is:%4d \n",1235);
*/
    //浮点数
/*	double fa = 1234.245;
	printf("浮点数fa=%lf \n",fa);

	//指定小数位数并四舍五入(哈哈，尾数>=6，才会进位哦)
	printf("两位小数fa=%.2lf \n",fa);


	//从控制台获取输入 scanf函数.(scan 表示扫描 f表示format，即按格式扫描)
	int scana=0;
	printf("please input a int value:");
	scanf("%d",&scana);
	printf("the value you input is:%d \n",scana);
	
	*/

	//ScanTest(); //演示scanf输入

   // ShowType();	  //演示C++中的数据类型

	//ShowArray();		//演示数组

	//ShowZuanYi();		//演示转义字符

	//BiaoDaShi();		//演示一些表达式

	//ShowOperateBit(); //演示未操作，里面还有switch

	  //ShowFor();		//演示For 循环
	  //ShowPointer(); //演示指针

	//StringCopy();

	// ShowScan();

	 //以下演示用于添加用户信息。
	 /*UserInfo user1;
     AddUserInfo(&user1);
     printf("---------------user's infomation--------------- \n");
	 printf("id \t name\t phonenumber\t \n");
	 printf("%d\t%s\t%s",user1.id,user1.name,user1.phoneNumber);
	 */


	//演示命令终端,循环接收用户输入的命令。
/*	while(1){
		char cmdline[128];
		printf("> ");
		scanf("%s",cmdline);
		printf("cmd: %s \n",cmdline);
		
		if(strcmp(cmdline,"exit")==0){
			printf("now exit...\n");
			break;
		}
		
	}
	*/

	//ShowMalloc();

	// MyPrinter(); 条用My_Scan.cpp 内演示链表的函数。 

	 //ShowTime();
     
	ShowFile();

	system("PAUSE");
	return 0;
}






void ScanTest(){
	printf("This func Show Scanf! \n");

	double x =0;
	double y=0;

	printf("Please input the float value x=");
	scanf("%lf",&x);

	printf("Please input the float value y=");
	scanf("%lf",&y);

	double res = 0;
	res= x * y;

	printf("the x*y=%.2lf \n",res);
}

//演示C++中数据类型--整型
void ShowType(){
	char c1=67;		//char  范围 -128 ~  127  占用1个字节内存
	char c2=68;
	printf("char 67=%c , 68=%c \n",c1,c2);
	printf("sizeof(char)=%d \n",sizeof(c1));

	short sd1=-32768;	//占用2个字节的整数，正负3万内的数，最好用short。 不要啥都用int
	short sd2=32767;
	printf("short: %d ~ %d ,sizeof(sd1)=%d \n",sd1,sd2,sizeof(sd1));

	int d1=2112344321;
	printf("int 范围 正负21亿,sizeof(d1)=%d , d1=%d",sizeof(d1),d1);

}

//演示数组
void ShowArray(){

	printf("this func show array in C++! \n");

	char arr[5]={1,3,5,7,9};
	//数组的大小值，必须是常量，这里的5是字面常量。 int a =5;  arr[5] 会报错的。

	char ci=0;

	for(ci;ci<5;ci++){
		printf("%d,",arr[ci]);
	}

	printf("\n");

	//字符串声明,可以如下，也可以一个个字母赋值。
	char name[10]="Husky";  //后面几个空的是ASIC码0 即\0表示字符串结束。
	for(ci=0;ci<10;ci++){
		printf("%c,",name[ci]);
	}
	printf("\nname=%s \n", name);

	//从控制台获取输入字符。

	printf("please input some chars(max 10 chars limit) \n");
	gets(name);

	printf(" you input chars=%s \n", name);


}

//演示C++中的转义字符，其实在ASCII吗表中也有定义。
void ShowZuanYi(){
	//我们最常见的转义字符是 \n 0x0A  换行
	printf("new line! \nsecond line! %cthird line %c",0x0A,'\n');

	//响铃
	printf("\a");

	printf("\n");

	//制表符
	printf("123456789123456789\n");
	printf("ID\tName\tPhoneNumber\t\n");
	printf("1\tHusky\t18868427512\t\n");

	// 转义输出 "  双引号
	printf("my name is \"FlyHusky\"");
}

//演示C++中，特殊一点的表达式
void BiaoDaShi(){
	int a,b,c,d;
	a=b=c=d=1;
	printf("a=%d,b=%d,c=%d,d=%d \n",a,b,c,d);

	a=3;

	c= a>b;  //3>1 为真 c=1

	printf("c=a>b, c=%d\n",c);


	//条件表达式
	c= d ? 111:222;  //如果d>0 那么 c=111, 否则c=222
	printf("c= d ? 111:222  c=%d \n",c );

	d=100;
	char score; //如果成绩90份，就是A，否则就是B
	score = (d>90) ? 'A' : 'B';
	printf("score is %c \n",score);
}


//演示位操作
void ShowOperateBit(){
	unsigned char a=0xff;
	a=a>>1;//右移1位，并赋值。
	printf("a=0xff; a>>=1; a=%d \n",a);  //255除2=127.

	a=3;
	a=a>>1;
	printf("a=3;a>>1;a=%d \n",a);

	//左移-<<，取反-~，不在演示了，还有，与-&  或-|  异或-^， 都是位操作，不在演示了，

	// 逻辑与&&  逻辑或|| 逻辑非！ 不在演示。

	//应用举例，置1， 清零

	unsigned char flag =0;
	unsigned char reg1=0x03;

	//比如要给寄存器Reg1的第5位置1.

	flag=1<<4; //flag=0b0010 0000
	reg1 =reg1 | flag;

	printf("flag=0x%x, reg1=0x%x \n",flag,reg1);

	//应用实例，把一个unsigned int 整数，转换为4个字节。
	unsigned int ui=0x12345678;
	unsigned char buf[4];

	buf[0]=ui>>24;
	buf[1]=ui>>16;
	buf[2]=ui>>8;
	buf[3]=ui;

	printf("ui=%x,%x,%x,%x \n",buf[0],buf[1],buf[2],buf[3]);

	ui = 4;

	switch(ui)   //switch 后面只能跟整数
	{
	case 1:			// case 后面跟的值，必须是常量。
		printf("1");  //一定要加break
		break;
	case 2:
		printf("2");
		break;
	case 3:
		printf("3");
		break;
	case 4: case 5:
		printf("4,5");
		break;
	default:
		printf("0");
	}

	printf("\n");
}

//演示for 循环
void ShowFor(){
	short i=1;
	//演示打印从1 到 100.

	for(;i<=100;i++){		//1-可以省略第一个语句
		printf("%d,",i );
	}
	printf("\n");

	//2-可以省略第1,2个语句, 同样第3个语句也可以省略，不在

	i=1;

	for(;;i++){
		printf("%d,",i);
		if(i>=100){
			break;
		}
	}
	printf("\n");

	i=1;
	//4-全部省略， 死循环
	for(;;){
		printf("%d,",i);
		i++;
		if(i>=100){
			break;
		}
	}
	printf("\n");


	//5- continue 语句，继续下一个循环执行。

	printf("打印出所有小于100的偶数\n");
	for(int k=1;k<=100;k++){
		
		if(k%2)
			continue;
		printf("%d ," ,k);
	}
	printf("\n");

	//演示while
	printf(" 演示while 循环 \n");
	  i=100;
	while(i-->0){
		printf("%d ," ,i);
	}

	//练习，用for循环，打印金字塔


	printf("\n");
 
	int wei=101;   //底边宽度,要求为奇数。

	int temp=0;  //临时变量

	int xt=1;  //循环体变量
 

	for(;xt<=wei;xt++){
		
		temp=(wei-(xt*2-1))/2;   //7- 2*2-1 = 4 /2 =2
		while(temp>0){
		    printf(" "); //空字符
		    temp--;
		}

		temp=xt*2-1;

		while(temp>0){
		    printf("*"); //空字符
		    temp--;
		}

		temp =xt*2-1;

		if(temp>=wei){
			break;    
		}

		printf("\n");

	}

			printf("\n");
}


//演示指针
void ShowPointer(){
	int a =12324;
	int b=1;

	int* pa=&a; 

	printf("address of int *pa=%08x \n",pa);

	const int* p=&a;  //常量指针，不能修改指针指向的值。赋值了，只能读。
	//*p=12345;		//编译报错，不能赋值
	a=12345	;		//编译通过。
	p=&b;			//但是指针变量p,可以赋值新的地址值。

	int ia[10]={1,2,3,4,5,6,7,8,9,10};
	printf("avg=%d \n",avg(&ia[0] ,10));

	//int* p;   如果后没没有给他赋值，则p是野指针，不安全。
	int* p1=0; //即位空指针，也不安全，但是程序可以接受

	if (p1)
		printf("p1 不是空指针！ \n");  //空指针一般用于做值传给函数参数
	else
		printf("p1 是空指针！ \n");
 
	//安全的使用指针。 1：杜绝野指针。 2：好习惯使用空指针(使用前判断指针是否为空)
	//程序无法判断野指针是否为空。
	//数组： 杜绝访问数组越界。
}

//演示const修饰指针，内容保护。
//求数组的平均值，arr-数组指针， len-长度。
//加const的好处是，防止函数内修改数组。
int avg(const int* arr, int len){  //也可以写 int avg(const int p[], int len)
	int sum=0;
	for(int i=0;i<len;i++){
		sum=arr[i]+sum;  //也可以写 sum=*(arr+i)+sum;
	}
	  
	return sum/len;
}


//演示strcpy 函数，将字符串拷贝进char[]
void StringCopy(){
	char name[10];

	strcpy_s(name,"Husky");

	printf("%s\n",name);
}


void ShowScan(){
	char name[120];
	  
	  printf("please input some chars \n");

	  AfGetString(&name[0]);

	  printf("you input chars=%s \n",name);
	
}

int AddUserInfo(UserInfo* user){
	printf("--------------add userinfo-------------- \n");
	printf("please input user name's name(max 20 chars) \n");
	AfGetString(&user->name[0]);

	printf("please input user's id \n");
	user->id=AfGetInt(0);

	printf("please input user's phone number (max 10 chars) \n");
	AfGetString(&user->phoneNumber[0]);

	return 1;
}


//malloc 可以动态冲内存中申请空间，而数组却只能写个常量int[100]
//下面演示malloc, 空间申请后，操作如同数组。
//如此看来，go语言中切片，还是蛮好用的哦。容量自动增长的。
//malloc 和 free必须同时出现， 申请使用完成后，若不释放，后果严重哦。
void ShowMalloc(){
	int size = 1000* sizeof(UserInfo);	//计算当个结构体
	UserInfo* users = (UserInfo*)malloc(size);

	for(int i=0; i<1000;i++){
		users[i].id = i+1;
		strcpy_s(users[i].name,"Husky");
		strcpy_s(users[i].phoneNumber,"number");
	}

	printf("%d,%s,%s",users[0].id,users[0].name,users[0].phoneNumber);

	free(users); //释放申请的空间
}

 
//
void ShowLianBiao(){
//引用
// int a =123;  int& r=a;   // 其实 r就是a 的别名， r=100, 那么 a=100...
	int a =123;
	int b=456;
	int& c=a;  //此处称为绑定， 把c指向a.
	c=b;	//此时c=a=456,  引用在c=a时已经绑定了,无法再绑定其它的对象，这里写c=b,是赋值456，而不是对c在绑定了。

}


//演示C中有关时间的函数。
void ShowTime(){
	//------------------演示时间time.h-------------------
	//当然了，首先要导入time.h
	time_t now= time(NULL); //返回1970-1-1 00:00:00 到现在的秒数

	printf("time=%d \n",now);

      tm* ttime;

	ttime=localtime(&now);

	printf("%s",asctime(ttime));

	printf("year=%d \n",ttime->tm_year+1900);  //tm_year 表示 自1900 年开始的年数。
	printf("month=%d \n",ttime->tm_mon+1);	//月份从0开始的，要加1
	printf("day=%d \n",ttime->tm_mday);		//月份中的天数。

	//1：计算300天后，是几月几号。
	now=now + 300 * 24*3600; //加上间隔的秒数

	ttime=localtime(&now);

	printf("300天后是 %s",asctime(ttime));

	//利用time_convert 来算日子， 
	//计算 2018-8-6-12.26.0  到 2020-1-1-11.11.11 隔了多少天
	time_t t1,t2,t3;

	t1=time_convert(2018,8,6,12,26,0);
	t2=time_convert(2020,1,1,11,11,11);
	t3=t2-t1;

	int days=t3/(24*3600);
	printf("days=%d \n",days);


}

//传入年，月，日，时，分，秒转换为time_t 格式对象
time_t time_convert(int year, int month, int day, int hour, int minute, int second){
	tm info = {0}; //tm 是个时间结构体在，time.h中定义的。
	info.tm_year= year-1900;
	info.tm_mon=month-1;
	info.tm_mday=day;
	info.tm_min=minute;
	info.tm_hour=hour;
	info.tm_sec=second;

	time_t t= mktime(&info);
	return t;
}

//演示文件操作
void ShowFile(){

   FILE * fp;
   fp = fopen ("..//..//file1.txt", "w+");         // 上一级目录 ..//file1.txt  上上一级目录 ..//..//file1.txt
   printf("create file1.txt \n");

   fprintf(fp, "%s %s %s %d", "We", "are", "in", 2014); //第一种写文件的方法。

  /* double a=4 / 3.0;
   fwrite(&a,1,sizeof(a),fp);		//第二种,保持精度(字节写入)

   char text[16];
   sprintf(text,"%.2lf",a);			//保留2位小数，先格式化位字符串，然后写入文件。(字符写入)
   fwrite(text,1,strlen(text),fp);


   //结构体的写入。
   Object obj={'M','C',1001};
   //4- 整体写入
   fwrite(&obj,1,sizeof(obj),fp);	 //字节写入，文件可读性若。
   */

   fclose(fp);


   //读取文件
      fp = fopen ("..//..//file1.txt", "r");    
	  char buf[5];
	  buf[4]='\0';
	  while(!feof(fp)){
		int n=fread(buf,1,4,fp);
		if(n>0){
			printf("read form file %d bytes : %s \n",n,buf);
		}
	  }
	  fclose(fp);
}



