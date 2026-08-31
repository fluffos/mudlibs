#include <std.h>
#include <helgrath.h>
inherit ROOM;

void create() {
    ::create();
    set_properties(([
      "light" : 2,
    ]));
    set_short("Dark Woods Tower");
    set_long("The tall black tower has only one entrance, right in the front.  There "
      "is no door, but the inside appears nice and warm.  Water laps up against the "
      "small platform that makes up the only standing ground outside the tower."
      "  The only way back is across the roots.");
    set_exits( ([ "enter" : ROOMS "mtower01",
                  "roots" : ROOMS "forest_lake_w01"
     ]));
    set_smell("default", "It is too cold to smell anything.");
    set_listen("default", "A faint croaking noise can be heard.");
    set_items(([
        ({"water", "lake"}) : "%^GREEN%^A green glow comes from the lake, probably from magic.",
        "entrance" : "Inside, it seems sheltered from the wind.",
        "roots" : "The roots snake across the lake, and look like they could be climbed.",
        "tower" : "The tall tower emerges from the middle of the lake."
    ]));

}
