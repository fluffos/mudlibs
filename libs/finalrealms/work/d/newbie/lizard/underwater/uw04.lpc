#include "path.h"
inherit "/std/room";
void setup(){
    set_light(50);
set_short("Realm of the Lizard:  Underwater");
set_long("\nRealm of the Lizard:  Underwater\n\n"
	 "     As you continue through this ancient underwater"
             " civilization, you see what appears to be a few stray"
             " bones lying around.  There are also many different fish"
             " and many different types of plant life growing around"
             " these decaying buildings.\n");
    add_item(({"buildings", "decaying buildings"}), "These decaying"
             " buildings are but a mere pile of junk now.  At once they"
             " were probably very fine craftsmanship.\n");
    add_item("bones", "These are just regular looking fish bones.\n");
    add_item("fish", "Several different types of multi-colored fish"
             " have taken over this place.\n");
    add_exit("east", UWATER+"uw02", "path");
    add_exit("north", UWATER+"uw03", "path");
    add_exit("south", UWATER+"uw05", "path");
    add_exit("northwest", UWATER+"uw07", "path");
    add_exit("west", UWATER+"uw08", "path");
    add_exit("southwest", UWATER+"uw09", "path");
}
