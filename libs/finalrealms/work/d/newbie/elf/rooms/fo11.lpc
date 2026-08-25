#include "path.h"
inherit FORESTROOM;


void setup()
{
 set_light(60);

 add_property("no_undead",1); set_short("Realm of the Elf:  High Forest Edge");
set_long("\n   Realm of the Elf:  High Forest Edge.\n\n"
         "     You are close to the edge of the High Forest.  The "
         "trees are taller and the vegitation more dense to the west."
         "\n\n");

 add_item("tree","The trees are covering the sky above you.\n");
 add_item("vegetation","The vegetation to the west consists of scrubbery, "
    "and tall trees.\n");
 add_item("forest", "The forest seems to be inhabited by lots of wildlife. "
    "Everywhere you look, you see small animals moving around.\n");

 add_exit("west", ROOM+"fo10", "road");
 add_exit("south", ROOM+"fo16", "road");
 
}
