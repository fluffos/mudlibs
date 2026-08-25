#include "path.h"
inherit FORESTROOM;
#define NUM 2

void setup()
{
 set_light(60);

 add_property("no_undead",1); set_short("Realm of the Elf:  Gloomy Forest, Clearing");
set_long("\n   Realm of the Elf:  Gloomy Forest, Clearing.\n\n"
         "     You feel as if you are getting close to the evil in "
		 "these woods. Since you left the last clearing the "
		 "feeling of dread is increasing. If you do find the "
		 "heart of these woods, you get the feeling it will not be a very good "
		 "idea to be here even with greatest of weapons armour. \n\n");

add_sound("birds","You wonder why you can't hear any birds. "
		"Perhaps the birds know something you don't.\n");
add_item("tree","The trees are black and twisted.  They seem "
		"to be a perversion of nature.\n");
add_item("sky","You long for a view of the blue sky but alas, "
		"the thick foilage is denying you of even that respite.\n");
add_item("ground","The ground is covered by twisted roots.\n");
add_item("forest","The forest ominously looms around you.\n");

add_exit("southeast", GLOOM+"dfo4b", "road");
add_exit("southwest", GLOOM+"dfo3c", "road");
add_exit("northeast", GLOOM+"dfo5c", "road");
 set_zone("forest");
   add_clone(CHAR+"wood_imp",1+random(2));
}

