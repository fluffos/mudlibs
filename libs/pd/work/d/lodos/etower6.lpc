#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("Along a twisted staircase");
   set_properties((["light" : 3]));
   set_properties((["town" : 1, "indoors" : 1, "building" : 1]));
   set_long("The stairs twist and turn along the outer wall of the "
     "room. This stair patern is consistent throughout the entire "
     "tower. The window here has been jammed open, letting even more "
     "than usual sunlight flow in.");
   set_exits(([ "east" : ROOMS"etower5",
                "up" : ROOMS"etower7"]));
   set_items(([
      "stairs" : "The line the outer wall of the room.",
      "tower" : "It twists and turns, always going upwards.",
      "window" : "It has been jammed open to let the light in freely."
   ]));
}

void reset() {
 ::reset();
   if (!present("maid"))
     make(MOB"maid");
}
