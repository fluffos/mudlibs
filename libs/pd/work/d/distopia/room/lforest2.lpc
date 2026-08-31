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
	set_short("Forest Path.");
	set_day_long
	(
	        "The trail skirts to the north east and away from the edge of the forest."
	        " As the sun beats down the shade of the trees only meters away looks promising."
	);
	set_night_long
	(
		"At night the forest is even more freightening. The slightest sound creeps down "
		"the spine and threatens to overwhelm the less brave. The trail, although hard "
		"to make out, seems to be heading away from the forest.  A good thing, too."
	);
	set_items
	(
	        ([
	                "trail" : "Maybe you should follow it?",
		            "forest" : "It looks spooky..."
   			])
	);
	set_exits
	(([
		"west" : ROOMS"lforest1",
		"northeast" : ROOMS"lforest3",
"south" : ROOMS"forest3"
		
	]));
}
