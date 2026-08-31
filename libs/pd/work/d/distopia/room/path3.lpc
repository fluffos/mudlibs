#include <std.h>
#include <hermes.h>
inherit ROOM;
void create()
{
	::create();
	set_properties
	(
	        (["light" : 2, "night light" : 1, "forest" : 1])
	);
	set_short("Road to Distopia.");
	set_smell("default", "The frest aroma of pine trees fills the air.");
    set_listen("default", "The faint howls echo in the distance.");
	set_day_long
	(
	        "The whines and howls fade in the distance "
	        "the forest is horribly deep here. It would be "
	        "incredibly easy to get lost.  However, the path "
	        "is still remarkably clear and easy to navigate. "
	        "The sunlight reflects off a small pond."
	);
	set_night_long
	(
	        "The moonlight peeks through the thick forest canopy "
	        "in brilliant, pale beams. Just enough light is given "
	        "to see the path and navigate through the forest. The "
	        "best feature is the lake, the water sparkling through "
	        "the individual beams of moonlight."
	);
	set_items
	(
	        ([
	                "forest" : "The forest streches out endlessly.",
	                "path" : "It gives you comfort to know you're not lost.",
	                "lake" : "The water looks beautiful. But you dare not step off the path to take a closer look.",
	        ])
	);
	set_exits
	(([
		"east" : ROOMS"path4",
		"west" : ROOMS"path2"
	]));
}
void reset() 
{
	::reset();
	if(!present("wolf"))
	{
		new(MOB"dwolf")->move(this_object());
		new(MOB"dwolf")->move(this_object());
	}
	if(!present("owl"))
	{
		new(MOB"dowl")->move(this_object());
		new(MOB"dowl")->move(this_object());
	}
}
