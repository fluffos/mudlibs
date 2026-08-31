#include <std.h>
#include <sindarii.h>
inherit ROOM;
void create() {
 ::create();
    set_property("light", 2);
   set_property("mountain",1);
    set_property("no castle", 1);
    set("short", "Eastern end of the Daroq Mountains Pass");
    set("long",
        "This small path leads west above the Daroq Mountain "
        "pass. The path leads west, towards a ledge, high above. "
        "Across the pass, to the south, the southern ledge of "
        "the pass can be seen.");
    set_exits(([ "southeast" : ROOMS"pass4",
                 "west" : ROOMS"npass2" ]));
}
