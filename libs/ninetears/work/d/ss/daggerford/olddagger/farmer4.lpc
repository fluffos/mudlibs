#include "path.h"
inherit CITYROOM;

#define NUM 3

setup()
{
 set_light(100);
 set_short("Farmer's Way");
 set_long("You are on Farmer's Way. "+
	"This way continues to the west and east to Duke's Way. "+
	"To the south is the River Shining Tavern.\n");
 add_exit("west",ROOM+"farmer3", "road");
 add_exit("east", ROOM+"duke3", "road");
 add_exit("south", ROOM+"shining", "door");
 add_alias(({"river shining","river shining tavern"}), "tavern");
 add_item("tavern",
	"It seems to be a tavern for the upper class. Even nobility would "+
	"find this place more than good enough for their needs.\n");
 set_monster(NUM, "city");
 set_zone("city");
}
