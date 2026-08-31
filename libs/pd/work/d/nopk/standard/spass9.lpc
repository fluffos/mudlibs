#include <std.h>
#include <sindarii.h>
inherit ROOM;

void create() {
 ::create();
    set_property("light", 2);
   set_property("mountain",1);
    set_property("no castle", 1);
    set("short", "Southern wall along the Daroq Mountains Pass");
    set("long",
        "The ground below is much smoother than that to the east. "
        "The ledge has begun to widen a bit, and has started to slope "
        "downwards. Further to the west the ledge slopes down and "
        "feeds into the pass below.");
    set_exits(([ "down" : ROOMS"spass10",
                 "east" : ROOMS"spass8" ]));
}
