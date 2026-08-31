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
	"The entire northern wall here has been turned into a the "
        "gaping maw of a cave. The cave is too dark to see into from "
        "here. Below you, the pass has recieved considerable damage from "
        "boulders.");
    set_exits(([ "west" : ROOMS"npass8",
                 "enter": ROOMS"daroq/cave11",
                 "east" : ROOMS"npass6" ]));
}
