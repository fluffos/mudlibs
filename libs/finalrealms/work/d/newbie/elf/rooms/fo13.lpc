#include "path.h"
inherit FORESTROOM;

#define NUM 2

void setup()
{
 set_light(80);
 add_property("no_undead",1); set_short("Realm of the Elf:  High Forest");
set_long("\n   Realm of the Elf:  High Forest.\n\n"
         "     You are in the High Forest.  The air is sweet with the "
         "scent of "
    "grass and flowers. You hear birds singing their praise to nature.\n"
         "     There are a lot of large trees around here.  There "
         "seems to be a lot less undergrowth to the west."
         "\n\n");

 add_exit("west", ROOM+"fo12", "road");
 add_exit("east", ROOM+"fo14", "road");
 add_exit("north", ROOM+"fo8", "road");

 add_item("forest", "The forest seems to be inhabited by lots of wildlife. "
	"Everywhere you look, you see small animals moving.\n");
add_smell("air", "You smell the sent of grass and flowers.\n");
add_sound("birds", "The birds are chirping..Like usual.\n");

 set_zone("track");
}
