#include <std.h>
#include <sindarii.h>
inherit ROOM;

void create() {
 ::create();
    set_property("light", 2);
    set_property("no castle", 1);
    set("short", "Southern wall along the Daroq Mountains Pass");
    set("long",
        "The ledge is still rather unstable, leaving no room "
        "for a cave or pit of any sort. This path is still too "
        "high up to allow a jump down, on to the pass.");
    set_exits(([ "west" : ROOMS"spass8",
                 "east" : ROOMS"spass6" ]));
}
