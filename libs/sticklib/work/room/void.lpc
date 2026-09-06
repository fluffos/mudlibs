#include <room.h>

status
church()
{
    if (!this_player()) return 0;
    if (environment(this_player()) != this_object()) return 0;
    this_player() -> tell_me("\n\nYou are transfered to the church...\n\n");
    move_object(this_player(), "/room/church");
    environment(this_player())->tell_here("Something appears out of void.", this_player());
    command("look", this_player());
    return 1;
}

void
create_room()
{
    set_short("The void");
    set_long("Void. You come to the void if you fall out of a room,\
 and have nowhere to go.");
    set_light_level(LT_LIGHTS);
    set_outdoors(WD_NONE);
    church();
}

void
init_room()
{
    if (interactive(this_player()))
	call_out("church", 0);
}
