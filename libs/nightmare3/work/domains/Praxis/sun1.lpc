#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 4);
    set_property("night light", 1);
    set_property("no castle", 1);
    set_short( "Sun Alley near Centre Path");
    set_long(
"Sun Alley is a bright path, named for the fact that the sun "
"always seems to be shining down upon it. The path is fairly "
"quiet, except for the occasional villager that is out strolling "
"or running their errands. The alley runs north of the village, "
"and interescts Centre Path west of here. To the south "
"you can see a small brown thatch house. " );
    set_items(
	(["alley" : "It is bright and cheerful, not like that alley on "
	    "the south end.",
	  "path" : "The main north-south road of Praxis.",
	  "intersection" : "Sun alley meets Centre Path there.",
	  "house" : "It's a small thatch house, nothing special."]) );
    set_exits( 
	      (["east" : "/domains/Praxis/sun2",
		"west" : "/domains/Praxis/n_centre2",
		"south"	 : "/domains/Praxis/house"]) );
}

