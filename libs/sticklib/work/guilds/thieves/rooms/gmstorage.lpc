/* Storage for enforcers/GMs only */

#include <room.h>
#include <bboard_defs.h>
#include <generic_items.h>
#include <guild.h>


#include "dirs.h"

object ob;

int clean_up(status flag) { return 0; }

int valid_board_access(object me)
{
    return (this_player()->query_coder_level()  ||
      (string)this_player()->query_guild() == GN_THIEF);
}

void
create_room()
{
    set_short("Iron room");
    set_long(
      "Wow, this is the strongest room you've ever seen! Walls are two metres \
thick solid iron. This must be the legendary Treasury of the Thief-Mages. \
The strongest possible guards and magic keep all but the Guildmasters \
and Enforcers away. A dark stairway leads down. You CAN NOT 'starthere' \
in this place due technical reasons.");
    set_light_level(LT_DIM);
    set(ROOM_GUILD);
    set(ROOM_WD, WD_INDOORS);
    set(PREVENT_TELEPORT);

    add_exit("north", GDIR + "rooms/inner");
    add_exit("down", GDIR + "rooms/inst_bot");

    add_object( ({ GENERIC_BBOARD,
	({ "set_board", 100, ([ BB_WRITE_CLOSURE : #'valid_board_access,
	    BB_READ_CLOSURE : #'valid_board_access, ]), "thief_enf_board", 0 }),
      }), 0, 1);

    move_object(clone_object(GDIR + "obj/temple_key"), this_object());
}
