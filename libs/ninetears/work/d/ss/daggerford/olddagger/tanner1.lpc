#include "path.h"
inherit CITYROOM;

#define NUM 3

setup()
{
 set_light(100);
 set_short("Tanner's Way");
 set_long("You are on Tanner's Way. "+
 "Tanner's Way continues east, and Duke's Way leads off to the north. "+
 "To the west you hear the sound of a market place.\n");
 add_exit("north", ROOM+"duke1", "road");
 add_exit("east", ROOM+"tanner2", "road");
 add_exit("west", ROOM+"market3", "road");
 set_monster(NUM, "city");
 set_zone("city");
}
