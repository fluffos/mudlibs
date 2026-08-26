// Petrarch
// Merentha Lib 1.0
// armour.h

#ifndef __ARMOUR_H__
#define __ARMOUR_H__

string query_short();
void set_type(string str);
string query_type();
void set_ac(int i);
int query_ac();
void set_limbs(string *str);
int query_limbs();
object query_worn_by();
int is_armour();

int wear(string str);
int unwear(string str);

#endif
