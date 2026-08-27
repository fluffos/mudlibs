#include "path.h"
inherit CITYROOM;

#define NUM 1

setup()
{
 set_light(100);
 set_short("Wall Street");
 set_long(
"You are on Wall street.  The street continues to the east and west.\n"+
"To the north you see the drill grounds of Daggerford Militia. If one "+
"is to believe rumours they also train adventurers in the barracks "+
"for a certain EP fee.\n");

 add_exit("east", ROOM+"ohall", "road");
 add_exit("west", ROOM+"wall2", "road");
 add_exit("north", ROOM+"drill1", "road");

 add_alias("drill field", "drill");
 add_alias("field", "drill");
 add_item("drill",
"The drill field looks like the perfect place to train fighting skills.\n");

 set_zone("city");
 set_monster(NUM, "city");
}


