#include "path.h"
inherit CITYROOM;

#define NUM 1

object guard;

void setup()
{
	set_light(80);
	set_short("Drill field");
	set_long("You are on the southern end of the drill field. "+
	"Wall street is to the south and the drill field continues "+
	 "north. To the east are the barracks which serves as fighters guild.\n");

	add_exit("north", ROOM+"drills", "road");
	add_exit("east", FIGHTER+"barracks","door");
	add_exit("south", ROOM+"wall3", "road");

	add_item("barracks", "Large building that houses the Militia.\n");
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
