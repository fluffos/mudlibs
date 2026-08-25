#include "path.h"
inherit ROOM+"baseroom";

void setup()  { my_setup();
set_short("Realm of the Lizard:  Edge of Town");
set_light(60);
set_long("\nRealm of the Lizard:  Edge of Town\n\n"
	 "     You have come to the edge of town. You can feel the comfort of "
	"the swamp"
" calling to you. To the south is the town square"
", that also serves as a graveyard, since it is the only firm"
" ground for miles. To the west appears to be a run down shop of some kind. To the northeast the swamp seems to spread out before you.\n");
add_property("no_undead",1);
add_exit("south",SWAMP +"lizard26","room");
add_exit("west", SWAMP +"smithy","door");
add_exit("northeast",SWAMP +"lizard22","room");
}
