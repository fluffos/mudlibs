/* Added by Galvin 95-05-15 */
#include "path.h"
inherit ROOM+"baseroom";

void setup()  { my_setup();
set_short("Realm of the Lizard:  Musty Swamp");
set_light(60);
set_long("\nRealm of the Lizard:  Musty Swamp\n\n"
	"     The mist clears a bit and you find yourself in a small clearing "
         "surrounded by twisted trees. A few shrubs grow here and the "
         "abscence of weed and roots make it a lot easier to follow the path."
         " To the northwest you think you can see a large pond but the mist "
         "harasses your sight. A quicksand hinders all movement to the "
         "northwest so you can't find out for sure. \n\n");
add_property("no_undead",1);
add_item("trees", "Twisted trees without the usual swampmoss and vines. \n\n");
add_item("shrubs", "Small shrubs that grow randomly in the clearing. \n\n");
add_item("pond", "There's definitely some kind of pond to the northwest. "
         "The smell of murky water certainly verifies that. \n\n");
add_item("mist", "The mist here isn't as striking as usual. You can almost "
         "see beyond the first row of trees. \n\n");
add_item("path", "The path turns slightly to pass a small quicksand. \n\n");
add_item("quicksand", "The quicksand covers a small area here, blocking all "
         "movement to the northwest. \n\n");
add_exit("northeast",SWAMP +"lizard17","room");
add_exit("south",SWAMP +"lizard23","room");
}
