// Coded by Whit

#include <std.h>
#include <tombar.h>


inherit ROOM;

void create() {
    ::create();
    set_name("a long, black hallway");
    set_long("The hallway seems to echo every movement throughout the entire "
      "hall.  Nothing much can be seen through the black hallways.  The only "
      "light source is the one of which you hold.  The walls are damp from the "
      "constant expore from the dripping water that comes from the ceiling.");
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
	"east" : ROOMS"14",
	"northwest" : ROOMS"7",
      ]));

}
