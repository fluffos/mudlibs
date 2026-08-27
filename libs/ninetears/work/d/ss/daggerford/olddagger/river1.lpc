#include "path.h"
inherit CITYROOM;

#define NUM 2

object thief;

void setup()
{
set_light(50);
set_short("River Road");
set_long("You are on the disreputable River Road. It continues east, "+
 "narrowing into an ever darker alley, and west towards Tanner's Road. "+
 "It's quite dark here, and you realize this is not among the safest places "+
 "you could be. You notice some stones and other rubble.  There is a pawnshop "+
 "to the north and some dark stairs to the south.\n");

add_exit("east", ROOM+"river2","road");
add_exit("west", ROOM+"tanner3","road");
add_exit("north", ROOM+"pawnshop","door");
add_exit("south", ROOM+"gambling","door");
modify_exit("north",({"message","N$N ducks into the pawnshop to the north.\n"}));
add_item("alley",
 "It looks dark and forbidding. Probably harbours many a crook.\n");
add_alias("stones", "rubble");
add_item("rubble", "Seems to just rubble.\n");
add_item("stairs", "You'd probably be safer down here. You might be eaten by "+
 "by a grue up there. It's dark, and some rude voices drift down here.\n");
set_zone("city");
set_monster(NUM, "city");
}

void reset()
{
	::reset();
	if(!thief)
	{
		thief=(object)HOSPITAL->get_monster("thief");
		thief->move(this_object());
         }
}
