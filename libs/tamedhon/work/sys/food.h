// SilberLand MUDlib
//
// sys/food.h -- standard food header
//
// $Date: 1997/10/07 11:50:15 $
/* $Revision: 1.1 $
 *
 * $Log: food.h,v $
 * Revision 1.1  1997/10/07 11:50:15  Woody
 * Initial revision
 *
 *
 * 12.10.1995	16:00	Mupfel
 *
 */
 
#ifndef __FOOD_H__
#define __FOOD_H__

// properties

#define P_FOOD_INFO	"food_info"

// special defines

#define F_HEAL          "heal"
#define F_SOAK          "soak"
#define F_DRINK         "drink"
#define F_ALCOHOL       "alcohol"
#define F_POISON        "poison"
#define F_MSG           "plmsg"
#define F_MSG_ROOM      "rmmsg"
#define F_VERB          "verb"

#endif // __FOOD_H__

#ifdef NEED_PROTOTYPES

#ifndef __FOOD_H_PROTO__
#define __FOOD_H_PROTO__

// prototypes

void BeimEssen();
int second_life(object player);
int mampf(string what);

#endif // __FOOD_H_PROTO__

#endif // NEED_PROTOTYPES

