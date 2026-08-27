#include "path.h"
inherit CITYROOM;

#define NUM 3

setup()
{
 set_light(100);
 set_short("Farmer's Way");
 set_long("You are on Farmer's Way. "+
	"This way leads further north towards a tavern. "+
	"To the south is Market Way, and to the west is Wall Street.\n");
 add_exit("north",ROOM+"farmer2", "road");
 add_exit("south", ROOM+"mark2", "road");
 add_exit("west", ROOM+"wgate", "road");
 add_item("tavern",
	"The sign up front seems to say: Happy Cow.\n");
 set_monster(NUM, "city");
 set_zone("city");
}
