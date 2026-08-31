#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("Standing before a temple to Omicron");
   set_properties(([ "town" : 1 ]));
   set_property("light", 2);
   set_long("The old dirt path continues east and west, but "
            "splits south into a large temple to Omicron, the "
            "god of peace and health. A peaceful feeling fills "
            "the air before the temple.");
   set_exits(([ "west" : ROOMS"town1",
                "east" : ROOMS"town3",
                "enter" : ROOMS"temple1"]));
}
