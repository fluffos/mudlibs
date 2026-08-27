#include "path.h"
inherit CITYROOM;

#define NUM 3

setup()
{
 set_light(100);
 set_short("Tanner's Way");
 set_long("You are on Tanner's Way. "+
 "Tanner's Way continues west and north. You see a cloud of dust from "+
 "the east. Possibly it's from a drill field.\n");
 add_exit("north", ROOM+"tanner3", "road");
 add_exit("east", ROOM+"drill2", "road");
 add_exit("west", ROOM+"tanner1", "road");
 set_monster(NUM, "city");
 set_zone("city");
}
