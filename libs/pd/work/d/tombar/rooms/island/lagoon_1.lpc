#include <std.h>
#include <tombar.h>

inherit ROOM;
int open;

void create() {
    ::create();
    set_name("Tombar Lagoon");
    set_properties(([ "light": 1, "night light": 0 ]));
    set_exits(([
		"southwest" : ROOMS"island/east_path_3",
		"northwest" : ROOMS"island/lagoon_3",
		"east" : ROOMS"island/lagoon_2",
	]));
	set_long("As the path begins to follow around the waters edge, scum "
		"and algea can be seen lineing the shore.  Small fish are seen "
		"in the water belly up floating with the waves of the ocean.  A "
		"small ship can be seen docked at the far side of the lagoon.");
	set_listen("default", "Flying bugs create a small buzzing sound.");
	set_smell("default", "The smell of death and decay lingers.");
	set_items(([ 
		"fish" : "The fish are floating dead in the water.",
		"ship" : "The ship can be seen at the other side of the lagoon "
			"rocking in the waves.",
	]));
}

