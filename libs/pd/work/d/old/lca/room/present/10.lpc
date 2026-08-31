#include <lca.h>
#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_name("in a church");
    set_short("somewhere deep in an abandoned city");
    set_long("The church has large,  cathedral ceilings.  Lamps hang "
      "down from the ceiling so that there could be light at gatherings.  "
      "Long pews are lined up going all the way up to the alter at the "
      "front of the church.  The alter is made of a black marble.");
    set_exits(([ 
        "east":PRESENT"11",
        "out":PRESENT"9",
      ]));
    set_items(([
	"altar":"It is made from black marble.",
      ]));
    set_properties(([ "light":2, "night light":1, "city":1 ]));
}


