inherit "/std/room";
#include "path.h"

void setup() {
set_short("The Great Maze");
set_light(15); add_item("piller","The pillar appears to be made out of the same grey stone as the walls, and doesn't appear to be of any importance.\n");
set_long("You are in the great maze.  You stand on what appears to be a "
	 "glass walkway above parts of the Great Maze.  Be careful not to "
	 "get too close to the edge, or you might just fall off."
    "  There is a stair leading down to the east."
	 "\n");
add_smell("room", "It smells old.\n");
add_taste("air", "The air tastes Musty and old.");

add_exit("north",MAZE+"smaze03","path");
add_exit("east",MAZE+"maze03","stair");

add_property("no_undead",1);   }  /* setup */
