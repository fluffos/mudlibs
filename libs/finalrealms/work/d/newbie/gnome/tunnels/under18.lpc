inherit "/std/room";
#include "path.h"

void setup ()   {
add_property("no_undead",1); 
set_short("Realm of the Gnome:  Macedonian Tunnel");
set_light(40);
set_long("\nRealm of the Gnome:  Macedonian Tunnel\n\n"
	 "     As you enter this room, you think you can faintly hear "
"the sound of rushing water to your south. "
"You also notice that the room appears to be a bit damper than the "
"rooms prior to it, which are to your west and northwest.\n\n");
add_item(({"wall","walls","floor","ceiling"}),"The walls and ceiling "
"appear to be much damper than those of the room you just left. "
"In some spots you can see water dripping from the ceiling.\n\n");
add_item(({"wall","walls","floor","ceiling"}),"Again this "
"part of the tunnel is a metamorphosis of dryness to dampness.  "
"In some areas the damp dirt is all that holds this part of the tunnle up.\n\n");
add_exit("south",UNDER +"under20","path");
add_exit("west",UNDER +"under17","path");
add_exit("northwest",UNDER +"under13","path");
}
