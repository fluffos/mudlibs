#include <std.h>
#include <std.h>
#include <hermes.h>
inherit ROOM;
void create()
{
	::create();
	set_properties
	(
	        (["light" : 2, "night light" : 1, "plains" : 1])
	);
	set_short("Forest Path.");
	set_long
	(
	        "The house is visible to the east. Stepping through a rusted open "
	        "gate one finds a yard, once there must have been a maticulusly maintained "
	        "yard. Flowerbeds, trimmed grass, flagstones. But now, there is nothing "
	        "but weeds as the forest slowly continues it's invasion."
	);
	
	set_items
	(
	        ([
	                "trail" : "Maybe you should follow it?",
		            "house" : "Maybe some crazy hermit?"
   			])
	);
	set_exits
	(([
		"east" : ROOMS"lforest5",
		"west" : ROOMS"lforest3"
		
	]));
}
