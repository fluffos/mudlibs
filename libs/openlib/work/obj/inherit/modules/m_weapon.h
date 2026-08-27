// m_weapon.h:  Functions for weapons
// Tim 23 Apr 96  (module created from old weapon.c)
#ifndef _M_WEAPON_MOD_H
#define _M_WEAPON_MOD_H

//
// You should inherit M_OBJECT_CLASS before this one to make sure the
// functions are properly defined.
//
#include "m_object_class.h"

//
// Prototypes
//
void initialize();               // make sure you call this in your routine
void set_wield_info(mixed*);
mixed *query_wield_info();
void set_hands(int);
void set_wielded(int);
void set_weapon_info(mixed);
int query_wielded();
mixed *query_weapon_info();
int query_hands();

#endif /* _M_WEAPON_MOD_H */
