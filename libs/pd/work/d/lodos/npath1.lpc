#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_properties((["outdoors" : 1, "light" : 2,
                    "night light" : 1]));
   set_short("On a dirt road");
   set_day_long("Dust stirs around in a dirt devil from the dirt "
     "road. A few trees have been planted here near the side of the "
     "road. The dirt road heads north up to some sort of building.");
   set_night_long("A cool breeze throws dust into the air. Several "
     "trees stand by the sides of the path as silent sentinals. "
     "The dirt road leads north to some shadowy figure. A garden "
     "rests south, bathed in moonlight.");
   set_items(([
     "garden"  : "There is a mid-sized garden south of here.",
     "trees"   : "Trees have been planted near the sides of the road.",
     "dust"    : "Dust blows into the air in a thick cloud.",

     "road"    : "The road heads up to a building to the north.",
     "building": "The nature of the building cannot be made out from "
                 "here."
   ]));
   set_exits(([ "north" : ROOMS"npath2",
                "south" : ROOMS"ngarden",
   ]));
}
