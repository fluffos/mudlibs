#include "path.h"
inherit CITYROOM;

#define NUM 3

setup()
{
set_light(100);
set_short("Landis Way");
set_long("You are on Landis Way. The way continues to the north" +
"and south.  To the west is the Wandering Traveller Tavern. Far to the north "+
"you notice a castle.\n");
add_exit("north",ROOM+"landis3", "road");
add_exit("south",ROOM+"landis1", "road");
add_exit("west",ROOM+"shining", "door");
add_item("castle",
 "It's a three-story stone keep, surrouded by "+
 "a two-story stone wall on a hillside.\n");
add_alias(({"wandering traveller","wandering traveller tavern","wandering"}), "tavern");
add_item("tavern",
"The Wandering Traveller Tavern is true to its name, as it's clean "+
"and inviting atmosphere relaxes the weary bones of any adventurer. "+
"This place is often frequented by travellers passing on the stories of their "+
"amazing adventures.\n");

set_monster(NUM, "city");
set_zone("city");
}
