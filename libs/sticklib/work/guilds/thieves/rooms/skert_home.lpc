#include <room.h>

#include "dirs.h"

object skert;

void
create_room()
{
    set_short("Excuse me?");
    set_long(
      "Huh? What? Is this...no...it cannot be...GASP...I think it...IS...\
Only gods might help you now...");

    set_light_level(LT_DIM);
    set(ROOM_WD,WD_NONE);
    set(IN_CITY);

    add_command("pray", "pray");

    this_object()->reset_room();
}

void
reset_room()
{
    if (!skert) {
	skert = clone_object(GDIR + "npc/skert");
	move_object(skert,this_object());
    }
}

status
pray()
{
    if (random(30) > 4)
    {
	this_player()->tell_me("Nothing happened.");
	return 1;
    }
    this_player()->tell_me("Hsoow! (Now that WAS a wise thing to do...)");
    this_player()->move_player("X#" + GDIR2 + "rooms/temple");
    return 1;
}
