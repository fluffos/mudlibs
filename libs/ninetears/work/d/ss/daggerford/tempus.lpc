#include "path.h"
inherit CITYROOM;

#define NUM 1

void setup()
{
	set_light(80);
	set_short("Tempus square");
	set_long("You are on Tempus Square.\n"+
      "You can see a drill field to the west and Wall Street is to the east. "+
      "To the north is the Temple of Tempus, the warrior-God, "+
      "which serves as combination of cleric's and fighter's guild.\n");

	add_exit("east", ROAD+"wall5","road");
	add_exit("north",TEMPUS +"temsteps", "road");
	add_exit("west", ROAD+"drill2", "road");

	add_alias("field", "drill");
	add_alias("drill field", "drill");
	add_item("drill", "Just a dusty field to practise fighting on.\n");
	add_alias(({"temple", "Temple of tempus"}), "tempus");
	add_item("tempus", "A shrine built solely og thick stonework. It "+
	 "would almost certainly stand against any conventional attack.\n");
	set_zone("city");
	set_monster(NUM, "city");
}

void reset()
{
	::reset();
}
