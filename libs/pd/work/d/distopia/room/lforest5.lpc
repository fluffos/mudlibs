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
	set_long
	(
	        "Finally, the trail ends... But it's just an old, run down house. The foundation "
	        "is cracked and overgrown, their are vines all along the house as the forest begins "
	        "to claim it as it's own.  There are cobweb cracks on the windows and the door swings "
	        "wide on rusty hinges inviting any who wished to enter."
	);
	set_items
	(
	        ([
				"trail" : "It lead to this house...",
				"foundation" : "This house is not going to last much longer.",
				"vines" : "The green vines surround the house, almost as if the forest grabbing it.",
				"door" : "It beckons..."
   			])
	);
	set_exits
	(([
		"west" : ROOMS"lforest4",
		"enter" : ROOMS"hentrance"
		
	]));
}
void reset() 
{
	::reset();
	if(!present("house")) 
	new(ITEMS"house")->move(this_object());
}
