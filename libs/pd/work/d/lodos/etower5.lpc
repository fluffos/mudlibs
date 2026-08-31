#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("Along a twisted staircase");
   set_properties((["light" : 2]));
   set_properties((["town" : 1, "indoors" : 1, "building" : 1]));
   set_long("The spiral stairway leads west, further up into the tower. "
      "To the north, the stairway twists back down the tower to the "
      "dirt path below. The walls have no corners because this room is "
      "circular.");
   set_exits(([ "north" : ROOMS"etower4",
                "west" : ROOMS"etower6"]));
   set_items(([
      "stairway" : "The stairway leads north, down, and west, up.",
      "room" : "It's design is so that four rooms complete one circle.",
      "walls" : "The walls have no corners, like most of the tower."
   ]));
}

void reset() {
 ::reset();
   if (!present("knight")) {
     make(MOB"knight");
     make(MOB"knight");
   }
}
