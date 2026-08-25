inherit "/std/room";
#include "path.h"

void setup ()   {
add_property("no_undead",1);
set_short("Realm of the Gnome:  Macedonian Tunnel");
set_light(40);
set_long("\nRealm of the Gnome:  Macedonian Tunnel\n\n"
	 "     You continue to follow the stream through the tunnels. " 
   "The stalagtites and stalagmites seem to be getting longer and "
   "longer, almost resembeling huge teeth.  To go back you would have "
   "to go to either the east or west, but your curiosity to see where "
    "this stream leads urges you southward.\n\n");
add_item(({"stalagtites","stalagmites","stalagtite","stalagmite"}),"The "
   "stalagtites and stalalagmites resemble blunt teeth as they "
    "continue to grow in length.\n\n");
add_item(({"stream","brooke","river"}),"The stream continues to "
   "run along and pull a breeze through the passageway. "
    "The breeze is a bit chilly since the water in the stream "
    "is quite cool.\n\n");
add_exit("south",UNDER +"under14","path");
add_exit("east",UNDER +"under08","path");
add_exit("west",UNDER +"under06","path");
}
