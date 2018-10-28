#include "defines.h"
#include "data.h"
#define PropertyLen 7

typedef struct{
    char* key;
    char* value;
} dict_entry;

char* null_char = "NULL";
char* PropertiesList = NULL;

dict_entry Properties[PropertyLen] = {
    {.key = "mode", .value = "judje"},
    {.key = "source", .value = "run.c"},
    {.key = "lbinary", .value = "run"},
    {.key = "wbinary", .value = "run.exe"},
    {.key = "project", .value = "root"},
    {.key = "projectroot", . value = "bin"},

    {.key = "help", .value = "help"}
};

char** GetProperty(char* propertyname){
    if (Equals(propertyname, "properties")){
        int len = 2 + PropertyLen;

        for(int i = 0; i < PropertyLen; i++){
            len += CountChar(Properties[i].value, '\n');
        }

        PropertiesList = malloc(sizeof(char) * len);
        PropertiesList[0] = '\n';
        PropertiesList[len] = 0;

        for(int i = 0; i < PropertyLen; i++){
            for(int j = 0; (Properties[i]).value[j] != 0; j++){
                PropertiesList[i + j] = Properties[i].value[j];
            }

            PropertiesList[++i] = '\n';
        }
        
        return &PropertiesList;
    }

    for(int i = 0; i < PropertyLen; i++){
        if (Equals(Properties[i].key, propertyname)){
            char** ret = &(Properties[i].value);
            return ret;
        }
    }

    return &null_char;
}