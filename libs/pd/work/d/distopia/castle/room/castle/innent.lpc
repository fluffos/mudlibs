#include <std.h>
#include <discastle.h>
inherit ROOM;
void create()
{
	::create();
	set_properties
	(
	        (["light" : 2, "night light" : 2, "inside" : 1])
	);
	set_short("Mad Cow Tavern.");
	set_long
	(
	        "As soon as one enters the Inn the atmosphere changes.  Evil does not invade "
	        "this place of happiness and peace.  Cheerful music comes from the main room "
	        "to the east totally out of place on this seemingly dreary and depressing land. "
	        "Why would anyone want to ever leave?"
	);

	set_smell("default", "The strong smell of mutton roasting on a spit.  Mouth watering.");
    set_listen("default", "An explosion of laughter and an upbeat tune fill the air");
	/*
	set_items
	(
	        ([
	                "forest" : "The forest streches out endlessly.",
	                "boots " : "Perhaps it's time to replace these old things?",
	                "animal" : "You hear it... But where is it coming from?",
	                ({"wolf","wolves"}) : "The pack of half insane wolves is determined to make you a meal"
	        ])
	);
	*/
	set_exits
	(([
		"east" : ROOMS"innbar",
		"out" : ROOMS"npath6"
	]));
}
void reset() 
{
	::reset();
	if(!present("bell"))
	{
		new(MOB"bell")->move(this_object());
	
	}
}
