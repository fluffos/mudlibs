#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("Inside a temple to Omicron");
   set_properties((["town" : 1, "indoors" : 1, "building" : 1])); 
   set_long("The walls are covered with royal blue tiles and "
            "the ground with expensive-looking creamy white "
            "tiles. Gold has been weaved into the pillars "
            "against the walls. The temple expands further "
            "to the south, and back to the west.");
   set_property("light", 2);
   set_items(([ "walls" : "They are a dark blue in color.",
                "tiles" : "The tiles on the ground are a light grey."
            ]));
   set_exits(([ "west" : ROOMS"temple1",
                "south" : ROOMS"temple7" ]));
}

void reset() {
 ::reset();
   if (!present("monk"))
      new(MOB"monk1")->move(this_object());
}
