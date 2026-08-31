#include <std.h>
#include <sindarii.h>
inherit ROOM;

void create() {
 ::create();
    set_property("light", 3);
    set("short", "Entrance to the Daroq caves");
    set("long",
        "Light floods this room, from the contrast of the dark tunnels "
        "below and the light outside of the cave. The giant cave maw "
        "gapes open to the outside here.");
    set_listen("default", "Many creatures can be heard moving about.");
    set_exits(([ "out" : ROOMS"npass7",
                 "down" : ROOMS"daroq/cave10" ]));
}
