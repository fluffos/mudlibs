/* An example door made by Nick, 1991-12-19 */

inherit "/std/door";
#include "door.h"
#include <stdproperties.h>

create_door() {

    /* You need an id, and both sides should have the same id
    */
  set_door_id("testiidoor");

    /* Here you decide wich command will take you through the door, 'enter' is no
       good pass command, at least not yet, since argument is not tested. If the
       first pass command has only one or two letters in it the second pass command
       will be used in the standard description of the door.
    */
  set_pass_command(({"s","south"}));


    /* The name of the door. The first name in the array will be used in the
       standard description of the door.
    */
  set_door_name(({"wooden door","door"}));

    /* This is the room on the other side of the door.
    */
  set_other_room(PATH + "/room_a");

    /* If you want to have a look on the door you need to define the following
       sets too.
    */
  set_lock_command("lock");
  set_lock_name("lock");
  set_unlock_command("unlock");

    /* The standard door is open and unlocked, if you want it differently you
       should use these functions too:
    */

  set_open(0);         /*  1 if open, 0 if closed */
  set_locked(1);       /*  1 if locked, 0 if unlocked */

    /* It is possible to pick the lock on this door if you are skilled.
     */

  set_pick(20);

    /* Why not make only short players like hobbits be able to enter this
     * door */

  add_prop(DOOR_I_HEIGHT, 150); /* 150 cm height in the door, no players */
                                  /* cannot bend their backs ;-) */

    /* There are also plenty of other things you can set in the door, but this
       is all you need. Look in /std/door.c for more details on all the 
       set_functions()
    */
}
