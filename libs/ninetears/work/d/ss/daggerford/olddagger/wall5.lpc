#include "path.h"
inherit CITYROOM;

#define NUM 3

setup()
{
	set_light(100);
	set_short("Wall street");
	set_long("You are on Wall street.\n "+
	 "The Temple of Tempus is to the northwest. Wall street follows the "+
	 "city-walls to the north and south.\n");
	add_exit("west",ROOM+"tempus", "door");
	add_exit("north", ROOM+"egate", "road");
	add_exit("south", ROOM+"wall4", "road");
	add_alias("temple", "tempus");
	add_alias("temple of tempus", "tempus");
	add_item("tempus",
	 "The stonewalled temple looks like it's ready to stand against any siege.\n");
	set_monster(NUM, "city");
	set_zone("city");
}
