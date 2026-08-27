#include "path.h"
inherit CITYROOM;

#define NUM 3

setup()
{
	set_light(100);
	set_short("Wall street");
	set_long("You are on Wall street. "+
	 "Wall street follows the city-walls to the north and south.\n");
	add_exit("north", ROOM+"wall15", "road");
	add_exit("south", ROOM+"wall17", "road");
	set_monster(NUM, "city");
	set_zone("city");
}
