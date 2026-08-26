// Petrarch
// Merentha Lib 1.0
// armour.c

#include <std.h>
#include "armour.h"

inherit OBJECT;

object __Worn;
string *__Limbs;
string __Type;
int __Ac;

void init() {
  ::init();
  add_action("wear", "wear");
  add_action("unwear", ({"remove","unwear"}));
}

string query_short() {
  return ::query_short()+(__Worn?" (worn)":"");
}

void set_type(string str) { __Type=str; }
string query_type() { return __Type; }

void set_ac(int i) { __Ac=i; }
int query_ac() { return __Ac; }

void set_limbs(string *str) { __Limbs=str; }
string *query_limbs() { return __Limbs; }

object query_worn_by() { return __Worn; }

int wear(string str) {
  if(str && !id(str)) return notify_fail("You can not wear that.\n");
  if(member_array(__Type,this_player()->query_worn_types())!=-1) return notify_fail("You are already wearing something of that type.\n");
  if(__Worn) return notify_fail("You are already wearing that.\n");
  this_player()->add_worn(this_object());
  message("action", "You wear "+query_short()+".", this_player());
  if(environment(this_player())) message("action", this_player()->query_cap_name()+" wears "+query_short()+".", environment(this_player()), this_player());
  __Worn=this_player();
  return 1;
}

varargs int unwear(string str) {
  if(str && !id(str)) return notify_fail("You are not wearing that.\n");
  if(!__Worn) return notify_fail("You are not wearing that.\n");
  __Worn->remove_worn(this_object());
  __Worn=0;
  message("action", "You remove "+query_short()+".", this_player());
  message("action", this_player()->query_cap_name()+" removes "+query_short()+".", environment(this_player()), this_player());
  return 1;
}

void remove() {
  unwear();
  ::remove();
} 

int is_armour() { return 1; }
