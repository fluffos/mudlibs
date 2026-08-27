#include "path.h"
inherit CITYROOM;

#define NUM 3

setup()
{
 set_light(100);
 set_short("Farmer's Way");
 set_long("You are on Farmer's Way. "+
	"This way continues to the east and south. "+
	"To the north is Happy Cow Tavern. Unfortunately it's closed at the "+
	"moment for rebuilding.\n");
 add_exit("south",ROOM+"farmer1", "road");
 add_exit("east", ROOM+"farmer3", "road");
 add_alias(({"happy cow","happy cow tavern"}), "tavern");
 add_item("tavern",
	"Closed for rebuilding, sorry!\n");
 set_monster(NUM, "city");
 set_zone("city");
}
