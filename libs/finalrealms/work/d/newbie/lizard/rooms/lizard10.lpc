#include "path.h"
inherit ROOM+"baseroom";

void setup()  { my_setup();
set_short("Realm of the Lizard:  Musty Swamp");
set_light(60);
set_long("\nRealm of the Lizard:  Musty Swamp\n\n"
	 "     This place is a little different looking than the "
	 "rest of the swamp. This is a clearing with few trees "
	 "and none of those weird looking vines. You can see that the "
	 "path stops here and leaves in two opposite directions "
	 "other than the way you came. On down the path it becomes "
	 "darker, not like your everyday swamp. Maybe this path leads "
	 "to somewhere important, but which way to go? You should watch your "
	 "back this place is becoming more sinister with every step. "
	 "\n\n");
add_property("no_undead",1);
add_item("trees","The trees here are few and far between. The ones "
	 "that are here look like perversions of nature. \n\n");
add_item("path","This path leads off to the Southeast and the "
	 "southwest. It looks like it may lead somewhere important, but "
	 "where? Only one way to find out! \n\n");
add_exit("north",SWAMP +"lizard08","room");
add_exit("southwest",SWAMP +"lizard13","room");
add_exit("southeast",SWAMP +"lizard14","room");
}
