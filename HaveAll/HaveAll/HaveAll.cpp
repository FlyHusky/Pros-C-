// HaveAll.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include <stdlib.h>  //����system("PAUSE"),��ֹ�����ڵ�������ʱһ��������

#include <string.h>  //������string

#include"My_Scan.h"

#include <time.h>
 

#include <iostream> // C++ ��׼��
using std::cout;	//��iostream���е�cout������������������ڳ�����Ҫдstd::cout
using std::endl;



//1��-----------��ʾ�ṹ��-----------
struct UserInfo 
{
	unsigned short id;
	char name[20];
	char phoneNumber[11];
	UserInfo* next;  //��һ����ַ��
};

//�ṹ���У������Ĵ洢���ж������⡣����char��int��һ��ʱ��char��ռ��4���ֽڡ�C++û��Ҫ����䣬�Ǳ�����������顣
struct Object
{
	char a;	//
	char i; // a, i ��һ�ֽڶ���
	int b; // b ��4�ֽڶ��䡣  
};

// void func(Object obj)  �ṹ�崫ֵ��ʽ
// void func(Object* obj) �ṹ�崫ָ�뷽ʽ



void ScanTest();
void ShowType();
void ShowArray();
void ShowZuanYi();
void ShowOperateBit();
void BiaoDaShi();
void ShowFor();		//��ʾForѭ��

void ShowPointer(); //��ʾָ��
int avg(const int* arr, int len);
void StringCopy();
void ShowScan();

int AddUserInfo(UserInfo* user);

void ShowMalloc();	//��ʾmalooc
	
void ShowLianBiao(); //��ʾ����

void ShowTime();	//ʱ����ʾ
time_t time_convert(int year, int month, int day, int hour, int minute, int second);

extern void MyPrinter();	//�������ļ����ú�����

void ShowFile();

 
int number = 0; //ȫ�ֱ���


//������������
int& test(){
	return number;
}



int _tmain(int argc, _TCHAR* argv[])
{

//----------------��ʾ����������������--------------
/*	int& r=test();

	r=111;  //��ʱnumberҲ��111
	printf("%d,%d \n",r,number);

	//����ֵ��������Ϊ��ֵ�����度��

	test()=333;
	printf("%d,%d \n",r,number); */
//-------------------------------------------------
	srand(100);	//�������������
	//rand() ����0-RAND_MAX ֮�������  RAND_MAX������stdlib.h �У�ֵ������3���ɡ�
	//rand()%n  �Ϳ��Եõ�0-n֮�������
	for(int k=0;k<5;k++){
		printf("%d \n",rand()%50);
	}


    //��ʾsprintf ��������ʽ�����뵽�ַ����顣
	/*
	char na[100];
	sprintf(&na[0],"haha%d",rand()%50);
	printf("%s \n",na);
	*/







	
	//cout << "iostream ��C++�ı�׼��" << endl;			//��ǰ��ʹ���� using std::cout;
	//std::cout<< "iostream ��C++�ı�׼��" << std::endl;	//Ҳ��������д��
	
	//const ������ʾ, ����ͨ���ô�д��ĸ��ʾ

/*	const double PI=3.1415926;

	//pi=3.144; �����ܸ�pi��ֵ
	printf("double pi=%lf \n",PI);


	printf("Hello C++ World! \n");   //printf��ӡ������C������ stdio ��ĺ���
	//C++ ��C���Ե�����������C++������C��


	//����վλ���
	printf("the number is:%4d \n",6);
	printf("the number is:%4d \n",53);
	printf("the number is:%4d \n",231);
	printf("the number is:%4d \n",1235);
*/
    //������
/*	double fa = 1234.245;
	printf("������fa=%lf \n",fa);

	//ָ��С��λ������������(������β��>=6���Ż��λŶ)
	printf("��λС��fa=%.2lf \n",fa);


	//�ӿ���̨��ȡ���� scanf����.(scan ��ʾɨ�� f��ʾformat��������ʽɨ��)
	int scana=0;
	printf("please input a int value:");
	scanf("%d",&scana);
	printf("the value you input is:%d \n",scana);
	
	*/

	//ScanTest(); //��ʾscanf����

   // ShowType();	  //��ʾC++�е���������

	//ShowArray();		//��ʾ����

	//ShowZuanYi();		//��ʾת���ַ�

	//BiaoDaShi();		//��ʾһЩ���ʽ

	//ShowOperateBit(); //��ʾδ���������滹��switch

	  //ShowFor();		//��ʾFor ѭ��
	  //ShowPointer(); //��ʾָ��

	//StringCopy();

	// ShowScan();

	 //������ʾ��������û���Ϣ��
	 /*UserInfo user1;
     AddUserInfo(&user1);
     printf("---------------user's infomation--------------- \n");
	 printf("id \t name\t phonenumber\t \n");
	 printf("%d\t%s\t%s",user1.id,user1.name,user1.phoneNumber);
	 */


	//��ʾ�����ն�,ѭ�������û���������
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

	// MyPrinter(); ����My_Scan.cpp ����ʾ����ĺ����� 

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

//��ʾC++����������--����
void ShowType(){
	char c1=67;		//char  ��Χ -128 ~  127  ռ��1���ֽ��ڴ�
	char c2=68;
	printf("char 67=%c , 68=%c \n",c1,c2);
	printf("sizeof(char)=%d \n",sizeof(c1));

	short sd1=-32768;	//ռ��2���ֽڵ�����������3���ڵ����������short�� ��Ҫɶ����int
	short sd2=32767;
	printf("short: %d ~ %d ,sizeof(sd1)=%d \n",sd1,sd2,sizeof(sd1));

	int d1=2112344321;
	printf("int ��Χ ����21��,sizeof(d1)=%d , d1=%d",sizeof(d1),d1);

}

//��ʾ����
void ShowArray(){

	printf("this func show array in C++! \n");

	char arr[5]={1,3,5,7,9};
	//����Ĵ�Сֵ�������ǳ����������5�����泣���� int a =5;  arr[5] �ᱨ��ġ�

	char ci=0;

	for(ci;ci<5;ci++){
		printf("%d,",arr[ci]);
	}

	printf("\n");

	//�ַ�������,�������£�Ҳ����һ������ĸ��ֵ��
	char name[10]="Husky";  //���漸���յ���ASIC��0 ��\0��ʾ�ַ���������
	for(ci=0;ci<10;ci++){
		printf("%c,",name[ci]);
	}
	printf("\nname=%s \n", name);

	//�ӿ���̨��ȡ�����ַ���

	printf("please input some chars(max 10 chars limit) \n");
	gets(name);

	printf(" you input chars=%s \n", name);


}

//��ʾC++�е�ת���ַ�����ʵ��ASCII�����Ҳ�ж��塣
void ShowZuanYi(){
	//���������ת���ַ��� \n 0x0A  ����
	printf("new line! \nsecond line! %cthird line %c",0x0A,'\n');

	//����
	printf("\a");

	printf("\n");

	//�Ʊ��
	printf("123456789123456789\n");
	printf("ID\tName\tPhoneNumber\t\n");
	printf("1\tHusky\t18868427512\t\n");

	// ת����� "  ˫����
	printf("my name is \"FlyHusky\"");
}

//��ʾC++�У�����һ��ı��ʽ
void BiaoDaShi(){
	int a,b,c,d;
	a=b=c=d=1;
	printf("a=%d,b=%d,c=%d,d=%d \n",a,b,c,d);

	a=3;

	c= a>b;  //3>1 Ϊ�� c=1

	printf("c=a>b, c=%d\n",c);


	//�������ʽ
	c= d ? 111:222;  //���d>0 ��ô c=111, ����c=222
	printf("c= d ? 111:222  c=%d \n",c );

	d=100;
	char score; //����ɼ�90�ݣ�����A���������B
	score = (d>90) ? 'A' : 'B';
	printf("score is %c \n",score);
}


//��ʾλ����
void ShowOperateBit(){
	unsigned char a=0xff;
	a=a>>1;//����1λ������ֵ��
	printf("a=0xff; a>>=1; a=%d \n",a);  //255��2=127.

	a=3;
	a=a>>1;
	printf("a=3;a>>1;a=%d \n",a);

	//����-<<��ȡ��-~��������ʾ�ˣ����У���-&  ��-|  ���-^�� ����λ������������ʾ�ˣ�

	// �߼���&&  �߼���|| �߼��ǣ� ������ʾ��

	//Ӧ�þ�������1�� ����

	unsigned char flag =0;
	unsigned char reg1=0x03;

	//����Ҫ���Ĵ���Reg1�ĵ�5λ��1.

	flag=1<<4; //flag=0b0010 0000
	reg1 =reg1 | flag;

	printf("flag=0x%x, reg1=0x%x \n",flag,reg1);

	//Ӧ��ʵ������һ��unsigned int ������ת��Ϊ4���ֽڡ�
	unsigned int ui=0x12345678;
	unsigned char buf[4];

	buf[0]=ui>>24;
	buf[1]=ui>>16;
	buf[2]=ui>>8;
	buf[3]=ui;

	printf("ui=%x,%x,%x,%x \n",buf[0],buf[1],buf[2],buf[3]);

	ui = 4;

	switch(ui)   //switch ����ֻ�ܸ�����
	{
	case 1:			// case �������ֵ�������ǳ�����
		printf("1");  //һ��Ҫ��break
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

//��ʾfor ѭ��
void ShowFor(){
	short i=1;
	//��ʾ��ӡ��1 �� 100.

	for(;i<=100;i++){		//1-����ʡ�Ե�һ�����
		printf("%d,",i );
	}
	printf("\n");

	//2-����ʡ�Ե�1,2�����, ͬ����3�����Ҳ����ʡ�ԣ�����

	i=1;

	for(;;i++){
		printf("%d,",i);
		if(i>=100){
			break;
		}
	}
	printf("\n");

	i=1;
	//4-ȫ��ʡ�ԣ� ��ѭ��
	for(;;){
		printf("%d,",i);
		i++;
		if(i>=100){
			break;
		}
	}
	printf("\n");


	//5- continue ��䣬������һ��ѭ��ִ�С�

	printf("��ӡ������С��100��ż��\n");
	for(int k=1;k<=100;k++){
		
		if(k%2)
			continue;
		printf("%d ," ,k);
	}
	printf("\n");

	//��ʾwhile
	printf(" ��ʾwhile ѭ�� \n");
	  i=100;
	while(i-->0){
		printf("%d ," ,i);
	}

	//��ϰ����forѭ������ӡ������


	printf("\n");
 
	int wei=101;   //�ױ߿��,Ҫ��Ϊ������

	int temp=0;  //��ʱ����

	int xt=1;  //ѭ�������
 

	for(;xt<=wei;xt++){
		
		temp=(wei-(xt*2-1))/2;   //7- 2*2-1 = 4 /2 =2
		while(temp>0){
		    printf(" "); //���ַ�
		    temp--;
		}

		temp=xt*2-1;

		while(temp>0){
		    printf("*"); //���ַ�
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


//��ʾָ��
void ShowPointer(){
	int a =12324;
	int b=1;

	int* pa=&a; 

	printf("address of int *pa=%08x \n",pa);

	const int* p=&a;  //����ָ�룬�����޸�ָ��ָ���ֵ����ֵ�ˣ�ֻ�ܶ���
	//*p=12345;		//���뱨�����ܸ�ֵ
	a=12345	;		//����ͨ����
	p=&b;			//����ָ�����p,���Ը�ֵ�µĵ�ֵַ��

	int ia[10]={1,2,3,4,5,6,7,8,9,10};
	printf("avg=%d \n",avg(&ia[0] ,10));

	//int* p;   �����ûû�и�����ֵ����p��Ұָ�룬����ȫ��
	int* p1=0; //��λ��ָ�룬Ҳ����ȫ�����ǳ�����Խ���

	if (p1)
		printf("p1 ���ǿ�ָ�룡 \n");  //��ָ��һ��������ֵ������������
	else
		printf("p1 �ǿ�ָ�룡 \n");
 
	//��ȫ��ʹ��ָ�롣 1���ž�Ұָ�롣 2����ϰ��ʹ�ÿ�ָ��(ʹ��ǰ�ж�ָ���Ƿ�Ϊ��)
	//�����޷��ж�Ұָ���Ƿ�Ϊ�ա�
	//���飺 �ž���������Խ�硣
}

//��ʾconst����ָ�룬���ݱ�����
//�������ƽ��ֵ��arr-����ָ�룬 len-���ȡ�
//��const�ĺô��ǣ���ֹ�������޸����顣
int avg(const int* arr, int len){  //Ҳ����д int avg(const int p[], int len)
	int sum=0;
	for(int i=0;i<len;i++){
		sum=arr[i]+sum;  //Ҳ����д sum=*(arr+i)+sum;
	}
	  
	return sum/len;
}


//��ʾstrcpy ���������ַ���������char[]
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


//malloc ���Զ�̬���ڴ�������ռ䣬������ȴֻ��д������int[100]
//������ʾmalloc, �ռ�����󣬲�����ͬ���顣
//��˿�����go��������Ƭ�����������õ�Ŷ�������Զ������ġ�
//malloc �� free����ͬʱ���֣� ����ʹ����ɺ������ͷţ��������Ŷ��
void ShowMalloc(){
	int size = 1000* sizeof(UserInfo);	//���㵱���ṹ��
	UserInfo* users = (UserInfo*)malloc(size);

	for(int i=0; i<1000;i++){
		users[i].id = i+1;
		strcpy_s(users[i].name,"Husky");
		strcpy_s(users[i].phoneNumber,"number");
	}

	printf("%d,%s,%s",users[0].id,users[0].name,users[0].phoneNumber);

	free(users); //�ͷ�����Ŀռ�
}

 
//
void ShowLianBiao(){
//����
// int a =123;  int& r=a;   // ��ʵ r����a �ı����� r=100, ��ô a=100...
	int a =123;
	int b=456;
	int& c=a;  //�˴���Ϊ�󶨣� ��cָ��a.
	c=b;	//��ʱc=a=456,  ������c=aʱ�Ѿ�����,�޷��ٰ������Ķ�������дc=b,�Ǹ�ֵ456�������Ƕ�c�ڰ��ˡ�

}


//��ʾC���й�ʱ��ĺ�����
void ShowTime(){
	//------------------��ʾʱ��time.h-------------------
	//��Ȼ�ˣ�����Ҫ����time.h
	time_t now= time(NULL); //����1970-1-1 00:00:00 �����ڵ�����

	printf("time=%d \n",now);

      tm* ttime;

	ttime=localtime(&now);

	printf("%s",asctime(ttime));

	printf("year=%d \n",ttime->tm_year+1900);  //tm_year ��ʾ ��1900 �꿪ʼ��������
	printf("month=%d \n",ttime->tm_mon+1);	//�·ݴ�0��ʼ�ģ�Ҫ��1
	printf("day=%d \n",ttime->tm_mday);		//�·��е�������

	//1������300����Ǽ��¼��š�
	now=now + 300 * 24*3600; //���ϼ��������

	ttime=localtime(&now);

	printf("300����� %s",asctime(ttime));

	//����time_convert �������ӣ� 
	//���� 2018-8-6-12.26.0  �� 2020-1-1-11.11.11 ���˶�����
	time_t t1,t2,t3;

	t1=time_convert(2018,8,6,12,26,0);
	t2=time_convert(2020,1,1,11,11,11);
	t3=t2-t1;

	int days=t3/(24*3600);
	printf("days=%d \n",days);


}

//�����꣬�£��գ�ʱ���֣���ת��Ϊtime_t ��ʽ����
time_t time_convert(int year, int month, int day, int hour, int minute, int second){
	tm info = {0}; //tm �Ǹ�ʱ��ṹ���ڣ�time.h�ж���ġ�
	info.tm_year= year-1900;
	info.tm_mon=month-1;
	info.tm_mday=day;
	info.tm_min=minute;
	info.tm_hour=hour;
	info.tm_sec=second;

	time_t t= mktime(&info);
	return t;
}

//��ʾ�ļ�����
void ShowFile(){

   FILE * fp;
   fp = fopen ("..//..//file1.txt", "w+");         // ��һ��Ŀ¼ ..//file1.txt  ����һ��Ŀ¼ ..//..//file1.txt
   printf("create file1.txt \n");

   fprintf(fp, "%s %s %s %d", "We", "are", "in", 2014); //��һ��д�ļ��ķ�����

  /* double a=4 / 3.0;
   fwrite(&a,1,sizeof(a),fp);		//�ڶ���,���־���(�ֽ�д��)

   char text[16];
   sprintf(text,"%.2lf",a);			//����2λС�����ȸ�ʽ��λ�ַ�����Ȼ��д���ļ���(�ַ�д��)
   fwrite(text,1,strlen(text),fp);


   //�ṹ���д�롣
   Object obj={'M','C',1001};
   //4- ����д��
   fwrite(&obj,1,sizeof(obj),fp);	 //�ֽ�д�룬�ļ��ɶ�������
   */

   fclose(fp);


   //��ȡ�ļ�
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



