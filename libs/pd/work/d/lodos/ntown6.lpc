#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("North on an old dirt path");
   set_long("The old dirt path leads north and south right through Lodos. "
     "All around you, to the north and one to the south, are towers. "
     "One tower, far to the north, stands high above the clouds. A single "
     "withered bush lies along the side of the path.");
   set_properties((["town" : 1, "outdoors" : 1, "light" : 2 ]));
   set_items(([ "path" : "It leads north and south.",
                "bush" : "The bush is withered and dead.",
                "tower": "A single tower to the north stands above the clouds."
   ]));
   set_exits(([ "south" : ROOMS"ntown5",
                "north" : ROOMS"ntown7" ]));
}

void reset() {
 ::reset();
   if (!present("citizen"))
     make(MOB"citizen");
}
