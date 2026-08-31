#ifndef __WEAPON_NAME_H__

#define __WEAPON_NAME_H__

// Prototypes:

void set_id(string str);
int id(string str);
void set_name(string str);
string query_name();
void set_alt_name(string str);
string query_alt_name();
void set_alias(string str);
string query_alias();
void set_short(string str);
string short();
void set_long(string str);
void long();

// End prototypes.


// Global variables:

string name_of_weapon;
string alt_name;
string alias_name;
string short_desc;
string long_desc;

// End global variables.

#endif // __WEAPON_NAME_H__
