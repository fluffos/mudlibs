#include "path.h"
inherit CITYROOM;

#define NUM 3

setup()
{
set_light(100);
set_short("Duke's Way");
set_long("You are on Duke's Way. The way continues to the north "+
 "and south. To the west is the River Shining Tavern. Far to the north "+
 "you notice a castle.\n");
add_exit("north",ROOM+"duke3", "road");
add_exit("south",ROOM+"duke1", "road");
add_exit("west",ROOM+"shining", "door");
add_item("castle",
 "It's a three-story stone keep, surrouded by "+
 "a two-story stone wall on a hillside.\n");
add_alias(({"river shining","river shining tavern","shining"}), "tavern");
add_item("tavern",
 "The River Shining Tavern is an old-fashioned and VERY stylish tavern "+
 "rumor goes even the Duke and his lovely sister eat there from time to "+
 "time. This place is only frequented by most noble and influential "+
 "of the citizens of Daggerford.\n");

set_monster(NUM, "city");
set_zone("city");
}
