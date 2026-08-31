//    oil dispenser
 
#include <std.h>
inherit OBJECT;
 
void create() {
  ::create();

  set_name("Oil Stand");
  set_short("Oil Stand");
  set_long("The oil stand has a huge button on it that says \"PUSH ME\".");
  set_weight(10000);
  set_value(0);
  set_id(({"stand", "oil stand", "oil dispenser"}));
}

void init() {
  ::init();
  add_action("push", "push");
}

int push(string str) {
  object ob;

  if(str != "button")
    return 0;

  write("You push the button and an oil pops out!  You decide to take it.");
  ob = new("/std/obj/oil");
  ob->set_uses(15);
  ob->move(this_player());
  return 1;
}

