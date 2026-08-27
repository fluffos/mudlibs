#include "path.h"
inherit CITYROOM;

#define NUM 3

setup()
{
set_light(100);
set_short("Duke's Way");
set_long("You are on Duke's Way before a sturdy gate. "+
 "The gate is closed at the moment, so you can't get in there. "+
 "There's a mighty temple to the east. The doors to the temple "+
 "are open.\n");
add_exit("south",ROOM+"duke4", "road");
add_exit("east", LATHANDER +"lath1", "door");
add_alias("ducal castle", "castle");
add_alias("ducal", "castle");
add_item("castle",
 "It's a three-story stone keep, surrouded by "+
 "a two-story stone wall. The gates are closed.\n");
add_alias("bright temple", "temple");
add_item("temple",
 "It's a cylindrically formed bright temple. It's also quite large for "+
 "a small town like Daggerford. It's doors are open.\n");

set_monster(NUM, "city");
set_zone("city");
}
