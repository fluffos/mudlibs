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
	set_short("Kitchen");
	set_long
	(
		"The kitchen is in no better shape then any other part "
		"of the house. There is no apparent cookware anywhere. "
		"The old stove looks like it hasn't been used in months."
	);
	set_items
	(
	([
		({"floor", "floors", "wall", "walls"}) : "The oak is rotted. It looks in horrible shape.",
		"ceiling" : "If the walls are any indication, this place will probably collapse soon.",
		"stove" : "A wood burning stove... It is rusted through."
	])
	
	);
	set_exits
	(([
		"west" : ROOMS"hden"
	]));
}
