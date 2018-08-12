#ifndef _MAIN_H
#define _MAIN_H

#define Clear_Stdin fflush(stdin);

bool LoginPassInput(const char* syspass);
bool Login();
bool ArrayCompare(const char* arr1, const char* arr2);

const char SysPass[]="a1b2c3";	//ÃÜÂë
const char HelpInfo[]="add:add user infos | view:view user infos | find:find wanted user infos | del:delete wanted user | exit:exit system | more:get more";//°ïÖúĞÅÏ¢

//ÃüÁî×Ö
const char CMD_ADD[]="add";
const char CMD_VIEW[]="view";
const char CMD_FIND[]="find";
const char CMD_DEL[]="del";
const char CMD_EXIT[]="exit";




#endif