#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_properties((["indoors" : 1, "light" : 2,
                    "night light" : 1]));
   set_short("Northeastern corner of the temple");
   set_day_long("This room, the northeast corner of the temple has three doorways "
     "leading into and out of it. These doorways go south, west, and northeast. "
     "Magnificent symbols have been painted on the walls in a dark blue paint. "
     "Daylight shines into this room from the south and west.");
   set_night_long("This is the very northeastern corner of the temple. Three "
     "doorways are in this room; to the south, west, and northeast. In a very "
     "dark, nearly black, blue paint symbols have been painted onto the walls. "
     "No doubt they are religious symbols of some faith. The northeastern "
     "passageway leads up to some sort of small tower on the corner of this "
     "very temple.");
   set_items(([
     "symbols" : "Painted in dark blue, symbols of the faith practiced within "
                 "this temple.",
     "tower"   : "A tower, more of a guard post, is on each corner of the temple.",
     "walls"   : "Onyx walls line the temple."
   ]));
   set_exits(([ "west"      : ROOMS"l1m2",
                "northeast" : ROOMS"l1ne3",
                "south"     : ROOMS"l1m6"
   ]));
}

void reset() {
 ::reset();
   if (!present("healer"))
     make(MOB"healer");
}

