#include <std.h>
#include <tombar.h>
#include <daemons.h>

inherit BEACH;
#include <ocean.h>

void create() {
    ::create();
    set_property("no castle", 1);
    set_property("light", 3);
    set_property("night light", 2);
    set_property("beach",1);
    set_max_catch(15);
    set_max_fishing(4);
    set_chance(10);
    set_short("Tombar Island");
	set_long("The shores are covered in a black, oily sand.  Remnants of old trees "
		"remain scattered about shores.  The only sign of life is small, weathered "
		"path can be seen heading into the treeline.  Branches have been strewn "
		"over the area making the sand crunchy when stepping.  The waves from the "
		"ocean wash over the beach, carrying the black substance back into the "
		"ocean with it.");
	set_smell("default", "A rancid smell lingers on the beach.");
    set_items( ([
	"sand" : "The sand is black.  How strange."]) );
/*
    set_exits( ([
       "north" : ROOMS"island/3",
        "east" : ROOMS"island/2"]) );
*/
    set_letter("l");
}

