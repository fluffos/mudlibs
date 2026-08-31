#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
    ::create();
    set_properties((["outdoors" : 1, "light" : 2,
	"night light" : 1]));
    set_short("Atop a small grassy hill");
    set_day_long("From atop this small, grassy-green hill, the mid sized town to "
      "the south can be looked across all the way to the town square. A dirt path "
      "continues south towards the town and also heads to a temple just north of "
      "this spot. The sun rests happily in the sky, shining onto the hill, "
      "providing a nice warm spot here.");
    set_night_long("From atop this small, grassy-green hill, moonlight bathes the "
      "surrounding area making it possible to see much of the town to the south. "
      "An illustrious temple sits just north of here. The old dirt road leads both "
      "south and north.");
    set_items(([
	"hill"   : "Soft green grass grows on this peaceful little hill.",
	"temple" : "The illustrious temple rises from the ground just north of this "
	"spot. ",
	"road"   : "A dirt road lead north and south, to town and a temple.",
	"town"   : "Much of the town of Lodos can be seen from here."
      ]));
    set_exits(([ "north" : ROOMS"npath5",
	"south" : ROOMS"npath3",
      ]));
}

void reset() {
    ::reset();
    if (!present("pygmy"))
	make(MOB"smurf2");
}
