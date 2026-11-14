// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/sys/tips.h
// Description: Include fuer alles, was mit den Spielertips zu tun hat
// Author:	Sissi (22.01.2000)
//
// $Log: tips.h,v $
// Revision 1.4  2001/03/14 20:32:37  freaky
// CVS-log eingebaut.
//

#ifndef TIPS_H
#define TIPS_H 1

#define TIPS_TOOL "/room/rathaus/obj/tips_tool" 
#define TIPS_FORMBLATT "/room/rathaus/obj/tips_formblatt" 

#define TIP_TEXT 0
#define TIP_AUTHOR 1
#define TIP_FOR 2
#define TIP_ACTIVE 3

#define MIN_TIME_BETWEEN_TIPS 7200
// man bekommt erst einen neuen Tip, wenn seit dem letzten Tip mindestens
// MIN_TIME_BETWEEN_TIPS Zeit verstrichen ist.

#endif // TIPS_H
