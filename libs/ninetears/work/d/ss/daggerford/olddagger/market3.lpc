#include "path.h"
inherit CITYROOM;

#define NUM 1

object merchant;

void setup()
{
	set_light(80);
	set_short("Market square");
	set_long(
"You are at the northern end of the market square. People are everywhere "+
"around you. There's a shop to the north. Tanners' way goes eastward "+
"from here, and Market way goes west. The market continues south.\n");

	add_exit("south", ROOM+"market2", "road");
	add_exit("east", ROOM+"tanner1","road");
	add_exit("west", ROOM+"mark1", "road");
	add_exit("north", ROOM+"farrels","door");

	add_item("people",
		"They're milling around, pushing into you and making noise.\n");
	add_item("shop", "You can't see much of it due to the crowd.\n");
	add_item("street", "You can't see much of it due to the crowd.\n");
	add_alias("square", "market");
	add_alias("market square", "market");
	add_item("market", "Lots of people and merchants are milling around.\n");

	set_zone("city");
	set_monster(NUM, "city");
}

void reset()
{
	::reset();
	if(!merchant)
	{
	  merchant = (object)HOSPITAL->get_monster("merchant");
	  merchant->move(this_object());
	}
}
