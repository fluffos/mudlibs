#include "path.h"
inherit CITYROOM;

#define NUM 3

setup()
{
	set_light(100);
	set_short("Wall street");
	set_long("You are on Wall street. "+
		"To the north is the beginning of the market square. "+
                "From here, Wall Street follows the city's walls to the east and west.  "+
                "Just to the northeast stands the inviting shape of a Tavern, "+
                "while to the northwest a small armory awaits your call.\n");
	add_exit("north",ROOM+"market1", "door");
	add_exit("east", ROOM+"wall1", "road");
	add_exit("west", ROOM+"wall19", "road");
	add_alias("market square", "market");
	add_alias("square", "market");
	add_item("market",
		"It seems VERY busy with merchants and other people milling around.\n");
        add_item("tavern", "The Lady Luck tavern is easily the most popular "+
                "watering-hole and gathering place in the Realms.  You feel "+
                "hungry for some of Otik's Spiced Potatoes just from looking at it.\n");
        add_item("armory", "The Daggerford armory sells many useful items of "+
                 "both an offensive and defensive nature.  Get it, offensive?\n");
	set_monster(NUM, "city");
	set_zone("city");
}
