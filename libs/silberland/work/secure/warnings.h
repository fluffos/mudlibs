// SilberLand MUDlib
//
// secure/warnings.h - player warnings
//
// $Id: warnings.h,v 1.2 2003/05/16 12:48:28 Crea Exp $
/*
 * $Log: warnings.h,v $
 * Revision 1.2  2003/05/16 12:48:28  Crea
 * P_WARNINGS put in #ifdef clause
 *
 * Revision 1.1  2002/08/29 17:11:41  Crea
 * Initial revision
 *
 */
 
#ifndef __WARNINGS_H__
#define __WARNINGS_H__

// defines

#define WARNING_MASTER "/secure/warningmaster"

#define WARNING_SAVEFILE "/secure/ARCH/warnings"
#define WARNING_LOGFILE "/log/ARCH/warnings"
#define MAX_WARNING_LEVEL 50

// mapping warning  = ([ int id: ({ int lvl, string cause, string warned_by, int time }) ])

#define W_CAUSE 0
#define W_LEVEL 1
#define W_WARNED_BY 2
#define W_TIME 3

// return values

#define W_OK 1
#define W_NOSUCHPLAYER -1
#define W_NOSUCHID -2
#define W_IDNOTONPLAYER -3

// properties

#ifndef P_WARNINGS
#define P_WARNINGS "warnings"
#endif /* P_WARNINGS */

#endif // __WARNINGS_H__

#ifdef NEED_PROTOTYPES

#ifndef __WARNINGS_H_PROTO__
#define __WARNINGS_H_PROTO__

// prototypes
// no prototypes

#endif // __WARNINGS_H_PROTO__

#endif	// NEED_PROTOYPES
