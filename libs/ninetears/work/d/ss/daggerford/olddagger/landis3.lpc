#include "path.h"
inherit CITYROOM;

#define NUM 3

setup()
{
set_light(100);
set_short("Landis Way");
set_long("You are on Landis Way.  The way continues to the north "+
"and south.  To the west is Farmer's Road.  Far to the north you see "+
"The Ducal castle and a large temple.\n");
add_exit("north",ROOM+"duke4", "road");
add_exit("south,ROOM+"duke2", "road");
add_exit("west",ROOM+"farmer4", "road");
add_alias("ducal castle", "castle");
add_alias("ducal", "castle");
add_item("castle",
 "It's a three-story stone keep, surrouded by "+
 "a two-story stone wall on a hillside.\n");
add_alias("bright temple", "temple");
add_item("temple",
 "It's a cylindrically formed bright temple. It's also quite large for "+
 "a small town like Daggerford.\n");

set_monster(NUM, "city");
set_zone("city");
}
