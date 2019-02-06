//********************************************************
// File name:  mem_debug.h
// Author:     Chadd Williams
// Date:       7/5/2013, Edited 1/29/2019 by Chris Lane
// Class:      CS380
// Assignment: HW 2 Basic Sorting
// Purpose:    To provide easy access to heap debugging tools
// https://docs.microsoft.com/en-us/visualstudio/debugger/finding-memory-leaks-using-the-crt-library?view=vs-2017
//********************************************************


#ifdef MEM_DEBUG
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifdef _DEBUG
#ifndef DBG_NEW 
#define DBG_NEW new (_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DBG_NEW
#endif
#endif

// Be sure to include the following lines at the beginning of main()
// to enable heap debugging.
// these must be the FIRST lines in main(), even before variable
// declarations!
// #ifdef MEM_DEBUG
//	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
//	// _crtBreakAlloc = 131; // optionally break at a particular mem alloc.
// #endif

#endif