// Coded by Whit

#include <std.h>
#include <tombar.h>

inherit ROOM;

void create() {
    ::create();
    set_name("underwater temple");
    set_long("The long temple halls seem to get smaller and wetter.  The markings "
      "no longer exist on the walls.  The halls are made from pure black stone and "
      "it is hard to see things in such a black blackness.");
    set_listen("default", "Dripping water can be heard in the distance.");
    set_properties(([ "light": 1, "night light": 1 ]));
    set_exits(([
	"south" : ROOMS"1",
	"west" : ROOMS"4",
	"north" : ROOMS"5",
	"northeast" : ROOMS"7",
      ]));
    set_items(([
	"wall" : "There are several markings on the wall.  They seem to signify royalty.",
	"ceiling" : "Water drips from the ceiling.",
      ]));

}
