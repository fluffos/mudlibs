#include <std.h>
#include <sindarii.h>
inherit ROOM;

void create() {
 ::create();
    set_property("light", 2);
    set_property("no castle", 1);
    set("short", "Northern path of the Daroq Mountain pass");
    set("long",
	"A gaping maw of a cave rests within the wall along the side "
        "of this path. The cave looks as though whatever made it "
        "carved it with claws and teeth, although it is not big "
        "enough for a dragon or even drake.");
    set_exits(([ "west" : ROOMS"npass6",
                 "enter" :ROOMS"daroq/entrance",
                 "east" : ROOMS"npass4" ]));
}
