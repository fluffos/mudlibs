// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/sys/browser.h
// Description:	Definitionen fuer /i/tools/browser.c
// Author:	Freaky (11.07.95)
//
// $Log: browser.h,v $
// Revision 1.4  2001/03/14 20:32:37  freaky
// CVS-log eingebaut.
//

#ifndef BROWSER_H
#define BROWSER_H 1

#define B_INITIAL 1
#define B_BACK    2
#define B_NEXT    3
#define B_PREV    4
#define B_MENUE   5

#define BR_MENUE	0
#define BR_STATUS_LINE	1
#define BR_BEGIN_LINE	2
#define BR_STATUS_BYTE	3
#define BR_PATH		4
#define BR_USER		5
#define BR_NUMBERS      6

#define BR_SIZE         7

// Die Flags
#define MORE_MASK	0xffff

#define BF_NO_MENUE	0x10000 // Das ist kein Menue  

#define END_BROWSE	1
#define BREAK_BROWSE	4

#endif // BROWSER_H
