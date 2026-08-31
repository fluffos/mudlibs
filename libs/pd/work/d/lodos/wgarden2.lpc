#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_properties((["town" : 1, "light" : 2, "forest" : 1,
                    "night light" : 0 ]));
   set_short("West of a tower, in a garden");
   set_day_long("Just west of the northern Lodian tower, this part "
     "of the garden has trees and bushes all over the place. A small, "
     "white tree stands just off center between the stepping stones, "
     "leading north and south.");
   set_night_long("The piece of the garden, just west of the northern "
     "Lodos tower is dark not only from night, but from the immense "
     "shadow of the tower itself. Small shrubs rest under the shadows "
     "of the tree surrounding them. Darkened stepping stones have "
     "been placed down leading north and south.");
   set_items(([
      "stones" : "They are made to look like small cuts out of a tree.",
      "tower" : "It sends a dark shadow across the garden.",
      "trees" : "Small trees have been planted everywhere."
   ]));
   set_exits(([ "south" : ROOMS"wgarden1",
                "north": ROOMS"wgarden3"
   ]));
}

void reset() {
 ::reset();
   if (!present("moose"))
     make(MOB"moose");
}
