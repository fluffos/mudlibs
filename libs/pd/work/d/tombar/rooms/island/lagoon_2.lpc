#include <std.h>
#include <tombar.h>

inherit ROOM;
int open;

void create() {
    ::create();
    set_name("Tombar Lagoon");
    set_properties(([ "light": 1, "night light": 0 ]));
    set_exits(([
		"west" : ROOMS"island/lagoon_1",
	]));
	set_long("The path begins to follow around the waters edge.  Scum "
		"and algea line the side of the water.  Small fish are seen in the "
		"water belly up floating with the waves of the ocean.  A small "
		"ship can be seen docked at the far side of the lagoon.");
	set_listen("default", "Flying bugs create a small buzzing sound.");
	set_smell("default", "The smell of death and decay lingers.");
	set_items(([ 
		"fish" : "The fish are floating dead in the water.",
		"ship" : "The ship can be seen at the other side of the lagoon "
			"rocking in the waves.",
	]));

}

