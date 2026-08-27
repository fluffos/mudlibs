#include "path.h"
inherit CITYROOM;

#define NUM 3

setup()
{
 set_light(100);
 set_short("Tanner's Way");
 set_long("You are on Tanner's Way. "+
 "Tanner's Way continues north and south. River Road leads off to the "+
 "east. Actually River Road is more of an alley than a road. You'd "+
 "better watch your step if you want to go in there after dark. "+
 "You see a tanner's shop to the west.\n");
 add_exit("north", ROOM+"tanner4", "road");
 add_exit("east", ROOM+"river1", "road");
 add_exit("south", ROOM+"tanner2", "road");
 add_exit("west", ROOM+"tannery", "door");
 set_monster(NUM, "city");
 set_zone("city");
 add_alias(({"tanner's", "tanner's shop", "tanner"}), "shop");
 add_item("shop", "It's Vic's Tannery, the shop this road is named after.\n"); 
}
