#pragma once


#include <stdlib.h>
#include <stdio.h>
#include "strlb.h"
#include "arrlib.h"
#include "data.h"

void RunMenu();
void Parser(char* dirtyInput);
int Process(char* input);
void Set(char* option, char* value);
void Get(char* option);
int Macro(char* command);
