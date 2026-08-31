#include <std.h>

#define FIREPLANE "/cmds/skills/obj/corona_fireplane"

inherit OBJECT;

string dest;
int times;

varargs void setup(int t, string d) {
 times = t;
 dest = d;
}

void create() {
  ::create();
  set_id( ({"corona"}) );
  set_name("corona");
  set_short("A flaming corona");
  set_long("A well defined ring of flames sets off the entryway. "
           "Inside is nothing but bright orange and yellow fire "
           "that gives off an intense scorching heat. It looks "
           "dangerous and maybe even deadly.");
}

int rmPortal() {
  if (this_object() && sizeof(dest)) {
    message("info","%^YELLOW%^The corona surges with flame and vanishes.%^RESET%^\n", environment(this_object()));
    this_object()->remove();
    if (this_object()) destruct(this_object());
  }
  return 1;
}

int init() {
  ::init();
  add_action("enter", "enter");
  call_out("rmPortal", 10);
}

int enter(string str) {
  object where;
  if (!str || present(str,environment(this_player())) != this_object())
    return notify_fail("Enter what?\n");

  if (!dest)
    return notify_fail("You cannot enter the corona.\n");

  if (!(where=clone_object(FIREPLANE)))
    return notify_fail("An error occurred, please tell an immortal.\n");
 
  where->setup(times, dest);
  write("You enter the flaming corona and find yourself surrounded by fire.");
  this_player()->move_player(where, "into the flames");
  return 1;
}

int get() { return 0; }

