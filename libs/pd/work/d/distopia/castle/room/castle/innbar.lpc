#include <std.h>
#include <discastle.h>
inherit ROOM;

void create()
{
	::create();
	
	set_properties
	(
	        (["light" : 2, "night light" : 2, "inside" : 1])
	);
	set_short("The Bar");
	set_long
	(
		"The fire in the corner casts a cheerful glow on the deluge of patrons enjoying "
		"the fine eateries of the establishment, a roaring cheer goes up as the keeper "
		"announces another round of drinks on the house.  This is trully a great place "
		"to stay although more then a little crowded as there seems to be not another table "
		"to be seen. The menu can be seen on the wall and the peg board shows the rooms to rent by day or week."
	);
	set_smell("default", "The smell of all different sorts of food is everywhere.");
    set_listen("default", "The noise is deafening, but merry.");
	set_items
	(
	        ([
	                ({"board","peg board"}) : "All rooms are occupied",
	                "fire" : "snap crackle pop",
	        		"table" : "They are all taken!",
	        		"menu" : "Maybe you should read it?"
	        ])
	);
	set_exits
	(([
		"west" : ROOMS"innent",
                "stairs" :ROOMS"innsecfl",
		"east" :ROOMS"innkit"
	]));
}
void reset() 
{
	::reset();

	if(!present("inn keeper"))
	{
		new(MOB"innkeeper")->move(this_object());
	}
	if(!present("patron"))
	{
		new(MOB"patron")->move(this_object());
		new(MOB"patron")->move(this_object());
		new(MOB"patron")->move(this_object());
	}
	if(!present("drunk"))
	{
		new(MOB"drunk")->move(this_object());
		new(MOB"drunk")->move(this_object());
	}
	
}
