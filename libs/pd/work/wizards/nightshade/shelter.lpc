#include <std.h>
inherit OBJECT;

object interior;

void create() {
  ::create();

  set_name("shelter");
  set_short("a Sturdy Shelter");
  set_long("The shelter has been made out of some wood gathered in"
           " the woods and is held together by strands of sinew.");
  set_id(({"shelter","sturdy shelter"}));
  set_mass(200);
  set_prevent_get("You cannot carry an entire shelter.");
  set_value(0);
  interior = new("/d/standard/obj/misc/forage/shelterroom");
  interior->set_exits(([ "out" : base_name(environment(this_player())) ]));
  call_out("collapse", this_player()->query_skill("nature") + 40);
}

void init() {
  ::init();
  add_action("enter", "enter");
}

int enter(string str) {
  if(str != "shelter")
    return notify_fail("Enter what?\n");
  this_player()->move_player(interior, "into the shelter");
  return 1;
}

void collapse() {
  message("info","As the shelter begins to collapse, everyone moves outside.", interior);
  all_inventory(interior)->force_me("square");
  interior->remove();
  if(interior)
    destruct(interior);
  this_object()->remove();
}
