#include "path.h"
inherit FORESTROOM;


void setup()
{
 set_light(60);

add_property("no_undead",1); set_short("Realm of the Elf:  High Forest Edge");

set_long("\n   Realm of the Elf:  High Forest Edge\n\n"
	 "     You are close to the edge of the High Forest. "
    "The trees are taller and the vegetation more dense to the west.\n");


 add_item("tree","The trees are covering the sky above you.\n");
 add_item("bush","The bushes are covering the view in all directions.\n");
 add_item("forest", "The forest seems to be inhabited by lots of wildlife. "
    "Everywhere you look, you see small animals moving around.\n");

 add_exit("west", ROOM+"fo21", "road");
 add_exit("north", ROOM+"fo16", "road");

 set_zone("forest");
}
