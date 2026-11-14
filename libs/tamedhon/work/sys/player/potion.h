// SilberLand MUDlib
//
// sys/player/potion.h -- player potion handler header
//
// $Date: 1997/03/31 15:12:28 $
/* $Revision: 1.4 $
 * $Log: potion.h,v $
 * Revision 1.4  1997/03/31 15:12:28  Woody
 * prepared for revision control
 *
 * Revision 1.3  1996/10/01  Woody
 * P_VISITED_POTIONROOMS und P_BONUS_POTIONS
 *
 */
 
#ifndef __PLAYER_POTION_H__
#define __PLAYER_POTION_H__

// properties

#define P_POTIONROOMS           "potionrooms"
#define P_VISITED_POTIONROOMS   "visited_potionrooms"
#define P_BONUS_POTIONS         "bonus_potions"
#define P_TRANK_FINDEN          "trank_finden"

#endif // __PLAYER_POTION_H__

#ifdef NEED_PROTOTYPES

#ifndef __PLAYER_POTION_H_PROTO__
#define __PLAYER_POTION_H_PROTO__ 

// prototypes

varargs int FindPotion(string s);

#endif // __PLAYER_POTION_H_PROTO__

#endif // NEED_PROTOYPES

