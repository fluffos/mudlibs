/*
 * Examples on doors, made by Nick
 *
 * All the pick and disarm routines should be the same as for room_e.
 * The only thing that differs is the create routine.
 */

inherit "/d/Genesis/doc/examples/door/room_e";

#include "door.h"
#include <stdproperties.h>

void
create_room()
{
    set_short("room f");
    set_long("The room f in all it's might.\n");

    door = clone_object(PATH + "/door_f");
    door->move(this_object());

    /* Observe, no set_key in this side. */

    add_prop(OBJ_I_SEARCH_TIME, 2); /* Extra time it takes to search here */
    add_prop(OBJ_S_SEARCH_FUN, "search"); /* Function to call when searching */

    add_prop(OBJ_S_WIZINFO, "This room contains a door which might have a " +
	"trap set in it.\nThe door is also pickable.\n");

    /* The other side will call reset_room and set up the trap */
}

