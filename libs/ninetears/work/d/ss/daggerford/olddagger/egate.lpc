#include "path.h"
inherit CITYROOM;

#define NUM 1

object guard;

void setup()
{
	set_light(100);
	set_short("City Gates");
	set_long(
"You are at the eastern gate of Daggerford.  You can go south or north from "+
"here to Wall Street, west to the disreputable River road or out into "+
"the wilderness. Far to the east you see a crossroads, and beyond it the "+
"peaks of a mountain range. From somewhere south of here wafts the smell of "+
"a swamp.\n");

	add_exit("south", ROOM+"wall5", "road");
	add_exit("north", ROOM+"wall6", "road");
	add_exit("west", ROOM+"river2", "road");
	add_exit("out", OUTSIDE, "gate");

	add_item("mountains",
		 "Although they are so far away, you can make out the white "+
		 "snowcaps on the tops of the highest peaks.\n");
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
	if(!guard)
	{
		guard=clone_object(CHAR+"cityguard");
		guard->move(this_object());
	}
}
