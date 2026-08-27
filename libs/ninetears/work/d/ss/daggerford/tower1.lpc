#include "path.h"
inherit CITYROOM;

#define NUM 1

object guard;

void setup()
{
	set_light(80);
	set_short("Southeast tower of Daggerford");
	set_long(
"You are below the southeast tower of Daggerford. Wall street continues "+
"to the west and north.\n");

	add_exit("north", ROOM+"wall4", "road");
	add_exit("west", ROOM+"ohall","road");

	add_item("tower",
		"It's a stone tower that's about 3 times higher than yourself. "+
		"it seems to have been build to stand against outside attacks.\n");

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
