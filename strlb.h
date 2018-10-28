#pragma once

#define ZERO_ASCII 48

#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include "defines.h"

#define DIRECTION_FORWARD 1
#define DIRECTION_BACKWARD -1


char WHITESPACE[3];

int CountChar(char* array, char termin);
void ShrinkString(char* str);
int CountInt(int* array, int termin);
int Contains(char* container, char key);
char* RemWhitespace(char* input);
char* IntToString(int number);
char* Concat(int cllim, int argc, ...);
char* GenString(int pcs, char c);
int StartsWith(char* start, char* with, int direction);
int FindFirst(char* input, char c, int n);
int Count(char* array, char c);
char* ToLower(char* arr);
int Equals(char* stra, char* strb);
char* Strip(char* input, char rem);

//Math functions
int GetHighestDecimalPlace(int number);
int Tenpow(int pow);