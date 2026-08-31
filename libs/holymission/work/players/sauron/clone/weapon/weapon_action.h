#ifndef __WEAPON_ACTION_H__

#define __WEAPON_ACTION_H__

// Prototypes:

void set_wield_func(object ob);
int wield(string str);
int un_wield();
int do_unwield(string what);
int query_wielded();
void init();

// End prototypes.


// Global variables:

string where_wielded;
int wielded;
object wielded_by,wield_func;

// End global variables.

#endif // __WEAPON_ACTION_H__
