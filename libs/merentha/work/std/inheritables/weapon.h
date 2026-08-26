// Petrarch
// Merentha Lib 1.0
// weapon.h

#ifndef __WEAPON_H__
#define __WEAPON_H__

string query_short();
void set_type(string str);
string query_type();
void set_wc(int i);
int query_wc();
void set_hands(int i);
int query_hands();
object query_wielded_by();

int wield(string str);
int unwield(string str);

int is_weapon();

#endif
