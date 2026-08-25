#include "path.h"
inherit "/std/room";
void setup(){
    set_light(50);
set_short("Realm of the Lizard:  Underwater Tunnel");
set_long("\nRealm of the Lizard:  Underwater Tunnel\n\n"
	 "     You have located a hidden underwater tunnel.  This tunnel"
             " is wide and smooth.  It sort of looks like it was dug,"
             " instead of being a natural tunnel.  There are a few"
             " small fish here, but no big ones.  This tunnel continues"
             " on to the northwest.\n");
   add_item("fish", "These are small fish.  They are not nearly big"
            " enough to eat.\n");
    add_item("tunnel", "This is a smooth walled tunnel.  It looks like"
             " it was dug out, so it must have some importance.\n");
    add_exit("out", UWATER+"uw09", "path");
    add_exit("northwest", UWATER+"uw11", "path");
}
