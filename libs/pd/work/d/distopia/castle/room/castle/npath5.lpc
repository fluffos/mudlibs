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
	set_day_long
	(
		"The road narrows here, becoming hard to follow and littered with falling leaves from the maple "
		"trees. The inn is in the distance to the east, coming closer with every step in that direction "
		"the brutal battlefield is back west, and travelers couldn't be happier to leave such an unholy "
		"place of death."
	);
	set_night_long
	(
		"The cheerful glow from the tavern provides a constant and reassuring light source towards civilization "
		"as the way is made in the dark and unforgiving night, one can not help but feel relief to be away from the "
		"battlefield to the west.  At this distance a cheerful music drifts towards one, making them feel eager to "
		"be part of the crowd to listen"
    );
	set_items
	(
	        ([
	                "taver" : "You can't wait to get there",
	                "inn" : "You are getting closer",
	                "trees" : "They look beautiful likes this",
	        ])
	);
	set_exits
	(([
		"east" : ROOMS"npath6",
		"west" : ROOMS"npath4"
	]));
}
void reset() 
{
	::reset();
	if(!present("bandit"))
	{
		new(MOB"bandit")->move(this_object());
		new(MOB"bandit")->move(this_object());
	
	}
}
