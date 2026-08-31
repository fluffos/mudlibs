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
        "This small path leads up, above the pass through the "
        "Daroq mountains. The climb up looks rather steep from "
        "here, though not at all impossible. The path leads northeast, "
        "then east down into the pass.");
    set_exits(([ "east" : ROOMS"spass1",
                 "up"   : ROOMS"spass3" ]));
}
