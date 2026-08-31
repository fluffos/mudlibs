#include <std.h>
#include <roston.h>

inherit ROOM;

void create() {
    ::create();
    set_name("north of town square");
    set_items((["snow"   : "A very deep white snow",
	"cracks" : "A huge hole in the ground",
	"vapors" : "A weird looking mist",
	"dirt"  : "A light brown mixture"]));
    set_properties((["light":2, "night light":2]));
    set_short("A snow path");
    set_long("The cave is very dark and stinks.  The cracks "
      "are larger here, and more vapors are coming out of the "
      "cracks in the ground.");

    set_exits( (["west"  : ROOMS "roston52",
	"east"  : ROSTON"cave/cave1"]));
}                             
