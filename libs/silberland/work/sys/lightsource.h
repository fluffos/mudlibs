// SilberLand MUDlib
//
// sys/lightsource.h -- lightsource header
//
// $Date: 2007/01/22 18:19:38 $
/* $Revision: 1.1 $
 * $Log: lightsource.h,v $
 * Revision 1.1  2007/01/22 18:19:38  Woody
 * Initial revision
 *
 */
 
#ifndef __LIGHTSOURCE_H__
#define __LIGHTSOURCE_H__

// properties

#define P_FUEL          "fuel"
#define P_MAX_FUEL      "max_fuel"
#define P_LIGHTDESC     "lightdesc"
#define P_DO_DESTRUCT   "do_destruct"
#define P_LIGHTED       "lighted"

#endif // __LIGHTSOURCE_H__

#ifdef NEED_PROTOTYPES

#ifndef __LIGHTSOURCE_H_PROTO__
#define __LIGHTSOURCE_H_PROTO__

// prototypes

int AddFuel(int fuel);

#endif // __LIGHTSOURCE_H_PROTO__

#endif	// NEED_PROTOYPES

