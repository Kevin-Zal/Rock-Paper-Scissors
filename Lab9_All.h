// Lab9_All.h
// Stores the #includes used throughout the program.  Also stores the master switch for Linux compatibility.
#define _LINUX_ 0
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#if _LINUX_
#else   // Must be Windows
#include <conio.h>
#endif  // _LINUX_

#include "Lab9_Definitions.h"
