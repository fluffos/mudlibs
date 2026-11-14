// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/sys/shadow.h
// Description:	Defines fuer /i/shadow.c
// Author:	Freaky (1996)
//
// $Log: shadow.h,v $
// Revision 1.3  2003/01/26 03:52:06  gnomi
// SHADOWING_FORBIDDEN ist nun -2 statt 3 (da es eine Fehlermeldung ist.)
//
// Revision 1.2  2001/03/14 20:32:37  freaky
// CVS-log eingebaut.
//

#ifndef SHADOW_H
#define SHADOW_H 1

#define NO_MULTI_SHADOW		1
#define REPLACE_OLD_SHADOW	2

#define SHADOWING_FORBIDDEN    -2
#define SHADOW_ALREADY_EXISTS  -1
#define COULD_NOT_SHADOW	0
#define SHADOWING_OK		1
#define OLD_SHADOW_REPLACED	2

#endif // SHADOW_H
