#include <std.h>
#include <citrin.h>

inherit ROOM;

void create() {
    ::create();
    set_name("clearing");
    set_short("clearing in the path");
    set_day_long("A large lake is to the west of the path.  The sun "
      "shines on it causing a very bright reflection enabling the "
      "view of an island in the middle of the lake.");
    set_night_long("A large lake is to the west of the path.  The moon "
      "shines on it causing a very bright reflection enabling the "
      "view of an island in the middle of the lake.");
set_property("forest", 1);
    set_properties((["light":1,"night light":0]));
    set_items(([
	"lake":"An island is seen in the center of the lake.",
      ]));
    set_exits(([
	"south":ROOMS"68",
	"northwest":ROOMS"70",
      ]));
}



