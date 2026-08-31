#include <std.h>
#include <tirun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 1);
    set_property("no castle", 1);
    set("short", "Monastary stairwell");
    set("long",
        "A spiraling flight of stairs leads up to the monastery "
        "attic. The prayer area is west.");
    set_exits( ([
                "west" : ROOMS"monastery",
                "up" : ROOMS"clergy/monk/monk_join",
    ]) );
    set_items(
        (["stairs" : "They spiral up and down in this old monastery."]) );
    set_property("no castle", 1);
}
