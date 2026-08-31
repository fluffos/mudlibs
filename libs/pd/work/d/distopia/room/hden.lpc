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
	set_listen("default", "Silence");
	set_long
	(
		"Apparently this is, or was, the den. It is bare, almost completly stripped. Whoever was living "
		"here did not live in a life of comfort.  The only items that catch the eye is a small desk that sits "
		"near the stair case and a dusty, tattered book on top of it."
	);
	set_items
	(
	        ([
				({"floor", "floors", "wall", "walls"}) : "The oak is rotted. It looks in horrible shape.",
				"ceiling" : "If the walls are any indication, this place will probably collapse soon.",
				"book" : "What is it?",
				"desk" : "There is nothing inside it worth taking."
			])
	);
	set_exits
	(([
		"east" : ROOMS"hkitchen",
		"west" : ROOMS"hentrance",
		"stairs" : ROOMS"hhall"
		
	]));
}
void reset() 
{
	::reset();
	if(!present("journal")) 
new(ITEMS"journal")->move(this_object());
}
