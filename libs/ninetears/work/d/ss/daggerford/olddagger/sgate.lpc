#include "path.h"
inherit CITYROOM;

#define NUM 1

object guard;

void setup()
{
	set_light(100);
	set_short("City Gates");
	set_long(
"You are at the southern gate of Daggerford.  You can go north from "+
"here into Daggerford, or out into the wilderness. Far to the east you notice "+
"some mountains. From somewhere south of here wafts the smell of a swamp.\n");

	add_exit("north", ROOM+"wall1", "road");
	add_exit("out", OUTSIDE + "daggerford", "gate");

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
