#include <std.h>
#include <citrin.h>

inherit ROOM;

void create() {
    ::create();
    set_name("clearing");
    set_short("clearing in the path");
    set_long("The path seems to clear away from the dense trees "
      "to the northwest.  The path is covered with small "
      "twigs.  The occasional forest animal scuries by "
      "alarmed by the disturbance of peace in the forest.  "
      "To the south a large lake can be seen.  An island "
      "can be seen in the middle of the lake.");
   set_property("forest", 1);
    set_properties((["light":1,"night light":0]));
    set_items(([
	"twigs":"They cover the path.",
	"lake":"An island is seen in the center of the lake.",
      ]));
    set_exits(([
	"southeast":ROOMS"69",
	"southwest":ROOMS"73",
	"northwest":ROOMS"71",
      ]));
}

