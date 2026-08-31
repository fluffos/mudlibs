#include <std.h>
#include <sindarii.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 2);
    set_property("forest", 1);
    set_property("no castle", 1);
    set("short", "A path in the North Forest");
    set("long",
      "A small path leads through the great North Forest into much denser "
      "and older tree cover north. South, the forest starts to thin out. Where "
      "the forest thins, the makings of a more traveled path can be made out.");
    set_exits( 
              (["north" : ROOMS"forest3",
                "south" : ROOMS"forest1"]));
    set_items(
        (["path" : "A small path through the huge North Forest.",
	"forest" : "The North Forest.  It is not a very well-traveled "
	  "place."]) );
}

