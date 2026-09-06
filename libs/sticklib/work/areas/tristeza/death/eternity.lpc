#include <room.h>

void
create_room()
{
    set_short("ETERNITY");
    set_long(
      "You can store the corpses of those mortals who didn't leave a\
 corpse into this room.");
    set_light_level(LT_LIGHTS);
    set(ROOM_WD, WD_NONE);
    set(PREVENT_TELEPORT);
    set(PREVENT_SHOUT);
    set(ROOM_ISOLATED);
    add_exit("church", "/room/church");
}

void
init_room()
{
    if (!this_player()->query_coder_level())
	call_out("kick_out", 0, this_player());
}

void
kick_out(object ob)
{
    if (!ob || !present(ob, this_object())) return;

    ob->move_player("X#room/church");
}
