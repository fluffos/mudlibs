
#include <std.h>
#include <saahr.h>

inherit ROOM;

int fall_down();

void create() {
  ::create();
  set_properties((["light" : 1, "indoors" : 0]));
  set_short("a bridge over the river");
  set_long("This bridge is small and rickety. It is made of wooden planks held "
    "together by some tough but frazzled rope. The bridge sways gently in the wind. "
    "Some trees can be seen to the east, while a plain stretches out westward.");
  set_items(([
    "bridge" : "An old wooden bridge that spans the river.",
    "planks" : "They're very worn out and don't exactly instill you with confidence.",
    "rope" : "The rope holds the planks together and also forms handholds on either side.",
    ({"trees","east"}) : "A forest is just on the eastern side of the river.",
    ({"plain","west","westward"}) : "Sunburnt plains fill the western side of the river."
  ]));
  set_listen("default","The sound of the river mixes with the creaking of the bridge.");
  set_exits(([
    "west" : VPROOMS "p5_5",
    "east" : VPROOMS "f7_5"
  ]));
  add_pre_exit_function("east", "fall_down");
  add_pre_exit_function("west", "fall_down");
}

int fall_down() {
  object tp=this_player();
  message("info","%^BOLD%^%^WHITE%^You step on a plank and it breaks!\n"
    "You fall through the bridge!%^RESET%^", tp);
  message("info","%^BOLD%^%^WHITE%^A plank breaks beneath "+
    tp->query_cap_name()+" and "+tp->query_subjective()+
    " falls through the bridge!%^RESET%^",
    environment(tp), tp);
  message("info", "%^BOLD%^%^WHITE%^"+tp->query_cap_name()+" falls into "
    "the water from above!%^RESET%^", load_object(VPROOMS"river6_5") );
  tp->move(VPROOMS"river6_5");
  tp->describe_current_room(1);
  return 0;
}

