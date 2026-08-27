#include "path.h"
inherit CITYROOM;

#define NUM 3

setup()
{
set_light(100);
set_short("Hill Road");
set_long("You are on Hill Road. Hill road continues to the west,  "+
 "and to the east is Wall Street. The stables lie to the north. "+
 "Northwest of here is the back of a bright temple, "+
 "and beyond it is the Ducal Castle.\n");
add_exit("north",ROOM+"stables", "door");
add_exit("east", ROOM+"wall7", "road");
add_exit("west", ROOM+"hill1", "road");
add_alias("ducal castle", "castle");
add_alias("ducal", "castle");
add_item("castle",
 "It's a three-story stone keep on a hillside, surrouded by "+
 "a two-story stone wall.\n");
add_alias("bright temple", "temple");
add_item("temple",
 "It's a cylindrically formed bright temple. It's also quite large for "+
 "a small town like Daggerford.\n");

set_monster(NUM, "city");
set_zone("city");
}
