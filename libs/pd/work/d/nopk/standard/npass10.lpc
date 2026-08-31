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
	"To the west a small dirt road connects this path to the "
        "main pass. A small, and dangerous-looking ledge lines the "
        "northern wall to the east.");
    set_exits(([ "west" : ROOMS"npass11",
                 "up" : ROOMS"npass9" ]));
}
