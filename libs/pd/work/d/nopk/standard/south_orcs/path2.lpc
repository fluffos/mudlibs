#include <std.h>
#include <sindarii.h>
inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
    set_property("night light", 0);
    set_property("no castle", 1);
    set("short", "A path leading through the orc fortress");
    set("long",
        "The road is now completely nothing more than a dirt "
        "path. The forest is widening out, as you near a clearing. "
        "Several small huts have been set up along the sides of the road "
        "here.");
    set_exits( 
	      (["north" : ROOMS"south_orcs/path1",
           "west" : ROOMS"south_orcs/hut1",
          "south" : ROOMS"south_orcs/path3"]) );
}
