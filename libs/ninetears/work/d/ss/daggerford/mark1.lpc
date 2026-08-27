#include "path.h"
inherit CITYROOM;

#define NUM 3

setup()
{
 set_light(60);
 set_short("Market Way");
 set_long("You are on Market Way. "+
	"You are on Market Way, which continues to the west and to the market "+
	"square to the east. To the north lies Daggerford Bank.\n");
	add_exit("north",ROOM+"bank", "door");
	add_exit("east", ROOM+"market3", "road");
	add_exit("west", ROOM+"mark2", "road");
	add_alias("daggerford bank", "bank");
	add_item("bank",
	 "Daggerford bank is a VERY safe place to deposit money, judging by "+
	 "the thick stone walls. The building looks like a place for the rich.\n");
	add_alias("market square", "market");
	add_alias("square", "market");
	add_item("market",
		"It seems VERY busy with merchants and other people milling around.\n");

	set_monster(NUM, "city");
	set_zone("city");
}
