#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("Inside a temple to Omicron");
   set_properties((["town" : 1, "indoors" : 1, "building" : 1])); 
   set_property("light", 2);
   set_long("The tiles on the ground are a light grey and the "
            "dark blue tiles seem to radiate with a strange light. "
            "A ladder leads up through a small tower into the hall "
            "of peace.");
   set_exits(([ "north" : ROOMS"temple1",
                "up" : ROOMS"temple5" ]));
}
