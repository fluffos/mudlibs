#include <std.h>
#include <sindarii.h>
inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
   set_property("mountain",1);
    set("short", "Before a strange pit, leading into the ground");
    set("long",
        "In the center of the path a strange, large pit leads deep "
        "into the ground. Who or what ever built this cave obviously "
        "is not scared of anyone or anything else, seeing as they "
        "build their home in the center of a commonly traveled road. "
        "The two walls of the pass come down, feeding back into the "
        "path here.");
    set_exits(([ "east" : ROOMS"pass12",
                 "down"  : "/d/roston/rooms/C_room1",
                 "southeast" : ROOMS"spass11",
                 "northeast" : ROOMS"npass11",
                 "west" : ROOMS"pass14" ]));
}
