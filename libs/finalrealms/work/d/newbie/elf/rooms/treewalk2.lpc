#include "path.h"
inherit "/std/room";


void setup()
{
 set_light(100);
add_property("no_undead",1); set_short("Realm of the Elf:  Tree House");
set_long("\n   Realm of the Elf:  Tree House\n\n"
	"     This is the spacious home of an elf, obviously an elf who "
		"feels at home climbing around the branches of tall trees.  "
		"There is a small bed against one wall, and a training area "
		"in the center of the room.\n");

add_item("bed","This is the comfortable bed of whoever lives here.\n");
add_item("training_area","This is where the Treewalker teaches "
		"elven students his arts.\n");
 set_zone("cave");

 add_exit("down", ROOM+"fo9", "door");
   add_clone(CHAR+"treewalker",1);

}

