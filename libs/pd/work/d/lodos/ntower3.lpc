#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("Climbing golden steps");
   set_properties((["town" : 1, "indoors" : 1, "building" : 1]));
   set_properties((["light" : 2]));
   set_long("The royal red stairs lead upwards, and like all steps, they "
      "also lead down. The tower is still much higher and through a small "
      "painted glass window you can see the street below.");
   set_exits(([ "up" : ROOMS"ntower4",
                "down" : ROOMS"ntower2"]));
   set_items(([
      "window" : "It is made of painted glass.",
      "stairs" : "The stairs lead up into the tower."
   ]));
}

void reset() {
 ::reset();
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
