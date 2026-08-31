#include <std.h>
#include <sindarii.h>
inherit ROOM;

void create() {
 ::create();
    set_property("light", 2);
   set_property("mountain",1);
    set_property("no castle", 1);
    set("short", "Northern path of the Daroq Mountain pass");
    set("long",
	"The small, rocky ledge has already given way mostly in this "
        "spot, leaving quite a bit of pressure on this single point, "
        "which happens to be where you are standing. Leaping west, to "
        "the next section of the ledge may be dangerous..");
    set_exits(([ "west" : ROOMS"npass9",
                 "east" : ROOMS"npass7" ]));
}
