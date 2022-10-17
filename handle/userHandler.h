
/**
* untitled1
* @autor WH
* @data 2022~07~08~17:20
* @motto 不满足是向上的车轮！
*/
#include "../model/User.h"
#ifndef UNTITLED1_USERHANDLER_H
#define UNTITLED1_USERHANDLER_H
int UserLoginHandle(User user);
int UserRegisterHandle(User user);
//用户是否存在
int isUserExit(char * username);
//获取用户列表
int GetUserData(User user_arr[],int * user_count);
//获取单个用户的账号密码
User GetUserInfo(char user_info[]);
#endif //UNTITLED1_USERHANDLER_H
