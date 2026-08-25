#include "path.h"
inherit ROOM+"baseroom";

void setup()  { my_setup();
set_short("Realm of the Lizard:  Town Gates");
set_light(60);
set_long("\nRealm of the Lizard:  Town Gates\n\n"
	 "     A large open gate stands before you, neatly embedded in the "
         "high wooden palisade that encircles the village. To the west a "
         "watchtower rests against the palisade and you can feel "
         "yourself being watched by guards hidden in it. A road "
         "follows the palisade into the village while a path leads "
         "out into the swamp. Not many lizard-men are about and the "
         "few you spot are always in a hurry. \n\n");
add_property("no_undead",1);
add_item("path", "It leads into the swamp, full of adventures and "
         "dangers. \n\n");
add_item("gate", "This is one of the twin gates guarding the north "
         "entrance. It can be closed at a moments notice from the "
         "guards in the watchtower, should danger arise. \n\n");
add_item("palisade", "Made of strong wood and smeared with mud this "
         "impressive fortification encircles the small village. \n\n");
add_item(({"watchtower","tower"}), "The watchtower stands a bit taller "
           "than the palisade and serves as an early warning system for "
           "the village. \n\n");
add_item("guards", "You can't see them but you know they're there. \n\n");
add_item("road", "The road is really not much different from the path, "
         "perhaps a bit more used and free of annoying vegetation. "
         "It follows the palisade into the village. \n\n");
add_item("lizard-men", "A few of the villagers hurry about, completely "
         "ignoring you. \n\n");
add_exit("southwest",SWAMP +"lizard27","room");
add_exit("northwest",SWAMP +"lizard22","room");
}
