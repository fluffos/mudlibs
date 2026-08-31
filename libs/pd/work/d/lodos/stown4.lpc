#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_properties(([ "town" : 1, "light" : 2, "night light" : 1 ]));
   set_short("Traveling further south of Lodos");
   set_day_long("The road begins to thin out a bit and a few scattered "
     "shadows cross the sunny path from a few scattered trees along the "
     "roadside. Wind whips across the road, sending dust high into the "
     "air.");
   set_night_long("The road begins to thin out a bit, though it is hard "
     "to see under the added shadows of the few scattered trees along "
     "the roadside. The wind has become more violent, fairly out in the "
     "open.");
   set_items(([
     "roadside" : "There are scattered trees along it.",
     "road" : "The road goes north and south. Trees begins to grow here.",
     "trees" : "The trees have started to take root around the roadside.",
     "wind" : "The wind whips across the road.",
     "dust" : "Dust and dirt are thrown into the air by the wind."
   ]));
   set_exits(([ "north" : ROOMS"stown3",
                "south" : ROOMS"stown5" ]));
}

void reset() {
 ::reset();
   if (!present("citizen"))
     make(MOB"citizen");
}
