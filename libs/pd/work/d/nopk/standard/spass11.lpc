#include <std.h>
#include <sindarii.h>
inherit ROOM;

void create() {
 ::create();
    set_property("light", 2);
   set_property("mountain",1);
    set_property("no castle", 1);
    set("short", "Small path leading into mountain pass");
    set("long",
        "This small path connects the southern ledge of the Daroq "
        "Mountain pass to the actual pass. To the northwest is "
        "an opening to some cave, in the center of the path.");
    set_exits(([ "northwest" : ROOMS"pass13",
                 "east" : ROOMS"spass10" ]));
}
