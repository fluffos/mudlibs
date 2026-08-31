#include <lca.h>
#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_name("North of the Square");
    set_short("somewhere deep in an abandoned city");
    set_long("The road seems bare.  Not even a single footprint is "
      "imprinted on the ground.  The buildings that are to the east "
      "and west have been neglected for so long they are falling "
      "apart which makes it imposible to explore them.  To the south "
      "is the center of the city.  To the north is the once busy market.");
    set_exits(([ 
	"north":PRESENT"2",
	"south":PRESENT"7",
      ]));
    set_properties(([ "light":2, "night light":1, "city":1 ]));
}

