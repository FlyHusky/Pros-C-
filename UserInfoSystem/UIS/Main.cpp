#include <stdio.h>
#include <stdlib.h>  //用于system("PAUSE"),防止程序在调试运行时一闪而过。
#include<string.h>

#include "Main.h"

int 

int main(){
	//打印显示欢迎信息！
	printf("---------------Welcom to the User Infomations Manage Sytem---------------\n");
	
	//用户登录，密码验证！
	if(Login()==false){
		system("PAUSE");
		return 0;	
	}
	
	printf("Login In OK!  \n");
	
	//打印命令帮助信息！。
	printf("%s\n",HelpInfo);

	int order=1;
    char command[11]={0}; //存储命令，命令最多10个字符

	//程序主体，接收用户输入指令，同时交互。
	while(order>0){
		memset(command,0,sizeof(command));
		printf(">");
		fflush(stdin);	//清零stdin，在VC中可用，但是linux下怎么办啊。。。。
	    fgets(command,sizeof(command),stdin);	//从stdin，读入n-1个数据。
	 	if(strlen(command)<=0){ //没收接收到字符
			continue; //继续下次循环
		}
		if(command[strlen(command)-1]=='\n'){	//判断第5个字符是不是回车符-\n.  
			command[strlen(command)-1]='\0';	// 如果是回车符，就替换为结束符号\0,
		}
		
		//1-退出命令
		if(ArrayCompare(command,CMD_EXIT)){
			printf("press any key to exit the system!!! \n");
			break;
		}

		//2-添加用户命令
		if(ArrayCompare(command,CMD_ADD)){
			printf("press any key to exit the system!!! \n");
			break;
		}




		printf("bad command:%s. Press \"help\" to get command infos \n",command);

	}
	system("PAUSE");
	return 1;
}

//添加用户信息
void AddUserInfo(){
	//user's id 由系统自动生成。
	printf("please input user's name(max 20 chars limited)");


}

//比较两个数组内容是否相等
bool ArrayCompare(const char* arr1, const char* arr2){
	int i,k;
	k=strlen(arr1); //系统密码
	i=strlen(arr2);	//输入密码

	if(i!=k){
		return false;
	}
	for(i=0;i<k;i++){
		if(arr1[i]!=arr2[i]){
			return false;
		}
	}
	return true;
}


//用户登录密码验证，true=正确  false=失败
bool LoginPassInput(const char* syspass){
	
	//printf("syspass=%s strlen(syspass)=%d\n",syspass,strlen(syspass));

	printf(">please input your password:");

	char pass[11]; //密码最大位数10位，这里最后一位手动放入 \0
	
	// scanf("%s",pass);  //scanf 输入超出范围的会溢出，不安全。
				//n=6
	fgets(pass,sizeof(pass),stdin);	//从stdin，读入n-1个数据。
	
	if(pass[strlen(pass)-1]=='\n'){	//判断第5个字符是不是回车符-\n.  
		pass[strlen(pass)-1]='\0';	// 如果是回车符，就替换为结束符号\0,
	}
	//综上，使用fgets函数，可以安全的获取输入。若要获取n个字符，需定义一个n+1长度的字符数组。

	//printf("strlen(pass)=%d \n",strlen(pass));
	//printf("%s\n",pass);

	//密码验证对比
	int i,k;
	k=strlen(syspass); //系统密码
	i=strlen(pass);	//输入密码

	if(i!=k){
		return false;
	}
	for(i=0;i<k;i++){
		if(syspass[i]!=pass[i]){
			return false;
		}
	}
	return true;
}

//用户登录，允许输入3次密码。
bool Login(){

	int retime=3;

	while(retime>0){
		retime--;
		if(LoginPassInput(&SysPass[0])){
			return true;
		}
		printf(">password is wrong! \n");
	}
	return false;
}



