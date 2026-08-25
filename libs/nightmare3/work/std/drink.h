#ifndef __DRINK_H
#define __DRINK_H

int cmd_drink(string str);
varargs void set_drink(mixed val, string str);
function query_drink_function();
string query_my_msg();
string query_other_msg();
void set_strength(int x);
int query_strength();
void set_type(string str);
string query_type();
void set_empty_name(string str);
string query_empty_name();

#endif /* __DRINK_H */
