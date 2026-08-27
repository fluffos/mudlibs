#include "path.h"
inherit CITYROOM;

#define NUM 3

setup()
{
	set_light(100);
	set_short("Wall street");
	set_long("You are on Wall street. "+
	 "Wall street follows the city-walls to the south, and Hill Road follows "+
	 "a hill westwards.\n");
	add_exit("west", ROOM+"hill2", "road");
	add_exit("south", ROOM+"wall6", "road");
	set_monster(NUM, "city");
	set_zone("city");
}
