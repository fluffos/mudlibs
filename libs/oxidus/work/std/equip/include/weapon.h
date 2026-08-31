#ifndef __WEAPON_H__
#define __WEAPON_H__

void set_hands(int i) ;
int query_hands() ;
mixed can_equip(string slot, object tp) ;
mixed equip(string slot, object tp) ;
mixed can_unequip(object tp) ;
varargs int unequip(object tp, int silent) ;
void unsetup() ;
int is_weapon() ;
void set_slot(string str) ;
string query_slot() ;

#endif // __WEAPON_H__
