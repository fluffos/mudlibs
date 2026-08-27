#include "path.h"
inherit CITYROOM;

#define NUM 3

setup()
{
 set_light(100);
 set_short("Market Way");
 set_long("You are on Market Way. "+
	"You are on Market Way, which leads to the market square to the "+
	"east. Farmer's Way leads off to the north, and to the west is Wall "+
	"Street. To the south is Daggerford Money Changer.\n");
 add_exit("north",ROOM+"farmer1", "road");
 add_exit("east", ROOM+"mark1", "road");
 add_exit("west", ROOM+"wall15", "road");
 add_exit("south", ROOM+"changer", "door"); 
 add_alias("daggerford bank", "bank");
 add_alias("market square", "market");
 add_alias("square", "market");
 add_item("market",
	"It's always VERY busy with merchants and other people milling around.\n");
 add_alias("money changer", "changer");
 add_item("changer", "It seems to be a place where you can exchange your "+  
   "money into lighter currency.\n");
 set_monster(NUM, "city");
 set_zone("city");
}
