#ifndef __WEAPON_GENERAL_H__

#define __WEAPON_GENERAL_H__

// Prototypes:

void set_info(string str);
string query_info();
void set_value(int v);
int query_value();
int get();
int drop();
void notify_destruct(object ob);
int query_weapon();
void reset(int flag);

// End prototypes.


// Global variables:

string info;
int value;

// End global variables.

#endif // __WEAPON_GENERAL_H__
