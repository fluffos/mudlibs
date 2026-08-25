#include "path.h"
inherit ROOM+"baseroom";

void setup()  { my_setup();
set_short("Realm of the Lizard:  Musty Swamp");
set_light(60);
set_long("\nRealm of the Lizard:  Musty Swamp\n\n"
	 "     You have ventured farther into the swamp. Despite "
	 "the fact that you are deeper into the swamp, it has "
	 "become a little less dense. Still no trees to speak "
	 "of but the foliage close to the ground has changed "
	 "a little. The upper level of the swamp has become "
	 "less dense but the foliage near the floor is growing "
	 "denser by the step. \n\n");
add_property("no_undead",1);
add_item("foliage", "These vines are creepy, they seem to "
	 "move on their own. As you walk they snatch at "
	 "your feet and legs. You should watch your step. \n\n");
add_item("trail", "The trail you were following is quickly "
	 "being enveloped by these strange vines. \n\n");
add_item("foliage", "The foliage here looks nothing like "
	 "the plant life from the other side of the swamp "
	 "where you're from. \n\n");
add_exit("west",SWAMP +"lizard01","room");
add_exit("southeast",SWAMP +"lizard06","room");
}
