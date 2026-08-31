#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("Inside a temple to Omicron");
   set_properties((["town" : 1, "indoors" : 1, "building" : 1])); 
   set_property("light", 2);
   set_long("You have come to a three-way fork in the corridors "
            "through the temple. The corridors lead east, "
            "west, and south. The walls are a light red here.");
   set_items(([ "walls" : "They are a light red in color.",
                "tiles" : "The tiles on the ground are a light grey."
            ]));
   set_exits(([ "east" : ROOMS"temple7",
                "west" : ROOMS"temple9",
                "south" : ROOMS"healer" ]));
}
