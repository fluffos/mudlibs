#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_properties((["outdoors" : 1, "light" : 2,
                    "night light" : 1]));
   set_short("On a dirt road");
   set_day_long("This dirt road heads south for a little and north over a hill "
     "up to a elaborate temple. Grass and wild flowers grow along the side of "
     "the road, growing healthily in the steady sunlight. A few stones are all "
     "that really occupy the thin dirt road.");
   set_night_long("Moonlight shines onto a thin dirt road, leading both north "
     "and a little to the south, from behind long patches of clouds. Grass and "
     "several wildflowers grow near the sides of the road. A chill night breeze "
     "blows dirt into the air.");
   set_items(([
     "flowers" : "Flowers grow in the grass near the sides of the road.",
     "wildflowers":"Beautiful wildflowers grow here.",
     "grass"   : "Long blades of grass wave in the breeze",
     "clouds"  : "Large groups of clouds linger in the sky.",
     "road"    : "A dirt road like any other, leading north and south."
   ]));
   set_exits(([ "north" : ROOMS"npath3",
                "south" : ROOMS"npath1",
   ]));
}

/*void reset() {
 ::reset();
   if (!present("weed"))
     make(MOB"weed2");
}
*/
