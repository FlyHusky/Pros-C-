#include <stdio.h>
#include <stdlib.h>  //����system("PAUSE"),��ֹ�����ڵ�������ʱһ��������
#include<string.h>

#include "Main.h"

int 

int main(){
	//��ӡ��ʾ��ӭ��Ϣ��
	printf("---------------Welcom to the User Infomations Manage Sytem---------------\n");
	
	//�û���¼��������֤��
	if(Login()==false){
		system("PAUSE");
		return 0;	
	}
	
	printf("Login In OK!  \n");
	
	//��ӡ���������Ϣ����
	printf("%s\n",HelpInfo);

	int order=1;
    char command[11]={0}; //�洢����������10���ַ�

	//�������壬�����û�����ָ�ͬʱ������
	while(order>0){
		memset(command,0,sizeof(command));
		printf(">");
		fflush(stdin);	//����stdin����VC�п��ã�����linux����ô�찡��������
	    fgets(command,sizeof(command),stdin);	//��stdin������n-1�����ݡ�
	 	if(strlen(command)<=0){ //û�ս��յ��ַ�
			continue; //�����´�ѭ��
		}
		if(command[strlen(command)-1]=='\n'){	//�жϵ�5���ַ��ǲ��ǻس���-\n.  
			command[strlen(command)-1]='\0';	// ����ǻس��������滻Ϊ��������\0,
		}
		
		//1-�˳�����
		if(ArrayCompare(command,CMD_EXIT)){
			printf("press any key to exit the system!!! \n");
			break;
		}

		//2-����û�����
		if(ArrayCompare(command,CMD_ADD)){
			printf("press any key to exit the system!!! \n");
			break;
		}




		printf("bad command:%s. Press \"help\" to get command infos \n",command);

	}
	system("PAUSE");
	return 1;
}

//����û���Ϣ
void AddUserInfo(){
	//user's id ��ϵͳ�Զ����ɡ�
	printf("please input user's name(max 20 chars limited)");


}

//�Ƚ��������������Ƿ����
bool ArrayCompare(const char* arr1, const char* arr2){
	int i,k;
	k=strlen(arr1); //ϵͳ����
	i=strlen(arr2);	//��������

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


//�û���¼������֤��true=��ȷ  false=ʧ��
bool LoginPassInput(const char* syspass){
	
	//printf("syspass=%s strlen(syspass)=%d\n",syspass,strlen(syspass));

	printf(">please input your password:");

	char pass[11]; //�������λ��10λ���������һλ�ֶ����� \0
	
	// scanf("%s",pass);  //scanf ���볬����Χ�Ļ����������ȫ��
				//n=6
	fgets(pass,sizeof(pass),stdin);	//��stdin������n-1�����ݡ�
	
	if(pass[strlen(pass)-1]=='\n'){	//�жϵ�5���ַ��ǲ��ǻس���-\n.  
		pass[strlen(pass)-1]='\0';	// ����ǻس��������滻Ϊ��������\0,
	}
	//���ϣ�ʹ��fgets���������԰�ȫ�Ļ�ȡ���롣��Ҫ��ȡn���ַ����趨��һ��n+1���ȵ��ַ����顣

	//printf("strlen(pass)=%d \n",strlen(pass));
	//printf("%s\n",pass);

	//������֤�Ա�
	int i,k;
	k=strlen(syspass); //ϵͳ����
	i=strlen(pass);	//��������

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

//�û���¼����������3�����롣
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



