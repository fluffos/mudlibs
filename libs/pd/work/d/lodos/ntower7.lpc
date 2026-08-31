#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("Climbing the steps further up the tower");
   set_properties((["light" : 2]));
   set_properties((["town" : 1, "indoors" : 1, "building" : 1]));
   set_long("This room is very bright. The room was already bright, "
      "but the light is reflected off of the marble ceiling and walls, "
      "making the room even brighter. The red carpet is dirty and needs "
      "to be cleaned.");
   set_exits(([ "up" : ROOMS"ntower8",
                "down" : ROOMS"ntower6"]));
   set_items(([
      "carpet" : "The carpet here needs to be cleaned.",
      ({ "room", "light" }) : "The room is very bright.",
      ({ "walls", "ceiling" }) : "The walls and ceiling are marble."
   ]));
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

void reset() {
 ::reset();
   if (!present("noble"))
     make(MOB"noble");
}
