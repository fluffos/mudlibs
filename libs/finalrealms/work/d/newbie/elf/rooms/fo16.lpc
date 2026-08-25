#include "path.h"
inherit FORESTROOM;

#define NUM 2

void setup()
{
 set_light(80);
 add_property("no_undead",1); set_short("Realm of the Elf:  High Forest Edge");
set_long("\n   Realm of the Elf:  High Forest Edge.\n\n"
         "     You are close to the edge of the High Forest.  The "
         "trees are taller and the vegatation more dense to the west."
         "\n\n");

 add_exit("east", ROOM+"fo17", "road");
 add_exit("west", ROOM+"fo15", "road");
 add_exit("north", ROOM+"fo11", "road");
 add_exit("south", ROOM+"fo22", "road"); 
 add_item("forest", "The forest seems to be inhabited by lots of wildlife. "
	"Everywhere you look, you see small animals moving.\n");

add_item("trees", "These trees tower high above you.  They almost completely"
	 " block your view upward and to all the sides.  Maybe you should "
	 "continue on your way.\n");
add_item("vegatation", "This vegatation is so thick, it makes it hard for you"
	 " to walk.  Although the dense vegatation does make a good place for"
	 " animals to hide in.\n");
/* set_monster(NUM, "forest");*/   
 set_zone("track"); 
}
