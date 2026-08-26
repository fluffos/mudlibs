// Petrarch
// Merentha Lib 1.0
// object.h

#ifndef __OBJECT_H__
#define __OBJECT_H__

void post_move();
void set_mass(int i);
int query_mass();
int query_total_mass();
void set_value(int i);
int query_value();
void set_prevent_get(string str);
string moveable();
int move(mixed dest);
void set_name(string str);
string query_name();
void set_cap_name(string str);
string query_cap_name(string str);
void set_short(string str);
string query_short();
void set_long(string str);
string query_long();
void set_id(string *arg);
string *query_id();
int id(string arg);
void set_properties(mapping props);
void set_property(string prop, mixed val);
void add_property(string prop, mixed val);
void remove_property(string prop);
mapping query_properties();
mixed query_property(string prop);

#endif
