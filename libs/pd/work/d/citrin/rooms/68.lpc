#include <std.h>
#include <citrin.h>

inherit ROOM;

void create() {
    ::create();
    set_name("clearing");
    set_short("clearing in the path");
    set_long("The path seems to enter a peninsula into the lake.  "
      "Water surrounds the path from the west and south of it.");
    set_properties((["light":1,"night light":1, "forest":1]));
    set_items(([
	"lake":"An island is seen in the center of the lake.",
      ]));
    set_exits(([
	"east":ROOMS"64",
	"north":ROOMS"69",
	"northeast":ROOMS"65",
      ]));
}


