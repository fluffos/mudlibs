#include <room.h>

void
create_room()
{
    set_short("The void");
    set_long("The void. You come to the void if you fall out of a room,\
 and have nowhere to go.");
    set_light_level(LT_LIGHTS);
    set_outdoors(WD_NONE);
    set_items(([ "xyzzy_void" : "What?" ]));
}

void
init_room()
{
    if (interactive(this_player())) {
	this_player() -> tell_me(" You are transfered to the shop...");
	move_object(this_player(), "/room/shop");
	command("look",this_player());
	environment(this_player())->tell_here("Something appears out of void.", this_player());
    }
}
