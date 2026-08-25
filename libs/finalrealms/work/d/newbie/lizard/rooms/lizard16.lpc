/* Added by Galvin 95-05-06 */
#include "path.h"
inherit ROOM+"baseroom";

void setup()  { my_setup();
set_short("Realm of the Lizard:  Musty Swamp");
set_light(60);
set_long("\nRealm of the Lizard:  Musty Swamp\n\n"
	 "     Here the swamp path forks into two directions. To the west you "
         "can discern some kind of building, while all the other directions "
         "are completely covered by the distorting mist. No trees can be seen"
         " around here and the ground is free of weed and roots. It looks "
         "like someone is trying to keep this part of the swamp under control"
         ". You smell a fire burning somewhere near. \n\n");
add_property("no_undead",1);
add_item("mist", "The mist seems to clear up a bit to the southeast, but it's"
         " still distorting every sound and shape. \n\n");
add_item("ground", "Someone has used a considerable amount of time to get it "
         "this clean from weed and roots. \n\n");
add_item("path", "The path is very easy to follow here, and the path to the "
         "west heavily used. \n\n");
add_item("building", "It looks like a little clay hut but you can't be to "
         "sure with the mist impairing your vision. \n\n");
add_exit("northwest",SWAMP +"lizard11","room");
add_exit("southeast",SWAMP +"lizard19","room");
add_exit("west",SWAMP +"lizard15","room");
}
