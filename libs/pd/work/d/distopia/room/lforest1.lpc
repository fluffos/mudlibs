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
    set_listen("default", "Birds chirp, water runs. It's very soothing.");
	set_long
	(
	        "The dias gradually disappears as the path to the forest is forged. "
	        "After a short time, the outskirts are reached and to the south lies the first "
	        "of many thick trees that seem to strech on forever. Wait, what's that? There seems "
	        "to be a little trail to the east, just skirting the end of the forest. Where does "
	        "it lead?"
	);
	set_items
	(
	        ([
	                "dias" : "So many questions... Where are you? Who made this? It's flawless, smooth, brilliant.",
	                "trail" : "Maybe you should follow it?",
		            "forest" : "It looks spooky..."
   			])
	);
	set_exits
	(([
		"east" : ROOMS"lforest2",
		"southwest" : ROOMS"nexus",
		"southeast" : ROOMS"forest2",
		"south" : ROOMS"forest1"
	]));
}
