/*
 * cave2.c
 */

/*
 * This is the inner part of the cave. It's inside and dark. A dull rock is
 * lying on the ground. Here I will show how you solve the problem if you
 * reset_room() function is written after the create_room(). (This problem
 * only appears i you use types on functions and arguments and create_room()
 * calls reset_room().)
 */
#pragma strict_types
#pragma no_clone

inherit "/std/room";

#include "ex.h"			/* Include our definitions */
#include <stdproperties.h>	/* Using < > will make the parser look for
				 * the file at standard directories. They are
				 * /sys and /secure (correct me someone if
				 * I'm wrong) */

/*
 * Prototypes - Since the definition of reset_room() has to be put before
 *		the function is called, we put a prototype of it up here.
 */
void reset_room();

/*
 * The creation of the room
 */
void
create_room()
{
    set_short("Deep in cave");
    set_long("You are in a dead end. There is not much to see here.\n");
    add_exit(EX_ROOM + "cave1", "east");

    /*
     * Again this is an inside room. And we want to make it dark too.
     * ROOM_I_LIGHT is the prop to use. It indicates how much light the
     * room itself 'gives out'. If the number is negative the room radiates
     * darkness and positive it radiates light. Default value of this prop
     * is 1 (light).
     */
    add_prop(ROOM_I_INSIDE, 1);
    add_prop(ROOM_I_LIGHT, 0);

    /*
     * Add the rock at creation.
     */
    reset_room();
}

/*
 * Again we use reset_room() to add the item
 */
void
reset_room()
{
    /*
     * This time we need a local variable of object type
     */
    object ob;

    /*
     * This time instead of room_add_object() we will use clone_object() and
     * move(). clone_object() is an efun that returns an object. Then we call
     * the local function move() in that object to move the object here.
     */
    if (!present("rock", this_object()))
    {
	ob = clone_object(EX_OBJ + "rock");
	ob->move(this_object());

	/*
	 * We want people in the room to get a message if they are here when
	 * the room resets. You can test this by picking up the rock, and 
	 * call reset_room() in the room. Compare this with picking up the
	 * torch in the earlier room and calling reset_room(). You call
	 * another function in an object with the Call command. To call
	 * reset_room() in your environment do, 'Call ! reset_room'.
	 *
	 * tell_room() looks like a efun, but is only a simulated one.
	 * Use 'sman tell_room' if you want to know more about it
	 */
	tell_room(this_object(), "A rock falls from the roof.\n");
    }

    /*
     * The -> means that we want to call a function in an object. It is the
     * same thing as 'call_other(ob, "move", this_object())'. (Call a function
     * in another object.) call_other() is an efun and it has a manual page.
     * Using -> is more compact and will be used when possible. Instead of
     * using ob as a storage for the object returned from clone_object() we
     * could also have written:
     *      clone_object(EX_OBJ + "rock")->move(this_object());
     */
}
