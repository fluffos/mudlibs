#include "path.h"
inherit CITYROOM;

#define NUM 3

setup()
{
set_light(100);
set_short("Crossroads");
set_long("You are at the crossroads between the southward-going "+
 "Tanner's Way and the eastward-going Hill Road. To your west is "+
 "Duke's road. To the north is the broad side of a bright temple, "+
 "and beyond it is the Ducal Castle.\n");
add_exit("south",ROOM+"tanner4", "road");
add_exit("east", ROOM+"hill2", "road");
add_exit("west", ROOM+"duke4", "road");
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
