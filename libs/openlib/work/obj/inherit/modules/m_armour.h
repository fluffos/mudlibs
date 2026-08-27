#ifndef M_ARMOUR_H
#define M_ARMOUR_H

//
// You should inherit M_OBJECT_CLASS before this one to make sure the
// functions are defined properly
//
#include "m_object_class.h"

//
// Prototypes
// 
void initialize();         // make sure you call this in your routine
void set_type(string);
string query_type();
void set_worn(int wear, string wheere);
string query_worn();
int query_where_worn();
void set_ac(int ac__one,int ac__two);
int query_ac_one();
int query_ac_two();
int *query_ac();

#endif /* _M_ARMOUR_H */
