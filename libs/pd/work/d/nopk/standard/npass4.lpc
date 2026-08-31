#include <std.h>
#include <sindarii.h>
inherit ROOM;

void create() {
 ::create();
    set_property("light", 2);
    set_property("no castle", 1);
    set("short", "Northern path of the Daroq Mountain pass");
    set("long",
	"The ledge continues west and heads back down to the east. "
        "The path has become as wide as the entire ledge, making "
        "it much harder to keep your balance on these rocks.");
    set_exits(([ "west" : ROOMS"npass5",
                 "east" : ROOMS"npass3" ]));
}
