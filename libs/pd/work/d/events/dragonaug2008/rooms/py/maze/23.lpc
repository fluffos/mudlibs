#include <std.h>
#include <dragonevent.h>
#include <rest.h>

inherit DRAG_ROOMS"py/icebase";

int opened;

void create() {
  ::create();
  set_exits( ([
    "north" : DRAG_ROOMS"py/maze/22",
  ]) );

//  add_fake_exits( ({ "east", "south", "west", "up", "down", "northeast", "northwest", "southeast", "southwest" }) );

  set_touch(({"ground","floor"}), "%^BOLD%^%^CYAN%^The entire ground here seems to be made out of pure ice. As you are bending over, you notice that a small amount of light seems to eminate from the ice.");
  set_search(({"ground", "floor"}), "it appears to be very sturdy, even though it is made of ice. As you are bending over, you notice that a small amount of light seems to eminate from the ice.");
}

void init() {
  ::init();
  add_action("use_stone_on_ground", ({"use","release"}) );
  add_action("break_ground_with_stone", ({"break", "smash", "destroy", "open", "melt"}) );
  add_action("stupid_break_ground", ({"breathe", "hug", "piss", "wiz", "urinate", "rub", "polish", "jump", "melt"}) );
  write("%^BOLD%^%^CYAN%^You slip and fall to the floor.");
  harm_player(this_player(), 20);
  this_player()->set_rest_type(LAY);
}

int stupid_break_ground(string str) {
  write("The ice covering the ground is much too sturdy for you to break through it in that manner.");
  return 1;
}

int use_stone_on_ground(string str) {
  object stone;
  string stoneName;
  if(!str) { return notify_fail(capitalize(query_verb())+" what?\n"); }
  if(str == "stone") { return notify_fail("You'll need a target.\n"); }
  if(sscanf(str, "%s on %s", stoneName, str) != 2) return 0;
  stone = present(stoneName, this_player());
  if(!stone) return notify_fail("What "+stoneName+"?\n");
  if(file_name(stone)[0..sizeof(DRAG_ITEMS"caveob")-1] != DRAG_ITEMS"caveob")
    return notify_fail(query_verb()+"ing a "+stoneName+" would do no good.\n");
  if(str != "floor" && str != "ground" && str != "ice")
    return notify_fail(query_verb()+"ing the stone on "+str+" would not help.\n");

  DRAG_D->set_data("cavestage:"+this_player()->query_name(), 6);
  write("%^YELLOW%^A bright light shoots forth from the stone, destroying the ice beneath you!");
  write("%^RED%^%^BOLD%^You begin to fall...");
  this_player()->move(DRAG_ROOMS"py/fall1");
  this_player()->set_rest_type(0);
  all_inventory(this_object())->move(environment(this_player()));
  return 1;
}

int break_ground_with_stone(string str) {
  string stoneName;
  if(str && sscanf(str, "%s with %s", str, stoneName) == 2);
  return use_stone_on_ground(stoneName+" on "+str);
}
