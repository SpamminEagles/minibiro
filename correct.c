#include"correct.h"

void RunFullCorrect(int testCases){
    int result = -1;
    int score = 0;

    printf("\n%-10s %30s\n", "Test case", "Results");
    printf("%s\n", GenString(41, '.'));

    for(int i = 0; i < testCases; i++){
        result = RunTestCase(i + 1);
        if (result == 0) score++;

        printf(
            "%-10s %30s",
            Concat(6, 2, "Case: ", IntToString(i + 1)),
            (result == 0 ? "Correct answer" : (result == -1 ? "Incorrect answer" : Concat(15, 2, "Runtime error: ", IntToString(result))))
        );
    }

    printf(Concat(64, 3,"\n", GenString(41, '-'), "\n"));
    printf("Subtotal: %d\n\n", score);
} 

int RunTestCase(int testcase){
    char* file = Concat(5, 3, "ex", IntToString(testcase), ".be");
    int ret;

    //Run the user's program
    rename(file, "be.txt");
    ret = RunProg();
    rename("be.txt", file);
    
    //Handling errors
    if(ret > 0) { return ret; }
    
    //Opening files
    FILE* resultsf = fopen("ki.txt", "r");
    FILE* patternf = fopen(Concat(5, 3, "ex", IntToString(testcase), ".ki") , "r");
    
    //Getting each of the files' length
    fseek(resultsf, 0, SEEK_END);
    fseek(patternf, 0, SEEK_END);
    int resultsLen = ftell(resultsf);
    int patternLen = ftell(patternf);
    rewind(resultsf);
    rewind(patternf);
    
    //Storing the data
    char* resultsc = malloc(sizeof(char) * (resultsLen + 1));
    char* patternc = malloc(sizeof(char) * (patternLen + 1));
    fread(resultsc, resultsLen, sizeof(char), resultsf);
    fread(patternc, patternLen, sizeof(char), patternf);

    //Closing streams
    fclose(resultsf);
    fclose(patternf);

    //Processing the data and returning with the results
    if (*RemWhitespace(resultsc) == *RemWhitespace(patternc)){
        return 0;
    }else{
        return -1;
    }

}