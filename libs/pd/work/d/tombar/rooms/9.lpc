// Coded by Whit

#include <std.h>
#include <tombar.h>


inherit ROOM;

void create() {
    ::create();
    set_name("a long, black hallway");
    set_long("The hallway winds its way underneath of the ocean.  The hall "
      "seems like an endless black void that goes on without ever ending.  "
      "The black stone walls are wet from the exposure from constant moisture "
      "that drips from the ceiling.  The floor is wet and slippery from the "
      "water.");
    set_items(([
	(({"wall","walls"})) : "The walls are wet from constant exposure to water.",
	"ceiling" : "Water seems to run from the ceiling making the floor wet.",
	"floor" : "The floor is wet from the dripping ceiling.  It is made of a "
	"smoothed black stone.",
      ]));
    set_property("light", 0 );
    set_property("night light", 0);
    set_property("inside", 1);
    set_exits(([
	"northwest" : ROOMS"8",
	"northeast" : ROOMS"11",
      ]));

}
