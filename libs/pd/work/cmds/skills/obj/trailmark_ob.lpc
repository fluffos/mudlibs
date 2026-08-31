
#include <std.h>

#define TRAILMARK_PROP "trailmark_abil_info"

inherit OBJECT;

object owner;
int difficulty;
string name;
string long;

string long_desc();
string short_desc();

void create() {
  ::create();
  set_name("trailmark");
  set_id( ({ "mark in the trail", "mark", "trail mark", "trailmark" }) );
  set_long( (: long_desc :) );
  set_short( (: short_desc :) );
  set_prevent_get("Impossible.");
  set_weight(0);
  owner = 0;
  difficulty = 0;
  name = "none";
  long = "A mark in the trail";
}

void init() {
  ::init();
  if (this_player() == owner)
    add_action("clear_mark", "clear");
}

void set_owner(object tp) { owner = tp; }
void set_difficulty(int x) { difficulty = x; }
void set_name(string str) { name = str; }
void set_long_desc(string str) { long = str; }

int can_see(object tp) {
  if (tp == owner) return 1;
  if (tp->query_skill("nature")*4/3 >= difficulty) return 1;
  if (tp->query_skill("perception") >= difficulty) return 1;
  return 0;
}

string long_desc() {
  if (this_player() && this_player() == owner)
    return long+" ["+name+"]";
  return long;
}

string short_desc() {
  if (this_player() && !can_see(this_player()))
    return 0;
  return "a mark in the trail";
}

int id(string str) {
  if (this_player() && !can_see(this_player()))
    return 0;
  return ::id(str);
}

int clear_mark(string str) {
  object tp = this_player();
  mapping marks;

  if (!str || present(str, environment(tp)) != this_object())
    return notify_fail("Clear what?");

  marks = tp->query(TRAILMARK_PROP) || ([]);
  map_delete(marks, name);
  tp->set(TRAILMARK_PROP, marks);
  message("info", "You clear away the trail marking.", tp);
  remove();

  return 1;
}
