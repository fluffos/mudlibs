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
        "The short path leads up, onto the southern ledge of the "
        "Daroq Mountain pass walls, and west onto the actual pass. "
        "Several dead and rotting trees line the sides of the path "
        "here.");
    set_exits(([ "west" : ROOMS"spass11",
                 "up" : ROOMS"spass9" ]));
}
