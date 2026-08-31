#include <std.h>
#include <citrin.h>

inherit ROOM;

void create() {
    ::create();
    set_name("clearing");
    set_short("clearing in the path");
    set_long("The trees seem to grow more closely to the path "
      "here.  A large lake is to the west of the path.  Small "
      "animals scury over the path seemly disturbed by the "
      "disturbance of the forest around them.");
    set_properties((["light":1,"night light":1, "forest":1]));
    set_items(([
	"lake":"An island is seen in the center of the lake.",
      ]));
    set_exits(([
	"northwest":ROOMS"64",
	"northeast":ROOMS"61",
	"south":ROOMS"59",
      ]));
}

