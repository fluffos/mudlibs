// SilberLand MUDlib
//
// sys/food.h -- standard food header
//
// $Date$
/* $Revision$
 * $Log$
 * 12.10.1995	16:00	Mupfel
 */
 
#ifndef __DRINK_H__
#define __DRINK_H__

// properties

#define P_DRINK_INFO	"drink_info"

// special defines

#define F_HEAL		0x01
#define F_SOAK		0x02
#define F_ALCOHOL	0x04
#define F_POISON	0x08

#endif // __FOOD_H__

#ifdef NEED_PROTOTYPES

#ifndef __DRINK_H_PROTO__
#define __DRINK_H_PROTO__

// prototypes

void BeimTrinken();
int mampf(string what);

#endif // __FOOD_H_PROTO__

#endif // NEED_PROTOTYPES

