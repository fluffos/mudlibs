#include "path.h"
inherit FORESTROOM;

#define NUM 2

void setup()
{
 set_light(80);
 add_property("no_undead",1); set_short("Realm of the Elf:  High Forest");
set_long("\n   Realm of the Elf:  High Forest.\n\n"
         "     You are in the High Forest.  The air is sweet with the "
         "smell of grass and flowers.  You can hear the birds lifting "
         "their voices in song, seemingly in praise to nature.\n"
         "     There are a lot of very large trees around here.  To "
         "the west there seems to be less undergrowth than here."
         "\n\n");

 add_exit("west", ROOM+"fo14", "road");
 add_exit("east", ROOM+"fo16", "road");
 add_exit("north", ROOM+"fo10", "road");

 add_item("forest", "The forest seems to be inhabited by lots of wildlife. "
	"Everywhere you look, you see small animals moving.\n");

 set_zone("track"); 
}
