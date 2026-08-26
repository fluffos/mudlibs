// Petrarch
// Merentha Lib 1.0
// weapon.c

#include <std.h>
#include "weapon.h"

inherit OBJECT;

object __Wielded;
string __Type;
int __Hands, __Wc;

void init() {
  ::init();
  add_action("wield", "wield");
  add_action("unwield", "unwield");
  __Hands=1;
}

string query_short() {
  return ::query_short()+(__Wielded?" (wielded)":"");
}

void set_type(string str) { __Type=str; }
string query_type() { return __Type; }

void set_wc(int i) { __Wc=i; }
int query_wc() { return __Wc; }

void set_hands(int i) { __Hands=i; }
int query_hands() { return __Hands; }

object query_wielded_by() { return __Wielded; }

int wield(string str) {
  if(str && !id(str)) return notify_fail("You can not wield that.\n");
  if(sizeof(this_player()->query_wielding())>1) return notify_fail("Your hands are full.\n");
  if(__Wielded) return notify_fail("You are already wielding that.\n");
  this_player()->add_wielding(this_object());
  if(__Hands==2) this_player()->add_wielding(this_object());
  message("action", "You wield "+query_short()+".", this_player());
  if(environment(this_player())) message("action", this_player()->query_cap_name()+" wields "+query_short()+".", environment(this_player()), this_player());
  __Wielded=this_player();
  return 1;
}

varargs int unwield(string str) {
  if(str && !id(str)) return notify_fail("You are not wielding that.\n");
  if(!__Wielded) return notify_fail("You are not wielding that.\n");
  __Wielded->remove_wielding(this_object());
  __Wielded=0;
  message("action", "You unwield "+query_short()+".", this_player());
  message("action", this_player()->query_cap_name()+" unwields "+query_short()+".", environment(this_player()), this_player());
  return 1;
}

void remove() {
  unwield();
  ::remove();
} 

int is_weapon() { return 1; }
