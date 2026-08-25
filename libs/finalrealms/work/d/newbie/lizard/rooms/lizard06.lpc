#include "path.h"
inherit ROOM+"baseroom";

void setup()  { my_setup();
set_short("Realm of the Lizard:  Musty Swamp");
set_light(60);
set_long("\nRealm of the Lizard:  Musty Swamp\n\n"
	 "     You find yourself deeper into the swamp. Those "
	 "creepy vines that were once sparsley placed are "
	 "now becoming too frequent to ignore. You think "
	 "you see the vines moving, in fact you know they are "
	 "moving. You should watch your step, these things could "
	 "hungry. Who knows, they could be man "
	 "eaters. \n\n");
add_property("no_undead",1);
add_item("vine","These things are moving around slowly. "
	 "They aren't moving toward you, YET! \n\n");
add_item("trees", "These trees are gnarled and deformed. "
	 "they look to be a perversion of nature itself. \n\n");
add_exit("east",SWAMP +"lizard07","room");
add_exit("northwest",SWAMP +"lizard02","room");
}
