#ifndef __WEAPON_HIT_H__

#define __WEAPON_HIT_H__

// Prototypes:

void set_hit_func(object ob);
string query_hit_msg();
int hit(object ob);
int hit2(object ob);

// End prototypes.


// Global variables:

string hit_msg;
object hit_func;

// End global variables.

#endif // __WEAPON__HIT_H__
