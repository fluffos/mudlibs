#include <std.h>
#include <sindarii.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 2);
    set_property("forest", 1);
    set("short", "The North Forest");
    set("long",
	"The southern edge of a huge forest is just north of the village of "
        "Tirun. The forest extends in all directions, with a small path "
	"leading deeper into it north and into one of the main "
	"village roads south.");
    set_exits( 
              (["north" : ROOMS"forest2",
                "south"  : "/d/nopk/tirun/ngate"]) );
    set_items(
        (["path" : "A small path throught the huge North Forest.",
	  "forest" : "The North Forest. It is not a very well traveled place.",
	  "village" : "The grand village of Tirun"]) );
}

