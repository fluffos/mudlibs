/*
 * road1.c
 */

/*
 * On a road. There is a large tree east and some plains west. A jacket is
 * lying on the ground.
 */
#pragma strict_types
#pragma no_clone

inherit "/std/room";

#include "ex.h"		/* Include our definitions */

/*
 * This function is described more in detail in cave1.c and cave2.c
 * if you haven't read them already.
 */
void
reset_room()
{
    if (!present("armour", this_object()))
	clone_object(EX_ARM + "jacket")->move(this_object());
}

/*
 * The creation of the room
 */
void
create_room()
{
    set_short("On a road");
    set_long("" +
	"You are on a long road, it runs north and south. East you see a\n" +
	"large tree standing and west are some small plains.\n");

    add_item("tree", "It's very large, perhaps you should go there " +
	"examine it more closely?\n");
    add_item( ({ "plain", "plains" }), "The plains look inviting.\n");

    add_exit(EX_ROOM + "at_tree", "east");
    add_exit(EX_ROOM + "road2", "north");
    add_exit(EX_ROOM + "roo1", "south", -3);
    add_exit(EX_PLAIN + "plain1", "west");

    /*
     * Add the jacket at creation.
     */
    reset_room();
}
