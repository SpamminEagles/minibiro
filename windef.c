#include "windef.h"

int RunProg(){
    
    int result = 0;
    result = ShellExecute(NULL, "open", Concat(16, 2, RUN_NAME, RUN_EXTENSION), "", NULL, SW_HIDE);

    return result;
}