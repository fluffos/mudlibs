#include <std.h>
#include <sindarii.h>
inherit ROOM;

void create() {
 ::create();
    set_property("light", 2);
    set_property("no castle", 1);
    set("short", "Northern path of the Daroq Mountain pass");
    set("long",
	"From here two cave entrances can be seen; one to the east "
        "and one to the west. The ledge has become rather narrow and "
        "you can't help but wonder if it will give out under your "
        "weight.");
    set_exits(([ "west" : ROOMS"npass7",
                 "east" : ROOMS"npass5" ]));
}
