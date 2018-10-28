#pragma once

#include <stdlib.h>
#include <stdio.h>
#include "strlb.h"

char* TrimCharArray(char* array, int from, int to, int increments);
char* SubStrA(char* input, char separator, int index);