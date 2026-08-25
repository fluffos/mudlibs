#include "path.h"
inherit "/std/room";
void setup(){
    set_light(50);
set_short("Realm of the Lizard:  Underwater");
set_long("\nRealm of the Lizard:  Underwater\n\n"
	 "     As you continue to swim through this ancient underwater"
             " civilization, you begin to wonder just how long can you"
             " breath down here, forever?  You see decaying structures"
             " inhabited with fish all to the northwest.\n");
    add_item(({"decaying structures", "structures"}), "These old"
               " buildings are almost nonexistant because they have"
               " almost decayed into the soil.\n");
   add_exit("northeast", UWATER+"uw02", "path");
    add_exit("north", UWATER+"uw04", "path");
    add_exit("northwest", UWATER+"uw08", "path");
    add_exit("west", UWATER+"uw09", "path");
}
