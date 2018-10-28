#pragma once

#include <stdlib.h>
#include <stdio.h>
#include "strlb.h"

#if defined(WIN32) || defined(WIN64)
//Windows specific libraries
#include "windef.h"
#elif  defined(__linux__)
//Linux specific libraries
#include "lnxdef.h"
#endif

void RunFullCorrect(int testCases);
int RunTestCase(int testcase);