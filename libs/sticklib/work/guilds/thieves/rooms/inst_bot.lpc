
#include <room.h>
#include <npc_defs.h>
#ifdef LIV_OK_TO_PK
#undef LIV_OK_TO_PK
#endif

#ifdef LIV_DAMAGE_TYPE
#undef LIV_DAMAGE_TYPE
#endif

#include "thief.h"

void
create_room()
{
    set_short("Bottom of Dark Stairway");
    set_long(
      "You are at the bottom of the dark spiral stairway. There is an open \
entrance to the south, which has been carved to resemble a mouth of \
a giant demon, ready to swallow and chew you alive!");
    set_light_level(LT_DARKNESS);
    set(ROOM_WD,WD_NONE);
    set(ROOM_GUILD);
    set(PREVENT_TELEPORT);

    add_exit("up", GDIR + "rooms/gmstorage");
    add_exit("south", GDIR + "rooms/demontemple");

    add_monster(GDIR+"npc/major_demon",
      "Major demon arrives in a puff of red smoke!", 1);
}

void
init_room()
{
    add_action("south", "south");
}

int
south()
{
    // Tidied up April 12, 1998 - Kieve
    // This had an ambiguous if statement that didn't seem to be
    // working perfectly.

    object tm, demon;

    if (this_player()->query_coder_level())
	return 0;

    if (!present("thief_demon", this_object()))
	return 0;

    tm = present("tmark", this_player());
    if(!tm  ||  tm->query_guildmaster() < TR_DEMON)
    {
	this_player()->tell_me("Demon hisses: \"No\", and blocks your way.");
	return 1;
    }
    return 0;
}
