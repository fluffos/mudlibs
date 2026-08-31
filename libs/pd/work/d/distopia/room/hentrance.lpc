#include <std.h>
#include <hermes.h>
inherit ROOM;
void create()
{
	::create();
	set_properties
	(
	        (["light" : 2, "night light" : 1, "indoors" : 1])
	);
	set_short("Entrance way");
	set_listen("default", "You hear a low growling.");
	set_long
	(
	        "The wide door frame allows just enough light to make out shapes. "
	        "The house is very run down, as was first thought, rotted wood floors "
	        "and walls make up the interior, who knows how bad the ceiling is. "
	        "A growl indicates that a wild animal had made this his shelter and perhaps "
	        "it wasn't wise to disturb him."
	);
	set_items
	(
	        ([
				({"floor", "floors", "wall", "walls"}) : "The oak is rotted. It looks in horrible shape.",
				"ceiling" : "If the walls are any indication, this place will probably collapse soon.",
			])
	);
	set_exits
	(([
		"east" : ROOMS"hden",
		"out" : ROOMS"lforest5"
		
	]));
}
void reset() 
{
	::reset();
	if(!present("bear")) 
	new(MOB"hbear")->move(this_object());
}
