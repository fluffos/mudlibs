#include "path.h"
inherit ROOM+"baseroom";

void setup()  { my_setup();
set_short("Realm of the Lizard:  Musty Swamp");
set_light(60);
set_long("\nRealm of the Lizard:  Musty Swamp\n\n"
	 "     Since leaving the last clearing the forest is "
	 "returning back to it's original dark and sinister "
	 "self. Why anyone would come in here alone is a mystery "
	 "yet unsolved. The trees here are starting to look a "
	 "little more normal compared to the ones back in the "
	 "deeper parts of the swamp. You know, it almost seems " 
	 "as if there might be a town on down the road a little "
	 "ways. Who knows, this swamp has decieved and taken the life of many a "
	 "weary adventurers. \n\n");
add_property("no_undead",1);
add_item("trees", "The trees here are starting to like trees you "
	 "would find in a town. These aren't the gnarled and cruel "
	 "looking trees of the swamp. \n\n");
add_item("path", "The path you were following continues on down "
	 "the way. It looks a little more traveled than the part of "
	 "the path you have been following. \n\n");
add_exit("west",SWAMP +"lizard12","room");
add_exit("northeast",SWAMP +"lizard10","room");
}
