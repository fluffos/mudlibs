#include "path.h"
inherit CITYROOM;

#define NUM 1

object guard;

void setup()
{
	set_light(80);
	set_short("Drill field");
	set_long("You are in the middle of the drill field. "+
	 "The drill field continues to the north and south. The ground is "+
         "very dusty downtrodden here, as if fighting has been taking place "+
         "years after years.\n");

	add_exit("north", ROOM+"drill2", "road");
	add_exit("south", ROOM+"drill1", "road");

	add_alias("field", "drill");
	add_alias("drill field", "drill");
        add_item("drill", "Just a dusty field to practice fighting on.\n");

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
