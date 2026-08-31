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
        "You are on a dirt path, leading up on top of a ledge. "
        "The ledge is just a short climb from here, a climb anyone "
        "could make. The ledge looks fairly stable from here.");
    set_exits(([ "east" : ROOMS"npass1",
                 "up" : ROOMS"npass3" ]));
}
