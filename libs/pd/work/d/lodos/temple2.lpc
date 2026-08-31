#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("Inside a temple to Omicron");
   set_property("light", 2);
   set_properties((["town" : 1, "indoors" : 1, "building" : 1])); 
   set_long("Light shines in from the entrance to the east. "
            "A calming feeling grows from the south of here. "
            "The tiles on the walls are a royal blue and the "
            "tiles on the ground, though worn down, are a "
            "creamy white.");
   set_items(([ "walls" : "They are a royal blue in color.",
                "tiles" : "The tiles on the ground are a light grey."
            ]));
   set_exits(([ "east" : ROOMS"temple1",
                "south" : ROOMS"temple9" ]));
}
