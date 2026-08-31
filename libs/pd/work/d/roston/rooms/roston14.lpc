#include <std.h>
#include <roston.h>

inherit ROOM;

void create() {
    ::create();          

    set_name("on a path north of town square");
    set_items((["snow"   : "A very deep white snow",
	"dirt"  : "A light brown mixture"]));     
    set_properties((["light":2, "night light":3]));
    set_short("A dirt path");
    set_long("This path seems to be leading to a white palace.  You seem to notice "
      "that there are not many footprints on the ground.  There seems to be more snow "
      "on the side of the path.");

    set_exits( ([ "north" : ROOMS "roston15",
	"south" : ROOMS "roston2" ]));
}

