#include "path.h"
inherit FORESTROOM;

#define NUM 2

void setup()
{
 set_light(80);
 add_property("no_undead",1); set_short("Realm of the Elf:  High Forest");
set_long("\n   Realm of the Elf:  High Forest.\n\n"
         "     You are in the High Forest.  The air is sweet with the "
         "smell of grass and flowers.  You can hear a multitude of "
         "birds raising their voice seemingly in praise of nature.\n"
         "     There is a sign next to the path."
         "\n\n");

 add_exit("east", ROOM+"exit", "road");
 add_exit("west", ROOM+"fo16", "road"); 


add_sign("This small sign has a message written upon it in beautiful "
         "elven script:\n\n"
         "     \"This way to the outside world.\"\n");
 add_item("woodpecker", "The woodpecker is banging it's head quicklike "
        "into the tree.\n");
add_smell("air", "The air smells sweet like the fresh spring air.  It has "
	  "the smell of flowers, and many other good smelling things.\n");
add_sound("birds", "These birds sound like normal chirping birds on a sunny "
	  "day.\n");
 add_item("forest", "The forest seems to be inhabited by lots of wildlife. "
	"Everywhere you look, you see small animals moving.\n");
 add_item("flowers", "The floor of the forest is covered by strange "
        "looking flowers.\n");
 add_item("tree", "There is a door in this tree.\n"); 
}
