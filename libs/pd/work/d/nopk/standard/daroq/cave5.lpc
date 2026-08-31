#include <std.h>
#include <sindarii.h>
inherit ROOM;

void create() {
 ::create();
    set_property("light", 1);
    set("short", "Traveling down, into the heart of the cave");
    set("long",
        "A foul stench enters this room from right above. This cave "
        "smells like it belongs to an army of orcs. A tunnel leads up, "
        "and a small passageway leads to the west.");
    set_smell("default", "A putrid stench fills the air.");
    set_exits(([ "west" : ROOMS"daroq/cave6",
                 "up" : ROOMS"daroq/cave4" ]));
}
