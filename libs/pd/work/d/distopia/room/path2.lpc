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
	set_day_long
	(
	        "The wolves have picked up a scent-- "
	        "the slow and rythmic crunching on the pathway "
	        "rises to a frenzied tempo. "
	        "However, it seems that the pack has caught it's prey "
	        "and it looks like it's going to be a fight. The path "
	        "is still here.  Those that can escape the wolves "
	        "can continue to Distopia."
	);
	set_night_long
	(
	        "The wolves have picked up a scent-- "
	        "the slow and rythmic crunching on the pathway "
	        "rises to a frenzied tempo. "
	        "However, it seems that the pack has caught it's prey "
	        "and it looks like it's going to be a fight. The path "
	        "is still here.  Those that can escape the wolves "
	        "can continue to Distopia."
	);
	set_smell("default", "The frest aroma of pine trees fills the air.");
    set_listen("default", "The howling is everywhere! Wolves barking! Complete chaos!");
	set_items
	(
	        ([
	                "forest" : "The forest streches out endlessly.",
	                "boots " : "Perhaps it's time to replace these old things?",
	                "animal" : "You hear it... But where is it coming from?",
	                ({"wolf","wolves"}) : "The pack of half insane wolves is determined to make you a meal"
	        ])
	);
	set_exits
	(([
		"east" : ROOMS"path3",
		"west" : ROOMS"path"
	]));
}
void reset() 
{
	::reset();
	if(!present("wolf"))
	{
		new(MOB"dfwolf")->move(this_object());
		new(MOB"dfwolf")->move(this_object());
		new(MOB"dfwolf")->move(this_object());
		new(MOB"dfwolf")->move(this_object());
		new(MOB"dfwolf")->move(this_object());
	}
}
