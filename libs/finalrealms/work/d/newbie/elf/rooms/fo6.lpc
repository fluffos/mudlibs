#include "path.h"
inherit FORESTROOM;

#define NUM 2

void setup()
{
 set_light(80);
 add_property("no_undead",1); set_short("Realm of the Elf:  Deep in the High Forest");

set_long("\n   Realm of the Elf:  Deep in the High Forest.\n\n"
         "     This looks like a very gloomy and unsecure part of the "
         "forest.  There are a lot of large trees and dense bushes around "
         "here."
         "\n\n");

 add_exit("west", ROOM+"fo5", "road");
 add_exit("south", ROOM+"fo10", "road");

 add_item("forest", "The forest seems to be inhabited by lots of wildlife. "
	"Everywhere you look, you see small animals moving.\n");

/* set_monster(NUM, "forest");*/
 set_zone("track");
}
