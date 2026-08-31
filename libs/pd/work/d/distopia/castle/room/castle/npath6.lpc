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
	set_short("Road to Distopia.");
	set_long
	(
		"At last, the yard of the tavern has been reached.  Music drifts towards the weary travler and a "
		"cheerful glow stands in stark contrast to the evil further west.  It feels different here, as if "
		"the evil that infected the rest of Distopia didn't invade this place of rest and solitude. "
		"Whatever it is, it is a welcome rest."
	);
	set_items
	(
	        ([
	                "tavern" : "Finally, you have reached it",
	                
	                "trees" : "They look beautiful likes this",
	        		"glow" : "The many candles give off a soft light"
	        ])
	);
	set_exits
	(([
		"west" : ROOMS"npath5",
		"enter" :ROOMS"innent"
	]));
}
void reset() 
{
	::reset();
	if(!present("inn"))
	{
	new(ITEMS"inn")->move(this_object());
	
	}
}
