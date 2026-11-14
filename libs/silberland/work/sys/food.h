// SilberLand MUDlib
//
// sys/food.h -- standard food header
//
// $Date: 2005/10/19 10:51:43 $
/* $Revision: 1.7 $
 *
 * $Log: food.h,v $
 * Revision 1.7  2005/10/19 10:51:43  Woody
 * neu: QueryEatCommands()
 *
 * Revision 1.6  2004/09/05 13:33:05  Woody
 * F_BAKED von 3 auf 4, damit & Abfragen in std/food passen
 *
 * Revision 1.5  2004/01/12 17:48:23  Woody
 * P_FOOD_STATE_DESC, F_BAKED
 *
 * Revision 1.4  2003/12/30 23:34:40  Woody
 * neu: P_FOOD_STATE, F_MSG_DECAY, F_MSG_REMOVE, F_SHOW_RAW, F_RAW/...
 * sowie Prototypen fuer cook(), fry(), bake() und decay()
 *
 * Revision 1.3  2000/10/05 09:59:00  Woody
 * Prototypes umbenannt
 *
 * Revision 1.2  1998/09/29 21:23:56  Woody
 * BeimEssen() prototyp angepasst
 *
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

#define P_FOOD_INFO		"food_info"
#define P_FOOD_STATE		"food_state"
#define P_FOOD_STATE_DESC	"food_state_desc"

// special defines

#define F_HEAL          "heal"
#define F_SOAK          "soak"
#define F_DRINK         "drink"
#define F_ALCOHOL       "alcohol"
#define F_POISON        "poison"
#define F_MSG           "msg"
#define F_MSG_ROOM      "msg_room"
#define F_MSG_DECAY     "msg_decay"
#define F_MSG_REMOVE    "msg_remove"
#define F_VERB          "verb"
#define F_SHOW_RAW      "show_raw"

#define F_RAW           0x00
#define F_COOKED        0x01
#define F_FRIED         0x02
#define F_BAKED         0x04
#define F_SPOILT        0x80

#endif // __FOOD_H__

#ifdef NEED_PROTOTYPES

#ifndef __FOOD_H_PROTO__
#define __FOOD_H_PROTO__

// prototypes

varargs void Eating(object pl);
int second_life(object player);
varargs int eat(string what, object pl);
int cook(int silent);
int fry(int silent);
int bake(int silent);
int decay(int silent);
string *QueryEatCommands();

#endif // __FOOD_H_PROTO__

#endif // NEED_PROTOTYPES

