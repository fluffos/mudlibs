#include <lca.h>
#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_short("somewhere deep in an abandoned city");
    set_name("Lost City of Ancients Square");
    set_long("At one time this was the center of the activity of "
      "the market.  Much time has passed since then and the "
      "streets are bare and isolated.  Buildings can be seen in "
      "all directions but most of them are falling apart.  An old "
      "post sticks out from the ground to be what looks like at one "
      "time a board.  The air here is very musty and stale.");
    set_exits(([ 
	"north":PRESENT"4",
	"east":PRESENT"8",
	"west":PRESENT"6",
	"south":PRESENT"12",
      ]));
//    set_listen("default");
    set_properties(([ "light":2, "night light":1, "city":1 ]));
}

void reset() {
    ::reset();
    if(!present("old post"))
	new(OBJ"post")->move(this_object());
}

