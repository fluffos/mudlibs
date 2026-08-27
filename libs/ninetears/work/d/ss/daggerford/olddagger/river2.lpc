#include "path.h"
inherit CITYROOM;

#define NUM 3

object thief;

void setup()
{
	set_light(50);
	set_short("River Road");
	set_long("You are on the disreputable River Road. It continues west, "+
	 "widening into a slightly wider alley, and east towards the river. "+
	 "It's quite dark here, and you "+
	 "see shadows dancing and running among the houses. To the south "+
	 "is some rubble and stones, with rats darting around in it.\n");

	add_exit("east", ROOM+"egate","road");
	add_exit("west", ROOM+"river1","road");
	add_exit("south", THIEVES+"thief","door");
	modify_exit("south", ({"message","N$N disappears south into the rubble.\n","obvious", 0}));
     add_item("alley",
	 "It looks dark and forbidding. Probably harbours many a crook.\n");
     add_alias("stones", "rubble");
     add_item("rubble", "Seems to just rubble, but if you're very interested "+
	 "in garbage you just might make your way through it.\n");
     set_zone("city");
     set_monster(NUM, "city");
}

void reset()
{
	::reset();
	if(!thief)
	{
		thief = (object)HOSPITAL->get_monster("thief");
		thief->move(this_object());
	}
}
