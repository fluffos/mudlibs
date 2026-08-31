#include <lca.h>
#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_name("In the market");
    set_short("somewhere deep in an abandoned city");
    set_long("The road leads east and west.  To the east is the center "
      "of the marketplace.  Buildings stand tall to the north and "
      "south.  Almost all the windows have been broken out of them.");
    set_exits(([ 
	"east":PRESENT"7",
	"northwest":PRESENT"5",
      ]));
    set_items(([
	"windows":"They have been broken out of the buildings.",
      ]));
    set_properties(([ "light":2, "night light":1, "city":1 ]));
}

