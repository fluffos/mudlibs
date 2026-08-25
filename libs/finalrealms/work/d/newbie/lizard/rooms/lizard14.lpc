#include "path.h"
inherit ROOM+"baseroom";

void setup()  { my_setup();
set_short("Realm of the Lizard:  Musty Swamp");
set_light(60);
set_long("\nRealm of the Lizard:  Musty Swamp\n\n"
	 "     Since leaving the clearing, the swamp is starting to "
	 "turn into a more normal looking swamp. This path is "
	 "turning into more like a road. It may be leading to a "
	 "fairly good size city. These woods can be deceiving but "
	 "for some reason you have a strong feeling that you are "
	 "headed in the right direction, \n\n");
add_item("path", " The path here is begining to widen into an "
	 "actual road as opposed to a swampy path. \n\n");
add_item("trees", " The trees here are not like the twisted nasty "
	 "looking trees that are present in the deep part of the "
	 "swamp. \n\n");
add_property("no_undead",1);
add_exit("south",SWAMP +"lizard18","room");
add_exit("northwest",SWAMP +"lizard10","room");
}
