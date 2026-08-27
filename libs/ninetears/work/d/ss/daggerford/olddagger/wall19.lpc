#include "path.h"
inherit CITYROOM;

#define NUM 3

setup()
{
	set_light(100);
	set_short("Wall street");
	set_long("You are on Wall street. "+
					 "Cromach's smithy is to the north. Wall street follows the "+
					 "city-walls to the east and west.\n");
	add_exit("north",ROOM+"smithy2", "door");
	add_exit("east", ROOM+"wall20", "corridor");
        add_exit("west", ROOM+"wall18a", "corridor");
	add_alias("cromach's smithy", "smithy");
	add_alias("cromach's", "smithy");
	add_item("smithy",
			"Cromach's smithy is run by a human blacksmith. It's well "+
			"established, and offers a wide variety of useful goods.\n");
	set_monster(NUM, "city");
	set_zone("city");
}
