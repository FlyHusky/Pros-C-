
#include "stdafx.h"
#include <string>
#include<sstream>
#include<iostream>

using std::string;
using 	std::stringstream;

//��ʾ����
struct Student{
	int id;
	string name;
	Student *next;
};

Student stus[100];


//ͨ��ʹ������������malloc�����Ķ����Ƕ���һ�����飬��������鶨�壬��ô���������ɶ��������
void LB_Show(){
		string name("haha");
	    string stu_name("");

  
	for(int i=0;i<100;i++){
	    stringstream stream;  
		stus[i].id=i+1;
		stream << i;
		stu_name=name+ stream.str();
		stream.clear();
		std::cout << stu_name << std::endl;
		stus[i].name=stu_name; 
		 
	}

	for( int i=0;i<99;i++){
		stus[i].next = & stus[i+1];
	}
	stus[99].next=NULL;

	Student* p = &stus[0];
    std::cout  << "id\t"   <<" name\t" <<std::endl;

	while(p){
		
		std::cout << p->id << "\t" << p->name <<"\t" <<std::endl;
		p=p->next;
	
	}

}

void MyPrinter(){
	  LB_Show();
}