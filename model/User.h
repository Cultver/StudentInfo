
/**
* untitled1
* @autor WH
* @data 2022~07~08~17:12
* @motto 不满足是向上的车轮！
*/

#ifndef UNTITLED1_USER_H
#define UNTITLED1_USER_H
typedef enum {
    LOGIN = 1,
    REGISTER = 2,
    GOTO_STU_SYS = 3,
    EXIT = 4
}ACTION;
typedef struct {
    char username[30];
    char password[30];
}User;
#endif //UNTITLED1_USER_H
