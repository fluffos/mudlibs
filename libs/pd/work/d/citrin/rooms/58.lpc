#include <std.h>
#include <citrin.h>

inherit ROOM;

void create() {
    ::create();
    set_name("clearing");
    set_short("clearing in the path");
    set_long("The path seems to end here.  Where the path was is now only "
      "dirt and grass.  The lake can be seen to the west.");
    set_properties((["light":1,"night light":1, "forest":1]));
    set_items(([
	"lake":"An island is seen in the center of the lake.",
      ]));
    set_exits(([
	"northeast":ROOMS"59",
      ]));
}

