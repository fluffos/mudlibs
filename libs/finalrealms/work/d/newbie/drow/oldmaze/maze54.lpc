inherit "/std/room";
#include "path.h"

void setup() {
set_short("The Great Maze");
set_light(15); add_item("piller","The pillar appears to be made out of the same grey stone as the walls, and doesn't appear to be of any importance.\n");
set_long("You are in the great maze.  The room is squareish in shape and "
	 "there is a pillar in each corner of the room.  The walls are made "
	 "out of some plain grey stone that looks like it is almost wet. "
	 "The air is seeped with a musty smell that you can taste."
    "  As you look around you notice a dark stain on the floor, but "
    "there doesn't appear to be anywhere that it could be coming from"
         ".\n");
add_item("stain","As you look at the stain on the floor you realize "
	 "that it is blood.  As you look closer, you feel a drop of "
	 "something hit you on the back of your head as you look up"
	 "you see a dark hole in the ceiling with a rope hanging "
	 "a little way out.  You could probably use the rope to "
	 "climb up into the hole.\n");
add_item("rope","As you look at the rope you see that it is dripping "
	 "blood.  It is just within reach, so you could probably use "
	 "it to climb up into the hole.\n");
add_smell("room", "It smells old.\n");
add_taste("air", "The air tastes Musty and old.");

add_exit("south",MAZE+"maze49","door");
add_exit("east",MAZE+"maze55","door");
add_exit("west",MAZE+"maze53","door");
 add_exit("climb rope",MAZE+"maze33","hole");
 modify_exit("climb rope",({"obvious",0}) );
add_exit("rope",MAZE+"maze33","hole");
modify_exit("rope",({"obvious",0}));

add_property("no_undead",1);   }  /* setup */
