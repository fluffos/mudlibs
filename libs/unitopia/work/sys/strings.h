// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/sys/strings.h
// Description:	Defines fuer trim()
// Author:	Driver (27.06.1999)
//
// $Log: strings.h,v $
// Revision 1.3  2001/08/23 09:21:54  freaky
// angepasst an ldmud-3.2.9dev323
//
// Revision 1.2  2001/03/14 20:32:37  freaky
// CVS-log eingebaut.
//

#ifndef LPC_STRINGS_H_
#define LPC_STRINGS_H_ 1

/* 'where' argument values for trim() */

#define TRIM_LEFT  0x01
#define TRIM_RIGHT 0x02
#define TRIM_BOTH  (TRIM_LEFT|TRIM_RIGHT)

#endif /* LPC_STRINGS_H_ */
