#include "path.h"
inherit "/std/outside";

#define NUM 2

void setup()
{
 set_light(80);
 add_property("no_undead",1); set_short("Realm of the Elf:  High Forest");
set_long("\n   Realm of the Elf:  High Forest.\n\n"
         "     The air is filled with the sweet smells of "
    "grass and flowers. You hear birds singing their praise to nature.\n"
		"     You notice a particularly big tree in this part of the "
		"forest.  Your elven instinct tells you that there is "
                "something different about this tree."
                "\n\n");

 add_exit("west", ROOM+"fo8", "road");
 add_exit("north", ROOM+"fo5", "road");
	add_exit("up", ROOM+"treewalk2", "hidden");

add_item("tree", "You see a huge tree with a rarely used rope "
		"ladder leading up high into the branches above.  "
		"Perhaps you should go up and see what is "
		"in this tree.\n");
add_item("ladder", "This is an almost invisible rope ladder.\n");
add_item("up", "You can't see much through the foilage.\n");

 add_item("forest", "The forest seems to be inhabited by lots of wildlife. "
	"Everywhere you look, you see small animals moving.\n");
/* set_monster(NUM, "forest");*/
 set_zone("track");
}
