#include <std.h>
#include <sindarii.h>
inherit ROOM;

void create() {
 ::create();
    set_property("light", 1);
    set("short", "A small and narrow passageway");
    set("long",
        "This small and narrow passageway leads east, right through "
        "the elder guardian's chambers. The passageway is littered with "
        "small, jagged rocks.");
    set_exits(([ "up" : ROOMS"daroq/cave8",
                 "east" : ROOMS"daroq/cave6" ]));
}
