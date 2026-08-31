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
        "You have climbed onto a ledge, overlooking the Daroq "
        "Mountain pass. The pass is far below, not enabling "
        "anyone to climb down onto it. Several cave entrances "
        "can be seen, along the walls of the pass.");
    set_exits(([ "west" : ROOMS"spass4",
                 "down" : ROOMS"spass2" ]));
}
