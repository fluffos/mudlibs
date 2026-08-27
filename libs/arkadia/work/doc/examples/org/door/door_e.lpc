/* An example door made by Nick */

inherit "/std/door";
#include "door.h"

/*
 * The normal create routine
 */
void
create_door()
{
    set_door_id("testiiidoor");
    set_pass_command(({"n", "north"}));
    set_door_name(({"stone door", "door"}));
    set_other_room(PATH + "/room_f");
    set_lock_command("lock");
    set_lock_name("lock");
    set_unlock_command("unlock");
    set_open(0);
    set_locked(1);
    set_pick(20);
}

/*
 * Someone is trying to pick the lock, well, if the trap is there it will
 * go off!
 */
void
do_pick_lock(int skill, int pick)
{
    object room;

    ::do_pick_lock(skill, pick);

    room = environment(this_object());
    if (room->query_trap())
	room->do_trap(this_player());
}

