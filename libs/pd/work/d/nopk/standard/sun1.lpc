#include <std.h>
#include <sindarii.h>

inherit ROOM;

void create() {
    set_property("light", 3);
    set_property("night light", 1);
    set_property("no castle", 1);
    set("short", "Sun Alley");
    set("long",
	"Sun Alley is a back alley that feeds into the larger Honin Road south. "
	"The alley goes only east from here. A restaurant is west, a sign hangs "
	"just outside of the door.");
    set_exits(([
      "south" : ROOMS"ehonin2",
      "west"  : ROOMS"restaurant",
      "east"  : ROOMS"sun2"
    ]));
    set_items(([
	"sign" :  "\n  _                        _\n ( )--.,,.----------.,,.--( )\n  |                        |\n"
                  "  |   The                  |\n  |       Weeping          |\n  |               Willow   |\n"
                  "  |                        |\n  |                        |\n (_)--.,,.----------.,,.--(_)",
        "road" : "Honin Road is south.",
    ]));
}

