#include <std.h>
#include <hermes.h>
inherit ROOM;
void create()
{
	::create();
	set_properties
	(
	        (["light" : 3, "night light" : 3, "plains" : 1])
	);
	set_short("Road to Distopia.");
    set_listen("default", "The humming has stopped. Silence now.");
	set_long
	(
	        "This is the edge of the forest. There is an immediate "
	        "difference as one makes the transition from one edge "
	        "to the other. But wait, there is something strange "
	        "to the northeast..."
	);
	set_items
	(
	        ([
	                "forest" : "The forest is behind you.",
	                "path" : "You feel you're almost there",
	                "light" : "Try as you might, you can't tell where it's coming from.",
	        		"strnage" : "What is it?"
	        ])
	);
	set_exits
	(([
		"northeast" : ROOMS"nexus",
		"southwest" : ROOMS"path4"
	]));
}
