#include <room.h>

#include <door_defs.h>
#include <generic_items.h>

#include "dirs.h"

object ob;

void
reset_room()
{
    if (ob) ob->set_lock(1,0);
}

void
create_room()
{
    set(ROOM_GUILD);
    set_short("Market Square of Newbie York");
    set_long(
      "You are in the 2nd floor of the Guild. This is not much more than an \
attic. The place is used for practice; you can see nice shadows to \
hide into, creaking floor is ideal for training the silent moving, and \
there is also a set of doors to practice lock picking. Note: this place \
is called 'Market Square' - that confuses most of the detection spells. \
So this is a good place to hide. The magic here also prevents summoning. \
You can see the Shower Room to the west.");

    add_exit("down", GDIR + "rooms/guild");
    add_exit("up", GDIR + "rooms/tower");
    add_exit("west", GDIR + "rooms/shower");


    set_light(1);
    set_outdoors(1);
    set(PREVENT_TELEPORT);

    if ((ob = clone_object(DOOR_FILE))) {
	ob->add_door(
	  "It is a heavy wooden door.",
	  "east", GDIR + "rooms/closet", "fine steel",
	  "youcanthavethiskey", 1, 0, 1, 60,
	  "It is quite a complex lock, but not impossible to pick." );
    }
}
