#include "path.h"
inherit CITYROOM;

#define NUM 3

setup()
{
	set_light(100);
	set_short("Wall street");
	set_long("You are on Wall street. "+
"From here, you may enter the lovely Daggerford Post Office to the north, or "+
"proceed west to the tower of the Mystics...or just mosey "+
"down the street to the east.\n");
	add_exit("north",ROOM+"post", "door");
        add_exit("east", ROOM+"wall18a", "corridor");
	add_exit("west", ROOM+"tower4", "corridor");
	add_alias("post office", "post");
	add_alias("post-office", "post");
	add_item("post",
"It's a nice little post-office.  For some strange reason, people "+
"insist on calling it \"The Daggerford Post-Office\", "+
"but no one really knows why.\n");
	set_monster(NUM, "city");
	set_zone("city");
}
