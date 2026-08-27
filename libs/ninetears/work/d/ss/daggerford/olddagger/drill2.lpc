#include "path.h"
inherit CITYROOM;

#define NUM 1

object guard;

void setup()
{
	set_light(80);
	set_short("Drill field");
	set_long("You are on the northern end of the drill field. "+
	"Tanner's way is to the west and the drill field continues "+
	 "south. To the northeast is the shrine of Tempus, the warrior-God,"+
	 "which serves as combination of cleric's and fighter's guild. "+
	 "To the north you see a smithy.\n");

	add_exit("south", ROOM+"drills", "road");
	add_exit("east", ROOM+"tempus","door");
	add_exit("north", ROOM+"smithy", "door");
	add_exit("west", ROOM+"tanner2", "road");

	add_item("barracks", "Large building that houses the Militia.\n");
	add_alias("field", "drill");
	add_alias("drill field", "drill");
	add_item("drill", "Just a dusty field to practise fighting on.\n");
	add_alias(({"temple", "temple of Tempus"}), "tempus");
add_item("tempus", "A shine built of solid stonework. It is a "+
               "formidable building which can stand against any "+
                "conventional attack.\n");
	add_item("smithy", "Derval's Smithy. It's run by a highly respectable "+
	 "dwarf. You can buy or sell expensive weapons and armor here.\n");
	set_zone("city");
	set_monster(NUM, "city");
}

void reset()
{
	::reset();
	if(!guard)
	{
		guard=clone_object(CHAR+"cityguard");
		guard->move(this_object());
	}
}
