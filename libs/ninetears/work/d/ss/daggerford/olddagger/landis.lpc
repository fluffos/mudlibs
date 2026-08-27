#include "path.h"
inherit CITYROOM;

#define NUM 3

setup()
{
set_light(100);
set_short("Landis Way");
set_long("You are on Landis Way. The way continues to the north. "+
 "to the south is Tanner's Way, and you here sound of a market there. "+
 "Far to the north you can barely make out a castle.\n");
add_exit("north",ROOM+"landis2", "road");
add_exit("south",ROOM+"tanner1", "road");
add_item("castle",
 "It's a high stone keep, surrouded by "+
 "a stone wall, situated on a hillside.\n");
set_monster(NUM, "city");
set_zone("city");
}
