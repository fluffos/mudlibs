#include "path.h"
inherit CITYROOM;

#define NUM 3

setup()
{
 set_light(100);
 set_short("Tanner's Way");
 set_long("You are on Tanner's Way. "+
 "Tanner's Way continues south. Hill Road leads off to the "+
 "north.\n");
 add_exit("north", ROOM+"hill1", "road");
 add_exit("south", ROOM+"tanner3", "road");
 set_monster(NUM, "city");
 set_zone("city");
}
