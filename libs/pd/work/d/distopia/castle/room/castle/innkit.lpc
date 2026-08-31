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
		"So this is what smells so good.  A chicken is slowly being turned over a roasted flame by "
		"by a bulky looking man in a white hat.  The fireplace is large and roaring at a pretty good "
		"pace by the amount of heat that can be felt.  To the west, another explosion of laughter is heard "
		"most of all by the gentle voice of the inn keeper herself."
	);
	set_smell("default", "The strong smell of mutton roasting on a spit.  Mouth watering.");
    set_listen("default", "An explosion of laughter and an upbeat tune fill the air");
	set_items
	(
	        ([
	                "fireplace" : "It's pretty big.  The heat feels good compared to the chill outside",
	        ])
	);
	
	set_exits
	(([
		"west" : ROOMS"innbar",
	]));
}
void reset()
{
	if(!present("cook"))
	{
		new(MOB"cook")->move(this_object());
	}
}
