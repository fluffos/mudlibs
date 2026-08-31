/* Glowing orb cloned by the conjuring light spell.
   See /bin/user/_light.c for more info.
   By Valodin, Jan 15, 1993
   */

// recoded by Nulvect 2012-Feb-7

#include <std.h>

// not inheriting LIGHT here because our LIGHT object is a pile of crap
inherit OBJECT;

#define tp this_player()

object owner;
int max_light;

varargs string query_long(int x);
int get();
int bury();
int cmd_extinguish(string);
int cmd_release(string);
void update_light();

void set_owner(object p) {
  owner = p;
  set_heart_beat(2);
}
void set_max_light(int m) { max_light = m; }

void create() {
  ::create();
  set_id( ({ "orb", "glowing orb", "magical orb", "light orb" }) );
  set_name("orb");
  set_short("a glowing orb");
  set_weight(0);
  set_value(0);
  set_property("light", 1);
  set_property("no auction", 1);
  set_property("no store", 1);
}

void init() {
  ::init();
  add_action("cmd_extinguish", "extinguish");
  add_action("cmd_release", "release");
}

void heart_beat() {
  object env = environment();
  object o_env;

  if (!owner) {
    remove();
    return;
  }

  if (!env) {
    owner->remove_effect("light");
    return;
  }

  o_env = environment(owner);
  if (env != owner && env != o_env) {
    move(o_env);
  }
  else {
    update_light();
  }
}

varargs string query_long(int x) {
  if (tp && tp == owner) {
    return
    "This magical orb glows softly, tuning itself to your surroundings.\n"
    "You can <release> it to light the area for others, or you can "
    "<extinguish> it when it's no longer needed.";
  }
  return
  "This magical orb glows softly, tuning itself to its owner's "
  "surroundings.";
}

// for get, 1 means "allow" and 0 means "don't allow"
int get() {
  if (tp) {
    if (owner && tp == owner) {
      return 1;
    }
    message("info", "The orb is insubstantial.", tp);
    return 0;
  }
  return 0;
}

// for drop, 1 means "don't allow" and 0 means "allow"
int drop() {
  message("info", "You release the orb to float beside you.", tp);
  message("info", tp->query_cap_name()+" releases a glowing orb to float "
    "beside "+tp->query_objective()+".", environment(tp), tp);
  move(environment(tp));
  return 1;
}

// for bury, 1 means "don't allow" and 0 means "allow"
int bury() { 
  if (tp && owner && tp == owner) {
    tp->remove_effect("light");
    return 1;
  }
  return 0;
}

int cmd_extinguish(string str) {
  if (!str)
    return 0;
  if (present(str, tp) == this_object() ||
      present(str, environment(tp)) == this_object()) {
        tp->remove_effect("light");
        return 1;
  }
  return 0;
}

int cmd_release(string str) {
  if (!str || present(str, tp) != this_object())
    return 0;
  message("info", "You release the orb to float beside you.", tp);
  message("info", tp->query_cap_name()+" releases a glowing orb to float "
    "beside "+tp->query_objective()+".", environment(tp), tp);
  move(environment(tp));
  return 1;
}

void update_light() {
  int ideal = 1;
  int min = 0;
  int current = query_property("light");
  int change;

  // remove the light from this orb first, to figure out what to change to
  remove_property("light");
  change = ideal - effective_light(owner);
  
  if (change < min)
    change = min;
  else if (change > max_light)
    change = max_light;
  
  if (change != current && environment()) {
    message("magic", "The glowing orb adjusts its brightness.",
      environment());
  }

  set_property("light", change);
}

