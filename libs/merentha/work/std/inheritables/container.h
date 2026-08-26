// Petrarch
// Merentha Lib 1.0
// container.h

#ifndef __CONTAINER_H__
#define __CONTAINER_H__

void set_max_mass (int i);
int query_max_mass ();
void set_max_items (int i);
int query_max_items ();
int query_holding_mass();
string get_living_contents();
string get_nonliving_contents();
int is_container();

#endif
