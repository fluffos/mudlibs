#include "path.h"

inherit FORESTROOM;

#define NUM 2

void setup()
{
 set_light(80);
 add_property("no_undead",1); set_short("Realm of the Elf:  High Forest");
set_long("\n   Realm of the Elf:  High Forest.\n\n"
    "     This looks like a peaceful well guarded part of "
    "the forest. The elves must really take care of this part of the "
    "forest, and keep it free of goblins and other pests.\n"
    "     The air is filled with sweet scent of "
    "grass and flowers. You hear birds singing their praise to nature."
    "  The trail turns south and west into the "
    "forest. Some small paths leads further into the forest to the east "
    "and north."
    "\n\n");

 add_exit("east", ROOM+"fo9", "road");
 add_exit("west", ROOM+"fo7", "road");
 add_exit("north", ROOM+"fo4", "road");
 add_exit("south", ROOM+"fo13", "road");

 add_item("forest", "The forest seems to be inhabited by lots of wildlife. "
	"Everywhere you look, you see small animals moving.\n");
 
 set_zone("track");
}
