#include "path.h"
inherit FORESTROOM;

#define NUM 2

void setup()
{
 set_light(80);
 add_property("no_undead",1); set_short("Realm of the Elf:  High Forest Center");
set_long("\n   Realm of the Elf:  High Forest Center.\n\n"
         "     You are standing in the center of the High Forest.  "
         "There "
        "are a lot of enormous trees around here. "
        "There are some signs of elven habitation in this area. "
        "The air is filled with the sweet "
        "smells of grass and flowers. "
          "You hear birds singing their praise to nature."
          "\n\n");

 add_exit("west", ROOM+"fo13", "road");
add_exit("east",ROOM+"fo15", "road");
	add_exit("south",ROOM+"fo20","road");

 add_item("trees", "The large trees are circleing the clearing. "
	"They're some of the largest trees you're ever seen.\n");
 add_item("building", "It's a beautiful elfin made building.\n");
add_item("path", "The path seems to lead into an Elvin village.\n");

add_item("signs", "there are various signs of elven inhabitation around.  "
	  "To your left, you see an old building that a elf must have lived "
	  "in for a long time.\n");
add_smell("air", "The air smells like the sent of spring...  The green grass"
	  ", and the red flowers.\n");
add_sound("birds", "The birds are chirpping like any bird would.\n");
/* set_monster(NUM, "forest");*/   
 set_zone("forest");
}
