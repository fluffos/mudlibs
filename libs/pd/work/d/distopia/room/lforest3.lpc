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
	        "The trial is more worn in this part, indicating a heavy use. The forest "
	        "grows more distant to the south and there is something to the east, maybe "
	        "the trail leads there?"
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
		"east" : ROOMS"lforest4",
		"southwest" : ROOMS"lforest2"
		
	]));
}
