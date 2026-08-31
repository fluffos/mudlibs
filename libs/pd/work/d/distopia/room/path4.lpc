#include <std.h>
#include <hermes.h>
inherit ROOM;
void create()
{
	::create();
	set_properties
	(
	        (["light" : 3, "night light" : 3, "forest" : 1])
	);
	set_short("Road to Distopia.");
	set_smell("default", "It almost smells like...fear.");
    set_listen("default", "The air is strangly silent except for a strange humming.");
	set_long
	(
	        "The forest has started to thin out. Here the path "
	        "encounters a fork and splits. There are now three "
	        "possible routs of travel.  One to the west, one to the "
	        "northeast, and one to the east... Or at least that should "
	        "have been the case.  The path to the east vanishes after "
	        "only a few meters in that direction leaving only the two "
	        "paths remaining. Not an animal to be seen, not a whisper in the wind. "
	        "For that matter, there is no wind. It's still here, "
	        "the animals clearly wishing to avoid this place. "
	        "It's also very bright. But where is the light source?"
	);
	set_items
	(
	        ([
	                "forest" : "The forest is tapering off.",
	                "path" : "You feel you're almost there",
	                "light" : "Try as you might, you can't tell where it's coming from.",
	        		"humming" : "Buzzzzz. It rattles your teeth and makes you very uncomfortable."
	        ])
	);
	set_exits
	(([
		"northeast" : ROOMS"path5",
		"west" : ROOMS"path3"
	]));
}
