#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_properties(([ "town" : 1, "light" : 2, "night light" : 1 ]));
   set_short("En route south of lodos");
   set_day_long("The road leads south and north. The air is comfortably "
     "cool. A light breeze shakes the few trees around the road. A small "
     "house is being used as a shop to the east. A small sign has been "
     "posted in the ground.");
   set_night_long("The road leads both to the south and to the north. "
     "The air is cold and chilly. It is becoming hard to see. A small, "
     "dark house is being used as a shop to the east. Shadows fall "
     "across the sign in the ground.");
   set_items(([
     "trees": "Newly planted trees.",
     "road" : "The old road leads both north and south.",
     "building" : "A small little building with a sign.",
   ]));
   set_exits(([ //"east" : ROOMS"pipes",
                "south" : ROOMS"stown3",
                "north" : ROOMS"stown1" ]));
}
