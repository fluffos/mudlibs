#include "path.h"
inherit CITYROOM;

#define NUM 3

setup()
{
set_light(80);
set_short("Landis Way");
set_long("You are on Landis Way.  Landis Way continues to the south "+
 "To the north the way ends by the gate to the Ducal Castle. "+
 "Up a hillside to the north and west you see a bright temple.\n");
add_exit("south",ROOM+"landis3", "road");
add_exit("east", ROOM+"hill1", "road");
add_exit("north", ROOM+"landis5", "road");
add_alias("ducal castle", "castle");
add_alias("ducal", "castle");
add_item("castle",
 "It's a three-story stone keep on a hillside, surrouded by "+
 "a two-storey stone wall.\n");
add_alias("bright temple", "temple");
add_item("temple",
 "It's a cylindrically formed bright temple. It's also quite large for "+
 "a small town like Daggerford.\n");

set_monster(NUM, "city");
set_zone("city");
}
