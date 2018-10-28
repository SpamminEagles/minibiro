#include"strlb.h"


char WHITESPACE[3] = {3, 9, 32};

//The first element defines the length of the useful characters + 1!

//Calculates how long the useful data of an array is (with defineable terminating character)
int CountChar(char* array, char termin){
    int counter = 0;
    for(int i = 0; array[i] != termin && array[i] != 0; i++){ counter++; }
    return counter;
}

int Count(char* array, char c){
    int ret = 0;
    int len = CountChar(array, '\n');

    for (int i = 0; i < len; i++){
        if (array[i] == c){
            ret++;
        }
    }
    return ret;
}

//Int version of CountChar()
int CountInt(int* array, int termin){
    int counter = 0;
    for(int i = 0; i != termin; i++){ counter++; }
    return counter + 1;
}

//Decides wether an array contains a key (char)
int Contains(char* container, char key){
    for(int i = 1; i < container[0]; i++){
        if (container[i] == key) { return 1; }          //True
    }

    return 0;                                           //False
}

//Shrinks string to its useful length
void ShrinkString(char* str){
    int len = CountChar(str, 0);
    char* new = malloc(sizeof(char) * (len + 1));
    
    for(int i = 0; str[i] != 0; i++){
        new[i] = str[i];
    }

    new[len] = 0;
    str = new;
}

//This function will remove white space from a string
char* RemWhitespace(char* input){
    char* new = malloc(sizeof(input));

    for(int i = 0, j = 0; ; i++){
        if (!Contains(WHITESPACE, input[i])){
            new[j] = input[i];
            j++;
        }

        if (input[i] == 0){
            new[j] = 0;
            break;
        }
    }
    return new;
}

int GetHighestDecimalPlace(int number){
    for(int i = 0; ;i++){
        if (number < 10){
            return i;
        }
        number /= 10;
    }
}

int Tenpow(int param){

    if (param == 0){return 1;}
    if (param == 1){return 10;}
    
    return 10 * Tenpow(param - 1);
}

char* IntToString(int number){
    int HighestDecimal = GetHighestDecimalPlace(number);
    char* ret = malloc(sizeof(char) * (HighestDecimal + 2));

    ret[HighestDecimal + 1] = 0;

    for(int i = 0; HighestDecimal > -1; HighestDecimal--, i++){
        ret[i] = ZERO_ASCII + (number / Tenpow(HighestDecimal));
        number -= (number / Tenpow(HighestDecimal) * Tenpow(HighestDecimal));
    }

    return ret;
}

//This function concatonates a maximum of n characters
char* Concat(int cllim, int argc, ...){
    int cursor = 0;
    char* new = malloc(sizeof(char) * (cllim * argc + 1));

    va_list lst;
    va_start(lst, argc);

    for(int i = 0; i < argc; i++){
        char* mych = va_arg(lst, char*);
        
        for(int j = 0; mych[j] !=0 && j < cllim ; cursor++, j++){
            new[cursor] = mych[j];
        }
    }

    va_end(lst);

    new[++cursor] = 0;

    ShrinkString(new);
    return new;
}

//Returns n pcs of c
char* GenString(int pcs, char c){
    char* ret = malloc(sizeof(char) * pcs);
    
    for(int i = 0; i < pcs; i++){
        ret[i] = c;
    }

    return ret;
}

///Not tested!
int StartsWith(char* start, char* with, int direction){
    int i = 0;

    if(direction < 0){
        i = CountChar(start, 0);
    }if (direction == 0){
        direction = 1;
    }

    for(int j;; i += direction, j++){
        if (with[j] == 0){
            return 1;
        }
        if (start[i] == 0){
            return 0;
        }

        if (start[i] != with[j]){
            return 0;
        }
    }
}

//Finds the first nth occourance of c in input
int FindFirst(char* input, char c, int n){
    for(int i = 0; input[i] != 0; i++){
        if(input[i] == c){
            if(n < 2){
                return i;
            }else{
                n--;
            }
        }
    }

    return -1;
}

char* ToLower(char* arr){
    for(int i = 0; arr[i]; i++){
        if(arr[i] > 'A' && arr[i] <= 'Z'){
            arr[i] += ('a' - 'A');
        }
    }

    return arr;
}

int Equals(char* stra, char* strb){
    //Length of each char
    int l1 = CountChar(stra, '\n');
    int l2 = CountChar(strb, '\n');

    //printf("%s %d, %s %d\n", stra, l1, strb, l2);
    //If they are no same length, they cannot match
    if (l1 != l2){
        
        return 0;
    }

    //If we find a character that does not match, the strings do not match
    for(int i = 0; i < l1; i++){
        if (stra[i] != strb[i]){
            return 0;
        }
    }

    //If all above was false, we know the strings must match!
    return 1;
}

char* Strip(char* input, char rem){
    int pcs = Count(input, rem);
    int len = CountChar(input, 0);
    char* ret = malloc(sizeof(char) * (len - pcs + 1));

    for(int i = 0, j = 0; i < len; i++){
        if(input[i] != rem){
            ret[j] = input[i];
            j++;
        }
    }

    ret[len-pcs] = 0;
    return ret;
}