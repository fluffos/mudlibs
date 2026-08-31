#include <std.h>
#include <sindarii.h>
inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
   set_property("mountain",1);
    set("short", "To the east of a pass, on a mountain road");
    set("long",
        "Just to the east, past a strange pit in the ground, is a "
        "pass through the Daroq Mountains. West is a moutain road, "
        "which actually starts here. A dead tree has fallen over here.");
    set_exits(([ "east" : ROOMS"pass13",
                 "west" : "/d/lodos/mount4",
    ]));
}
