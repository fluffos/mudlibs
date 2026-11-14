// SilberLand MUDlib
//
// sys/timevars.h -- timed variables handler
//
// $Date: 1997/03/31 13:44:17 $
/* $Revision: 1.1 $
 * $Log: timevars.h,v $
 * Revision 1.1  1997/03/31 13:44:17  Woody
 * prepared for revision control
 *
 * 21.02.1996	22:50	Mupfel
 *
 */
 
#ifndef __TIMEVARS_H__
#define __TIMEVARS_H__

// no properties

// no special defines

#endif // __TIMEVARS_H__

#ifdef NEED_PROTOTYPES

#ifndef __TIMEVARS_H_PROTO__
#define __TIMEVARS_H_PROTO__

// prototypes

void AddTimeVar(string name, int duration);
int ReadTimeVar(string name);

#endif // __TIMEVARS_H_PROTO__

#endif // NEED_PROTOTYPES
