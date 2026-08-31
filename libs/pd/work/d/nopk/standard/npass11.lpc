#include <std.h>
#include <sindarii.h>
inherit ROOM;

void create() {
 ::create();
    set_property("light", 2);
   set_property("mountain",1);
    set_property("no castle", 1);
    set("short", "A very short dirt road");
    set("long",
	"This very short dirt road simply leads southwest onto the "
        "Daroq Mountain pass and east onto the northern ledge of the "
        "pass. A light breeze stirs the dirt and rattles the trees. "
        "The ground is a dark brown rock, like the rest of the moutains.");
    set_exits(([ "southwest" : ROOMS"pass13",
                 "east" : ROOMS"npass10" ]));
}
