#include <room.h>

#include "thief.h"

#define TP this_player()

void
create_room()
{
    set_short("Heroes' Temple");
    set_long(
      "The walls of this large hall are all covered by black silk curtains. \
The floor and ceiling are covered by shining black obsidian tiles. \
There are several black obsidian statues around which portray \
ancient thieven heroes.");
    set_light_level(LT_DIM);
    set(ROOM_WD, WD_NONE);
    set(ROOM_GUILD);
    set(PREVENT_TELEPORT);

    add_exit("southeast", GDIR + "rooms/guild");
    add_item(({ "statue", "statues" }),
      "The birth of a new guild beckons its members to achieve great feats.\n"+
      "The statues are unlabelled awaiting great and heralded identities.");
}
