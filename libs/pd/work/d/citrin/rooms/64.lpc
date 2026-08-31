#include <std.h>
#include <citrin.h>

inherit ROOM;

void create() {
    ::create();
    set_name("clearing");
    set_short("clearing in the path");
    set_long("Part of the path starts to turn away from the lake "
      "farther back into the forest.  The other part of the "
      "path continues to encircle the lake.");
    set_properties((["light":1,"night light":1, "forest":1]));
    set_items(([
	"lake":"An island is seen in the center of the lake.",
      ]));
    set_exits(([
	"east":ROOMS"63",
	"west":ROOMS"68",
	"southeast":ROOMS"60",
      ]));
}


