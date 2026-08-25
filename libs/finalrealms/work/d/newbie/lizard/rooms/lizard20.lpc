/* Added by Galvin 95-06-18 */
#include "path.h"
inherit ROOM+"baseroom";

void setup()  { my_setup();
set_short("Realm of the Lizard:  Musty Swamp");
set_light(60);
set_long("\nRealm of the Lizard:  Musty Swamp\n\n"
	 "     The dark swamp is all around you. Between the few trees to the"
         " north you glimpse a murky pond, but the heavy vegetation on "
         "the ground and the deceiving mist make further investigation "
         "impossible. A large swarm of insects pester you as you try "
         "to follow the slightly turning path. \n\n");
add_property("no_undead",1);
add_item("trees", "The trees are old and twisted. Large vines hang from"
         " the trees and seem to have a life of their own. \n\n");
add_item("vines", "Nasty vines hang from the trees and seem to move by "
         "themselves in a menacing way. \n\n");
add_item("vegetation", "The usual swamp vegetation, shrubs, weed and "
         "vines. They grow in great numbers in the swamp and close to "
         "the pond. \n\n");
add_item("insects", "These annoying insects can be found everywhere in "
         "these parts and you gave up trying to whisk them away a long "
         "time ago. \n\n");
add_item(({"weed","shrubs"}), "They seem to grow everywhere and especially "
         "where you walk. \n\n");
add_item(({"pond","water"}), "There's a huge pond of murky water to the "
         "north. The smell of stagnant water can be arduous for inexperienced"
         " adventurers. \n\n");
add_item("mist", "The mist is all around you and hampers your sight. "
         "But that's nothing unusual in these parts and you have lived "
         "with it for most of your life. \n\n");
add_item("ground", "It's an unfriendly place to walk on. \n\n");
add_item("path", "The path turns slightly and you have no idea where "
         "it will bring you. \n\n");
add_exit("west",SWAMP +"lizard19","room");
add_exit("southeast",SWAMP +"lizard23","room");
}
