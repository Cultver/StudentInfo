#include <stdio.h>
#include "model/User.h"
#include "handle/userHandler.h"
#include "common/Tips.h"
/**
* untitled1
* @autor WH
* @data 2022~07~08~16:58
* @motto �����������ϵĳ��֣�
*/
int login_clock = 3;
User UserLoginView();
User UserRegisterView();
 void main(){
    printf("#######################��ӭʹ��ѧ������ϵͳ: \n");
    printf("��ѡ��Ҫ���еĲ��� (1-��¼ 2-ע�� 0-�Ƴ�) : ");
    int user_action = 0;
    scanf(" %d",&user_action);
//    printf("%d\n",user_action);
     do {
         switch (user_action) {
             case LOGIN: {
                 int res = 0;
                 while (res <= 0){
                     printf("�����¼...\n");
                     User user = UserLoginView();
                     res = UserLoginHandle(user);
                     //            printf("res = %d",res);
                     if (!res) {
                         puts("��½ʧ��!");
                         login_clock--;
                         if(login_clock<=0){
                             puts("���ĵ�¼�����Ѿ�����!����ϵ����Ա!");
                             break;
                         }else{
                             printf("������%d�λ���\n",login_clock);
                         }
                     } else {
                         puts("��¼�ɹ�!");
                         user_action = 3;
                     }
                 }
             }
                break;
             case REGISTER: {
                 printf("����ע��... \n");
                 User user = UserRegisterView();
                 int result = UserRegisterHandle(user);
                 if (result) {
                     puts("ע��ɹ�!");
                     user_action = 3;
                 } else {
                     puts("ע��ʧ��!");
                 }
             }
                 break;
             case GOTO_STU_SYS:{
                 printf("###############��ӭ����ѧ������ϵͳ��\n");
                 printf("��ѡ����Ӧ�Ĳ���(1-���ѧ�� 2-ѧ���б� 3-ɾ��ѧ�� 4-�˳�):\n");
                 user_action = 0;
             }
             case EXIT:
                 printf("##################���˳�ϵͳ");
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