#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("Climbing the steps further up the tower");
   set_properties((["light" : 2]));
   set_properties((["town" : 1, "indoors" : 1, "building" : 1]));
   set_long("The red-carpeted, gold lined stairs lead up, along with "
      "the slight curve of the tower. A gleaming silver rail leads "
      "along side of the stairs.");
   set_exits(([ "up" : ROOMS"ntower6",
                "down" : ROOMS"ntower4"]));
   set_items(([
      "stairs" : "They are carpeted and lined in gold.",
      "carpet" : "The carpet looks expensive.",
      "rail" : "The silver rail leads up into the tower with the stairs."
   ]));
}

void reset() {
 ::reset();
   if (!present("servant"))
     make(MOB"servant");
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
