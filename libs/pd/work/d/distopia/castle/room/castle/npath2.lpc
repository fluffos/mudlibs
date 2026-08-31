#include <std.h>
#include <discastle.h>
inherit ROOM;
void create()
{
	::create();
	
	set_properties
	(
	        (["light" : 2, "night light" : 1, "road" : 1])
	);
	set_short("Road out of Lodos.");
	set_day_long
	(
"The castle rises to the north, the tall pavilions rising up high and proud "
	        "in the sunlight. To the south the odd and all together spooky dias floats on "
	        "a pallet of air.  This road leads to the kingdom of Distopia, but because of the "
	        "current state of affairs the merchants that once led the great parade to the capital "
	        "have become sparse and paranoid."
	);
    set_listen("default", "Silence.");
	set_night_long
	(
		"A scant and beat looking row of torches line the way north to the capital of Distopia. "
		"the tall, majestic spires of the castle are not visable at this time of day but stars "
		"and the small light from the torches make the road visable... barely.  To the South is "
		"the dias, as creepy as ever."
	);
	set_items
	(
	        ([
	                "castle" : "It looks beautiful",
	                "pavelions" : "They are so huge",
	                "dias" : "It's so strange. You can't get over it",
	                "debris" : "Pieces of wood line the road everywhere. It looks like they were broken through."
	        ])
	);
	set_exits
	(([
		"north" : ROOMS"npath3",
		"south" : ROOMS"npath1"
	]));
}
void reset() 
{
	::reset();
	if(!present("corpse"))
	{
		new(ITEMS"corpse")->move(this_object());
	}
}
