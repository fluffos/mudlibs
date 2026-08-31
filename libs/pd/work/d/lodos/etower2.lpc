#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("Along a twisted staircase");
   set_properties((["light" : 2, "town" : 1, "indoors" : 1,
     "building" : 1]));
   set_long("The eastern tower along the dirt path has a twisted and "
      "winding staircase leading up to the top of it. Two windows let "
      "light into the room. One of the windows is cracked.");
   set_exits(([ "down" : ROOMS"etower1",
                "north" : ROOMS"etower3"]));
   set_items(([
      "windows" : "One of the windows has a large crack in it.",
      "window" : "It has been smashed by a hammer or bat.",
      "staircase" : "The stairs wind up into the top of the tower.",
      "path" : "It cannot be seen from here."
   ]));
}

void reset() {
 ::reset();
   if (!present("soldier"))
     make(MOB"soldier2");
}
