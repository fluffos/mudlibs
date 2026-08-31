#include <lca.h>
#include <std.h>

inherit VAULT;

void create() {
    ::create();
    set_name("the clock tower");
    set_short("somewhere deep in an abandoned city");
    set_day_long("The corridor ends here at the start of a door.  Light "
      "can be seen from the crack under the door.");
    set_exits(([ 
	"west":PRESENT"t5",
	"east":PRESENT"t3",
      ]));
    set_door("door", ROOMS"tower/5", "west", "old steel key");
    set_open("door", 0);
    set_locked("door", 1);
    set_items(([
      ]));
    set_properties(([ "light":2, "night light":1, "city":1 ]));
}

