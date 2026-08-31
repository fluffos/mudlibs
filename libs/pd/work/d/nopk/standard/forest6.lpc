#include <std.h>
#include <sindarii.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 2);
    set_property("forest", 1);
    set_property("no castle", 1);
    set("short", "Path in the North Forest");
    set_long(
        "The forest is a dark and ominous place.  Teaming with life, "
        "the forest seems to be watching all that goes in inside it's "
        "depths.  The path underfoot leads north and south. ");
    set_exits( 
              (["south" : ROOMS"forest5",
                "north" : "/d/nopk/forest/forest95" ]) );
    set_items(
        (["path" : "A small path throught the huge North Forest.",
          "forest" : "The North Forest.  It is not a very well-"
          "traveled place.",
          "cavern" : "Its mysterious maw beckons you to enter."]) );
}
