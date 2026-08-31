//    stone dispenser
 
#include <std.h>
inherit OBJECT;
 
void create() {
  ::create();

  set_name("Stone Stand");
  set_short("Stone Stand");
  set_long("The oil stand has a huge lever on it that says \"PULL ME\".");
  set_weight(10000);
  set_value(0);
  set_id(({"stand", "stone stand", "stone dispenser"}));
}

void init() {
  ::init();
  add_action("pull", "pull");
}

int pull(string str) {
  object ob;

  if(str != "lever")
    return 0;

  write("You pull the lever and a stone pops out!  You decide to take it.");
  ob = new("/std/obj/stone");
  ob->move(this_player());
  return 1;
}

