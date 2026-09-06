#include <room.h>
#include <door_defs.h>

#include "dirs.h"

object *guards;

void
create_room()
{
    object door;

    set_short("Guard Room");
    set_long(
      "A bunch of tough guards stays here at all times, guarding the entrance \
to some large room to the south.");
    set_light_level(LT_LIGHTS);
    set(ROOM_WD,WD_INDOORS);
    set(ROOM_GUILD);
    set(PREVENT_TELEPORT);
    set(NO_CLEANUP);
    set_exits(
      ([
	"south": GDIR + "rooms/donate"
      ])
    );

    if ((door = clone_object(DOOR_FILE))) {
	door->add_door( ({
	    "It is a heavy metal door.\n",
	    "It is a heavy metal door.\n" }),
	  "northwest", GDIR + "rooms/guild", "strong iron",
	  "thief_lender_key", 0, 0, 1, 5,
	  "It is a strong iron lock\n");
    }

    this_object()->reset_room();

    add_command("south", "south_cmd");
}

void
reset_room()
{
    int i;

    if (present("guild_guard")) return;

    if (!guards || sizeof(guards) < 1) guards = ({ 0,0,0,0,0 });

    for (i = random(4) + 1; i >= 0; i--)
    {
	if (!guards[i])
	{
	    guards[i] = clone_object(GDIR + "npc/treasure_guard");
	    guards[i]->move_player("X#" + GDIR2 + "rooms/guard_room");
	}
    }
}

status
south_cmd()
{
    if (present("guild_guard") && !present("tmark", this_player()))
    {
	notify_fail("Guard blocks your way!\n");
	return 0;
    }

    this_player()->move_player("south#" + GDIR2 + "rooms/donate");
    return 1;
}
