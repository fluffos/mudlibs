
#include <room.h>

#include <guild.h>

#include "dirs.h"

void
create_room()
{
    set_short("Tower");
    set_long(
      "This is the tower of the temple complex and guild. There is a great \
view to the city of Tristeza from here.  This is also suitable place \
for thieves to arrive after a long absence. (see 'help starthere')");

    add_exit("down", GDIR + "rooms/attic");

    set_light_level(LT_DIM);
    set(ROOM_WD,WD_INDOORS);
    set(ROOM_GUILD);
    set(PREVENT_TELEPORT);

    /* Load black and white lists */
    call_other(GDIR + "obj/foelist", "???");
}

int query_is_start_location() {
    if ((string)this_player()->query_guild() == GN_THIEF) return 1;
    write("You aren't a thief!\n");
}
