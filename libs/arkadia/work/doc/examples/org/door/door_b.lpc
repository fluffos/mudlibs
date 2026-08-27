/* An example door made by Nick, 1991-12-19 */

inherit "/std/door";
#include "door.h"

create_door()
{

    /* You need an id, and both sides should have the same id
    */
  set_door_id("testdoor");

    /* Here you decide wich command will take you through the door, 'enter' is no
       good pass command, at least not yet, since argument is not tested. If the
       first pass command has only one or two letters in it the second pass command
       will be used in the standard description of the door.
    */
  set_pass_command(({"e","east"}));

    /* The name of the door. The first name in the array will be used in the
       standard description of the door.
    */

  set_door_name(({"steel gate","gate"}));

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

           set_open(i)           1 if open, 0 if closed
           set_locked(i)         1 if locked, 0 if unlocked

       There are also plenty of other things you can set in the door, but this
       is all you need. Look in /std/door.c for more details on all the
       set_functions()
    */
}
