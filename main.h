#pragma once

#if defined(WIN32) || defined(WIN64)
//Windows specific libraries
#include "windef.h"
#elif  defined(__linux__)
//Linux specific libraries
#include "lnxdef.h"
#endif

//Cross platform libraries, and standard c libraries for the main program
#include "strlb.h"
#include "correct.h"
#include "menu.h"

#include <stdio.h>
#include <stdlib.h>