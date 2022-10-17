#include <stdio.h>
#include "model/User.h"
#include "handle/userHandler.h"
#include "common/Tips.h"
/**
* untitled1
* @autor WH
* @data 2022~07~08~16:58
* @motto 不满足是向上的车轮！
*/
int login_clock = 3;
User UserLoginView();
User UserRegisterView();
 void main(){
    printf("#######################欢迎使用学生管理系统: \n");
    printf("请选择要进行的操作 (1-登录 2-注册 0-推出) : ");
    int user_action = 0;
    scanf(" %d",&user_action);
//    printf("%d\n",user_action);
     do {
         switch (user_action) {
             case LOGIN: {
                 int res = 0;
                 while (res <= 0){
                     printf("处理登录...\n");
                     User user = UserLoginView();
                     res = UserLoginHandle(user);
                     //            printf("res = %d",res);
                     if (!res) {
                         puts("登陆失败!");
                         login_clock--;
                         if(login_clock<=0){
                             puts("您的登录次数已经用完!请联系管理员!");
                             break;
                         }else{
                             printf("您还有%d次机会\n",login_clock);
                         }
                     } else {
                         puts("登录成功!");
                         user_action = 3;
                     }
                 }
             }
                break;
             case REGISTER: {
                 printf("处理注册... \n");
                 User user = UserRegisterView();
                 int result = UserRegisterHandle(user);
                 if (result) {
                     puts("注册成功!");
                     user_action = 3;
                 } else {
                     puts("注册失败!");
                 }
             }
                 break;
             case GOTO_STU_SYS:{
                 printf("###############欢迎进入学生管理系统！\n");
                 printf("请选择相应的操作(1-添加学生 2-学生列表 3-删除学生 4-退出):\n");
                 user_action = 0;
             }
             case EXIT:
                 printf("##################已退出系统");
                 break;
             default:
                 break;
         }
     } while (user_action>2||user_action<0);



 }
User UserRegisterView(){
    User user = {};
    printf("Plase enter account: \n");
    scanf("%s",user.username);
    printf("Plase enter password: \n");
    scanf("%s",user.password);
//            printf("%s%s",user.password,user.username);
    return user;
 }
User UserLoginView(){
    User user = {};
    printf("Plase enter account: \n");
    scanf("%s",user.username);
    printf("Plase enter password: \n");
    scanf("%s",user.password);
//            printf("%s%s",user.password,user.username);
    return user;
}