#include <lca.h>
#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_name("In the market");
    set_short("somewhere deep in an abandoned city");
    set_long("A large building has colapsed to the north preventing "
      "anyone from going further into the city.  The road leads back to the "
      "center of the market southeast from here.");
    set_exits(([ 
        "southeast":PRESENT"6",
      ]));
    set_items(([
	"building":"It is old and has collapsed.",
      ]));
    set_properties(([ "light":2, "night light":1, "city":1 ]));
}


