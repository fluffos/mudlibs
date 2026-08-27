#include "path.h"
inherit CITYROOM;

#define NUM 3

setup()
{
	set_light(100);
	set_short("Wall street");
        set_long("You are on Wall Street.  The post office lies just to the "+
                 "east, while Wall Street continues to follow the city walls, "+
                 "oddly enough, to the north and to the south.  To the south, "+
                 "you can just see one of the city watchtowers in the distance.\n");
	add_exit("east",ROOM+"post", "door");
	add_exit("north", ROOM+"wall16", "corridor");
	add_exit("south", ROOM+"tower4", "corridor");
	add_alias("post office", "post");
	add_alias("post-office", "post");
	add_item("post",
			"It's a nice little post-office named Daggerford Post-Office.\n");
	set_monster(NUM, "city");
	set_zone("city");
}
