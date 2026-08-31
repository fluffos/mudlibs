#include <std.h>
#include <sindarii.h>
inherit ROOM;

void create() {
 ::create();
    set_property("light", 2);
    set_property("no castle", 1);
    set("short", "The entrance of a cave");
    set("long",
	"This appears to be a cave of some depth. The only "
        "light is that which comes through the cave opening. A tunnel "
        "leads down, deeper into the cave.");
    set_exits(([ "down" : ROOMS"daroq/cave1",
                 "out" : ROOMS"npass5" ]));
}
