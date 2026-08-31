#include <lca.h>
#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_name("In the market");
    set_short("somewhere deep in an abandoned city");
    set_long("It is musty inside the building.  A middle-sized counter "
      "is up against the north wall.  A sign lays apon the counter.  "
      "An old carpet lays in the middle of the floor.  The walls are "
      "bare and empty.");
    set_exits(([ 
        "west":PRESENT"2",
      ]));
    set_items(([
	"sign":"It is old and worn.  It is unlikely it can be read.",
	"counter":"It is old and dusty.",
      ]));
    set_properties(([ "light":2, "night light":1, "city":1,
	"indoors":1]));
}

void init() {
    ::init();
    add_action("read", "read");
}

int read(string str) {
    if(str != "sign") return 0;
    write("The sign is too old and worn to read.\n");
    return 1;
}


