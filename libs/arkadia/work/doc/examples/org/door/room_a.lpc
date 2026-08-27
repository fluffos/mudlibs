/* Examples on doors made by Nick */

inherit "/std/room";
#include "door.h"

create_room() {
    object door, key;

    set_short("room a");
    set_long("The room a in all it's might.\n");

       /* This is what is needed for the west door. */
    door = clone_object(PATH + "/door_a");
    door->move(this_object());

    key = clone_object(PATH + "/steel_key");
    key->set_key(STEEL); /* Setting the id number of the key. */
    door->set_key(STEEL); /* Tells the door which key fits. */
    key->move(this_object());

       /* This is what is needed for the north door. */
    door = clone_object(PATH + "/door_c");
    door->move(this_object());

    key = clone_object(PATH + "/wood_key");
    key->set_key(WOOD);
    door->set_key(WOOD);
    key->move(this_object());
}
