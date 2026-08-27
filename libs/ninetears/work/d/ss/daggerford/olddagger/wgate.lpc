#include "path.h"
inherit CITYROOM;

#define NUM 1

object guard;

void setup()
{
	set_light(100);
	set_short("City Gates");
	set_long(
"You are at the western gate of Daggerford.  You can go south from "+
"here to Wall Street, east to Farmer's Way or out into the wilderness. "+
"Far to the west you see and hear the surf of the Sword Coast. "+
"From somewhere south of here wafts the smell of a swamp.\n");

	add_exit("south", ROOM+"wall15", "road");
	add_exit("east", ROOM+"farmer1", "road");
        add_exit("north", ROOM+"wall14", "road");
	add_exit("out", OUTSIDE, "gate");
	add_alias("sword coast", "coast");
	add_alias("surf", "coast");
	add_item("coast",
		 "You are too far away to see any details.\n");
	add_item("gate",
"This gate leads out of the city. In the far distance "+
"you can see some mountains.\n");

	add_item("swamp",
			"A dark swamp lies to the south, somewhere along the Sword Coast.\n");

	set_zone("city");

	set_monster(NUM, "city");
}

void reset()
{
	::reset();
        if(!present("cityguard"))
	{
		guard=clone_object(CHAR+"cityguard");
		guard->move(this_object());
	}
}
