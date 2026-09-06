#include "priest_room.h"


void create_room()
{
    set_light_level(LT_DIM);
    set(ROOM_WD, WD_NONE);
    set(PREVENT_TELEPORT);
    set(ROOM_GUILD);
    set(NO_CLEANUP);
    set(NO_PK);
    set_short("In the mist");
    set_long(
      "You are floating in the middle of a strange white mist. You don't seem \
to be able to move anywhere, but somehow you feel that you are very \
safe here."
    );
}

void
teleport_to_church(object pl) {
    pl->move_player("X", "/room/church");
}


void
check_player(object pl) {
    if(pl->query_guild_object_name() != PRIEST_MARK_PATH) {
	pl->tell_me("You are not a member of the old priest \
guild! How on earth have you been able to get here?? Well, you are \
teleported to church...");
	call_out(#'teleport_to_church, 2, pl);
	return;
    }
}

void
init_room() {
    call_out(#'check_player, 1, this_player());
    if(this_player()->set_start_location(1) == 
      "players/priests/room/relaxation")
	this_player()->set_start_location(PRIEST_ROOM_DIR "relaxation");
}
