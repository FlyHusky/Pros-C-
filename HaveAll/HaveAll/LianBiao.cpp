
#include "stdafx.h"
#include <string>
#include<sstream>
#include<iostream>

using std::string;
using 	std::stringstream;

//演示链表
struct Student{
	int id;
	string name;
	Student *next;
};

Student stus[100];


//通常使用链表，对象都是malloc出来的而不是定义一个数组，如果用数组定义，那么还有链表干啥啊哈哈。
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