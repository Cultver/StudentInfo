#include <stdio.h>
#include "Config.h"
/**
* untitled1
* @autor WH
* @data 2022~07~13~20:26
* @motto 不满足是向上的车轮！
*/
void PrintLog(char * message){
#ifdef DEBUG
    puts(message);
#endif

}