#include "path.h"
inherit CITYROOM;

#define NUM 1

object merchant;

void setup()
{
	set_light(80);
	set_short("Market square");
	set_long(
"You are at the southern end of the market square. People are everywhere "+
"around you. There's a smithy to the west and a tavern to the east. "+
"Wall street is to the south and the market square continues north.\n");

	add_exit("north", ROOM+"market2", "road");
	add_exit("east", ROOM+"ladyluck","door");
	add_exit("south", ROOM+"wall20", "road");
	add_exit("west", ROOM+"smithy2","door");

	add_item("people",
		"They're milling around, pushing into you and making noise.\n");
	add_item("tavern", "You can't see much of it due to the crowd.\n");
	add_item("smithy", "You can't see much of it due to the crowd.\n");
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
