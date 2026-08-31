#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("Inside a temple to Omicron");
   set_properties((["town" : 1, "indoors" : 1, "building" : 1])); 
   set_long("The dark blue walls of the temple symbolize peace "
            "and healing. The ground is a light white, almost "
            "grey tile. A passage leads to the east and to the "
            "west. To the south is a ladder leading up into the "
            "hall of peace.");
   set_items(([ "walls" : "They are a dark blue in color.",
                "tiles" : "The tiles on the ground are a light grey.",
                "passage" : "Passagways lead east, west, and south." ]));
   set_property("light", 2);
   set_exits(([ "west" : ROOMS"temple2",
                "east" : ROOMS"temple3",
                "out" : ROOMS"town2",
                "south" : ROOMS"temple4"]));
}

void reset() {
 ::reset();
   if (!present("statue"))
      new(OBJ"monk_stat")->move(this_object());
}
