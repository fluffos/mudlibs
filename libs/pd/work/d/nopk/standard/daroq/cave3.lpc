#include <std.h>
#include <sindarii.h>
inherit ROOM;

void create() {
 ::create();
    set_property("light", 1);
    set("short", "Traveling down, into the heart of the cave");
    set("long",
        "The cave walls are close and cramped, looking as if they would "
        "crush the life out of anything living. The air is cold and "
        "damp.");
    set_smell("default", "A putrid stench fills the air.");
    set_listen("default", "Something can be heard moving about.");
    set_exits(([ "down" : ROOMS"daroq/cave4",
                 "up" : ROOMS"daroq/cave2" ]));
}
