#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("Climbing golden steps");
   set_properties((["light" : 2]));
   set_properties((["town" : 1, "indoors" : 1, "building" : 1]));
   set_long("The steps of the staircase here have been made in marble "
      "with a golden lining. The carpet over the steps is magenta. The "
      "tower walls are black marble. The tower goes straight up, almost "
      "as far as you can see.");
   set_exits(([ "up" : ROOMS"ntower3",
                "down" : ROOMS"ntower1"]));
   set_items(([
      "steps" : "They are marble and lined with gold.",
      "carpet" : "It is a king's red.",
      "gold" : "The gold looks new.",
      "tower" : "As high as you can see.",
      "walls" : "They are a black marble."
   ]));
}

void reset() {
 ::reset();
   if (!present("paladin")) {
     make(MOB"paladin");
     make(MOB"paladin");
   }
   if (!present("squire"))
     make(MOB"squire");
}
int slide(string str) {
   if (!str) return 0;
   if (str != "rail" && str != "on rail") return notify_fail(
     "Slide on what?\n");
   write("You cannot resist the urge!! WHEEEeeeeeeeeeeeee!!!....");
   this_player()->move_player(ROOMS"ntower1", "sliding down the rail");
   return 1;
}
void init() {
 ::init();
   add_action("slide", "slide");
}
