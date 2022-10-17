
/**
* untitled1
* @autor WH
* @data 2022~07~13~16:45
* @motto 不满足是向上的车轮！
*/
#include <string.h>

//过滤字符串换行符
void FilterStringLine(char str[]){
    char * temp = NULL;
    if(temp = strstr(str,"\n")){
        *temp = '\0';
    }
}