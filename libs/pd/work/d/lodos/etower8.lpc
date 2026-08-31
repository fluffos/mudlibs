#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("Along a twisted staircase");
   set_properties((["light" : 2]));
   set_properties((["town" : 1, "indoors" : 1, "building" : 1]));
   set_long("The stairs make a sharp turn to the east here, from the "
      "south. The south leads down the tower, and to the east the tower "
      "rises even higher than it already is. The tower is only a short "
      "distance higher.");
   set_exits(([ "south" : ROOMS"etower7",
                "east" : ROOMS"etower9"]));
   set_items(([
      "tower" : "It is not all too much taller.",
      "stairs" : "The stairs make a sharp turn here."
   ]));
}

void reset() {
 ::reset();
   if (!present("knight"))
     make(MOB"knight");
}
