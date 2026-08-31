// orb of darkness for dark spell
// recoded by Nulvect 2012-Feb-7

#include <std.h>

// not inheriting LIGHT here because our LIGHT object is a pile of crap
inherit OBJECT;

#define tp this_player()

object owner;
int max_dark;

varargs string query_long(int x);
int get();
int bury();
int cmd_shatter(string);
int cmd_release(string);
void update_dark();

void set_owner(object p) {
  owner = p;
  set_heart_beat(2);
}
void set_max_dark(int m) { max_dark = m; }

void create() {
  ::create();
  set_id( ({ "orb", "orb of darkness", "magical orb", "dark orb" }) );
  set_name("orb");
  set_short("an orb of darkness");
  set_weight(0);
  set_value(0);
  set_property("light", -1);
  set_property("no auction", 1);
  set_property("no store", 1);
}

void init() {
  ::init();
  add_action("cmd_shatter", "shatter");
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
    owner->remove_effect("dark");
    return;
  }

  o_env = environment(owner);
  if (env != owner && env != o_env) {
    move(o_env);
  }
  else {
    update_dark();
  }
}

varargs string query_long(int x) {
  if (tp && tp == owner) {
    return
    "This magical orb absorbs light from your surroundings.\n"
    "You can <release> it to darken the whole area, or you can "
    "<shatter> it to return the lighting to normal.";
  }
  return
  "This magical orb absorbs light from its owner's "
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
  message("info", tp->query_cap_name()+" releases an orb of darkness "
    "to float beside "+tp->query_objective()+".", environment(tp), tp);
  move(environment(tp));
  return 1;
}

// for bury, 1 means "don't allow" and 0 means "allow"
int bury() { 
  if (tp && owner && tp == owner) {
    tp->remove_effect("dark");
    return 1;
  }
  return 0;
}

int cmd_shatter(string str) {
  if (!str)
    return 0;
  if (present(str, tp) == this_object() ||
      present(str, environment(tp)) == this_object()) {
        tp->remove_effect("dark");
        return 1;
  }
  return 0;
}

int cmd_release(string str) {
  if (!str || present(str, tp) != this_object())
    return 0;
  message("info", "You release the orb to float beside you.", tp);
  message("info", tp->query_cap_name()+" releases an orb of darkness "
    "to float beside "+tp->query_objective()+".", environment(tp), tp);
  move(environment(tp));
  return 1;
}

void update_dark() {
  int ideal = -6;
  int min = -1;
  int current = query_property("light");
  int change;

  // remove the light from this orb first, to figure out what to change to
  remove_property("light");
  change = ideal - effective_light(owner);
  
  if (change > min)
    change = min;
  else if (change < max_dark)
    change = max_dark;
  
  /*
  if (change != current && environment()) {
    message("listen", "The orb of darkness hums quietly.",
      environment());
  }
  */

  set_property("light", change);
}

