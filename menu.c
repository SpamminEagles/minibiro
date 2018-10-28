#include "menu.h"

void RunMenu(){
    putchar('\n');
    char input[128];

    while(1){
        printf("\nminibiro~(ಠ_ಠ)~$> ");
        fgets(input, sizeof(input), stdin);
        Parser(input);

        if(Process(input)){
            break;
        }
    }
}

void Parser(char* dirtyInput){
    char* cleanInput = malloc(sizeof(dirtyInput));
    int ignore = 0;
    int commands = 0;

    //printf("%s", dirtyInput);

    for(int i = 0, j = 0;;i++){
        if(dirtyInput[i] == 0){
            cleanInput[j] = 0;
            break;
        }

        if(' ' == dirtyInput[i] && !ignore){
            ignore = 1;
            if (commands == 3){
                cleanInput[j] = 0;
                break;
            }
            cleanInput[j] = ' ';
            j++;
            commands++;
            continue;
        }
        else{
            cleanInput[j] = dirtyInput[i];
            j++;
            ignore = 0;
        }
    }

    dirtyInput = cleanInput;
    ShrinkString(dirtyInput);
}

int Process(char* input){
    int elements = Count(input, ' ') + 1;
    

    for (int i = 1; i < elements + 1; i++){
        //printf("%s\n%d", ToLower(SubStrA(input, ' ', i)), ToLower(SubStrA(input, ' ', i)) == "get");

        if (Equals(SubStrA(input, ' ', i), "&&") || Equals(SubStrA(input, ' ', i), "||")){
            continue;
        }

        //Get the command:
        if(Equals(ToLower(SubStrA(input, ' ', i)), "get")){
            if(i + 1 > elements){
                printf("Not enough arguments for get!\n");
                return 0;
            }

            Get(SubStrA(input, ' ', i + 1));
            i++;
            continue;
        }

        if(Equals(ToLower(SubStrA(input, ' ', i)), "set")){
            if(i + 2 > elements){
                printf("Not enough arguments for set!\n");
                return 0;
            }

            Set(SubStrA(input, ' ', i + 1), SubStrA(input, ' ', i + 2));
            i += 2;
            continue;
        }

        int result = Macro(SubStrA(input, ' ', i));
        if(result == 2){
            printf("Error! Macro not found!\n");
        }
        else if(result == 1){
            return 1;
        }
        else{
            printf("Macro (%s) conducted succesfully!\n", Strip(SubStrA(input, ' ', i), '\n'));
        }
    }

    return 0;
}

void Set(char* property, char* value){
    value = Strip(value, '\n');

    char** p = GetProperty(property);
    *p = value;
    printf("Poperty set..\n");
}

void Get(char* property){
    printf("Property <%s> is \"%s\" \n", Strip(property, '\n'), *GetProperty(property));
}

int Macro(char* command){
    if(Equals(command, "exit")){
        return 1;
    }
    else if(Equals(command, "test")){
        return 0;
    }
    else{
        return 2;
    }

}