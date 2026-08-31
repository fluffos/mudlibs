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
	set_short("Hallway");
	set_long
	(
		"The floors creek as they are stepped upon. This is the small upstairs "
		"hallway, it leads to the bathroom and the bedroom..or it should. It looks like "
		"something collapsed burying both rooms."
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
		"stairs" : ROOMS"hden"
	]));
}
