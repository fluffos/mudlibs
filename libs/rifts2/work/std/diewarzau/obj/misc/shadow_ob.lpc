//    Shadow form object.c
#include <rooms.h>

inherit "/std/Object";

int drop() { return 1; }

void create() {
  ::create();
  set_short(0);
  set_long(0);
  return;
}

void init() {
  string *exits;
  int i;
  
  ::init();
  if(this_player() != environment()) return;
  add_action("sorry", "get");
  add_action("sorry", "take");
  add_action("sorry", "kill");
  add_action("sorry", "use");
  add_action("sorry", "cast");
  exits = (string *)this_player()->query("exits");
  i = sizeof(exits);
  while(i--) {
    add_action("pass_that_door", exits[i]);
  }
  return;
}

void reset_exits() {
  object prev;

  prev = environment();
  this_object()->move(ROOM_VOID);
  this_object()->move(prev);
  return;
}

int sorry(string null) {
  write("You are unable to do that in your immaterial state.");
  return 1;
}

int pass_that_door(string null) {
  string verb, door;
  object prev;
  
  verb = query_verb();
  door = environment(this_player())->query_door(verb);
  if(!environment(this_player()) || (door && !environment(this_player())->query_open(door))) return 0;
  this_player()->move_player((string)environment(this_player())->query_exit(verb), "min");
  return 1;
}

