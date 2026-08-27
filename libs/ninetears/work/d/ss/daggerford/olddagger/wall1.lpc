#include "path.h"
inherit CITYROOM;

#define NUM 3

setup()
{
set_light(100);
set_short("Wall street");
set_long("You are on Wall street. "+
	 "Lady Luck Tavern is to the north.  The southern gate is " +
	 "to the south.  Wall street follows the city-walls to the "+
	 "east and west.\n");
add_exit("south",ROOM+"sgate", "road");
add_exit("north",ROOM+"ladyluck", "door");
add_exit("east", ROOM+"wall2", "road");
add_exit("west", ROOM+"wall20", "road");
add_alias("lady luck", "tavern");
add_alias("lady luck tavern", "tavern");
add_alias("lady", "tavern");
add_item("tavern",
"This is the most popular meeting place in Daggerford. It's rumored "+
"to be a nice and noisy place with frequent bar brawls.\n");
set_monster(NUM, "city");
set_zone("city");
}
