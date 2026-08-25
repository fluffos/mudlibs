inherit "/std/room";
#include "path.h"

void setup ()   {
add_property("no_undead",1); 
set_short("Realm of the Gnome:  Macedonian Tunnel");
set_light(40);
set_long("\nRealm of the Gnome:  Macedonian Tunnel\n\n"
	 "     This room is long and appears to be in a cylindar type shape "
"Much like someone took a tube and just hollowed out this tunnel. "
"The walls are of packed earth, and seem very dry.  This tunnel is just "
"big enough for you to stand in, but that is about it. Although "
"the walls appear to get slightly damp to the southeast, and seem to "
"stay quite dry to your north and south.\n\n");
add_item(({"wall","walls","ceiling","floor"}),"The walls and "
"ceiling here are kinda mixed as far as dryness goes.  To the north "
"and south they appear to be quite dry, but as you look to the "
"southeast they seem to become damp.\n\n");
add_exit("south",UNDER +"under17","path");
add_exit("north",UNDER +"under06","path");
add_exit("southeast",UNDER +"under18","path");
}
