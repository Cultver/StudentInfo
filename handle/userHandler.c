#include "userHandler.h"
#include <stdio.h>
#include <string.h>
#include "../common/Config.h"
#include "../common//StringUtils.h"
#include "../common/Tips.h"

/**
* untitled1
* @autor WH
* @data 2022~07~08~17:21
* @motto �����������ϵĳ��֣�
*/
int UserLoginHandle(User user){
    User user_arr[USER_SIZE];
    int user_count = 0;
    int res = GetUserData(user_arr,&user_count);
    if(!res){
        PrintLog("��½����:�û���Ϣ�ṹ���ȡʧ��!");
        return 0;
    }
    for (int i = 0; i < user_count; ++i) {
        FilterStringLine(user_arr[i].password);
        if(strcmp(user_arr[i].username,user.username)==0 && strcmp(user_arr[i].password,user.password)==0){
            return 1;
        }
    }
    return 0;
}
int UserRegisterHandle(User user){
    PrintLog("����ע�����ҵ��...");

    FILE * user_file = fopen("../data/user.txt","a+");
    if(!user_file){
        PrintLog("�ļ���ʧ��");
        return 0;
    }
    //�˺��Ƿ����
    int result = isUserExit(user.username);
    if(result==-1){
        PrintLog("�ļ���ȡʧ��!");
        return 0;
    }
    if(result==0){
        PrintLog("�˺��Ѵ���!");
        return 0;
    }

    char user_info[STR_SIZE];
    sprintf(user_info,"%s %s\n",user.username,user.password);
//    puts(user_info);
    printf("Ҫע����û���ϢΪ: %s\n",user_info);
    if(fputs(user_info,user_file)==EOF){
        PrintLog("ע��ʱ�ļ�д��ʧ��");
    }

    fclose(user_file);

    return 1;
}
int isUserExit(char * username){
    User user_arr[USER_SIZE];
    int user_count = 0;
    int result = GetUserData(user_arr,&user_count);
//    printf("res = %d\n",result);
//    for (int i = 0; i < user_count; ++i) {
//        printf("username = %s\tpwd = %s",user_arr[i].username,user_arr[i].password);
//    }
    if(!result){
        return -1;
    }
    //ѭ���ṹ�������ж�
    for (int i = 0; i < user_count; ++i) {
        if(strcmp(user_arr[i].username,username)==0){
            return 0;
        }
    }
    return 1;
}
int GetUserData(User user_arr[],int * user_count){
    FILE * user_file = fopen("../data/user.txt","r");
    if(!user_file){
        PrintLog("��ȡ�û��б�:�ļ���ʧ��!");
        return 0;
    }
    char buff[STR_SIZE];
    char * read_line;
    int user_index = 0;
    int result_index = 1;
    while (1){
        read_line = fgets(buff,STR_SIZE,user_file);
        if(!read_line){
            if(ferror(user_file)){
                PrintLog("��ȡ�û��б�:�û���Ϣ�ļ���ȡʧ��");
                result_index = 0;
            }else if(feof(user_file)){
                PrintLog("��ȡ�û��б�:�û���Ϣ�ļ���ȡ���");
            } else{
                PrintLog("��ȡ�û��б�:�û���Ϣ�ļ���ȡʧ��");
                result_index = 0;
            }
            break;
        }
        if(read_line==EOF){
            result_index = 0;
            break;
        }

//        printf("====>%s\n",read_line);
        User user = GetUserInfo(read_line);
//        printf("====>%s\n",user.username);
//        printf("====>%s\n",user.password);
        user_arr[user_index] = user;
        user_index++;

    }
    *user_count = user_index;
    fclose(user_file);
    return result_index;
}
User GetUserInfo(char user_info[]){
    User temp_user = {};
    char * rs;
    rs = strtok(user_info," ");
    strcpy(temp_user.username,rs);
    rs = strtok(NULL," ");
    strcpy(temp_user.password,rs);

    return temp_user;
}