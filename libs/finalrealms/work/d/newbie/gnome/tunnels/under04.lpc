inherit "/std/room";
#include "path.h"

void setup ()   {
add_property("no_undead",1);
set_short("Realm of the Gnome:  Macedonian Tunnel");
set_light(40);
set_long("\nRealm of the Gnome:  Macedonian Tunnel\n\n"
	"     This part of the tunnels has also been mined, but it looks "
     "much neater than the part that you just left.  There is "
   "no left over rubble here and the walls appear quite "
    "smooth.  You can go back southwest and to the rubble or you can continue "
    "north or southeast.\n\n");
add_item(({"walls","wall","floor","ceiling"}),"The floors "
    "and the walls appear quite smooth and well worn as if they "
    "have been well mined.  It appears that the newbie/gnomes who used "
    "to work here have done their job well.\n\n");
add_exit("north",GNOME +"gnome17","path");
add_exit("southwest",UNDER +"under10","path");
add_exit("southeast",UNDER +"under11","path");
}
