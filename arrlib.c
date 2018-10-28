#include "arrlib.h"


//A trim array function. Something Python does out of the box...
char* TrimCharArray(char* array, int from, int to, int increments){
    int len = (to - from) / increments + 1;
    char* new = malloc(sizeof(char) * len);

    for(int i = from, j = 0; i <= to; i += increments, j++){
        new[j] = array[i];
    }
    new[len] = 0;
    return new;
}

//Returns element n form the string as a substring, separated by the
//user defined separating character
char* SubStrA(char* input, char separator, int index){
    int start;
    int end;

    if (--index <= 0){
        start = -1;
        end = FindFirst(input, separator, 1);
    }else{
        start = FindFirst(input, separator, index);
        end = FindFirst(input, separator, index + 1);
    }

    if (end == -1){
        end = CountChar(input, 0);
    }

    int len = end - start;
    char* ret = malloc(sizeof(char) * len);
    
    ret = TrimCharArray(input, start +1, end -1, 1);
    ret[len] = 0;

    return ret;
}