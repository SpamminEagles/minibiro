#include "lnxdef.h"

int Compile(char* source){
    pid_t childID = fork();
    int ret = 0;

    if(childID < 0){
        printf("Error. Something occoured, while trying to run external application");
    }else if(childID > 0){
        int status = 0;
        waitpid(childID, &status, 0);
    }else{
        ret = execve(Concat(64, 4, "gcc -o ", RUN_NAME, " ", source), NULL, NULL);
        //_exit(0);
    }

    return ret;
}

int RunProg(){
    pid_t childID = fork();
    int ret = 0;

    if(childID < 0){
        printf("Error. Something occoured, while trying to run external application");
    }else if(childID > 0){
        int status = 0;
        waitpid(childID, &status, 0);
    }else{
        ret = execve(RUN_NAME, NULL, NULL);
        //_exit(0);
    }
    
    return ret;
}