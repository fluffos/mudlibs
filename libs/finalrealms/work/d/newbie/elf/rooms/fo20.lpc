#include "path.h"
inherit FORESTROOM;


void setup()
{
 set_light(60);

add_property("no_undead",1); set_short("Realm of the Elf:  Deep in the High Forest");
 set_long("\n   Realm of the Elf:  Deep in the High Forest\n\n"
	 "     You are in the High Forest. The air is filled with smells of "
    "grass and flowers. You hear birds singing their praise to nature.\n"
    "There are a lot of large trees around here. There is less shrubbery "
    "to the north.\n");

 add_item("tree","The trees are covering the sky above you.\n");
 add_item("bush","The bushes are covering the view in all directions.\n");
 add_item("forest", "The forest seems to be inhabited by lots of wildlife. "
    "Everywhere you look, you see small animals moving.\n");

add_sound("birds", "CHIRP CHIRP\n");
add_smell("air", "The air smells like grass and flowers.\n");
 add_exit("west", ROOM+"fo19", "road");
 add_exit("east", ROOM+"fo21", "road");
 add_exit("north", ROOM+"fo14", "road");


/* A guard here?...... */
 set_zone("forest");
}
