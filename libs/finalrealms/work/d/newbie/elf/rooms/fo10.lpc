#include "path.h"
inherit FORESTROOM;


void setup()
{
 set_light(80);
 add_property("no_undead",1); set_short("Realm of the Elf:  High Forest");
set_long("\n   Realm of the Elf:  High Forest.\n\n"
         "     This looks like a peaceful well guarded part of the forest.  "
    "There are lots of strange beautiful plants around here. "
    "The elves must really take care of this part of the "
    "forest, and keep it free of goblins and other pests. "
    "The air is filled with smells of grass and flowers. "
"You hear birds singing their praise to nature. "
    "The trees are getting larger to the southeast. "
    "The track continues north and south from here. "
    "A small path turns off to the west away from the track."
    "\n\n");
 add_item("plants", "These plants are various in size and shape.  Although "
"most are only a couple of inches high, others have grown taller than you!\n");
add_smell("air", "These air smells just like the air of spring would smell. "
	  " You smell sents of red flowers, and green grass.\n");
add_item("path", "This path leads to the track to the west...Maybe you should"
	 "follow it.\n");

 add_exit("east", ROOM+"fo11", "road");
 add_exit("north", ROOM+"fo6", "road");
 add_exit("south", ROOM+"fo15", "road");
add_exit("west", ROOM+"center", "road");

 add_item("forest", "The forest seems to be inhabited by lots of wildlife. "
	"Everywhere you look, you see small animals moving.\n");
   
 set_zone("track"); 
}
