#include <std.h>
#include <event.h>

inherit ROOM;

void create() {
    ::create();
    set_name("tunnels beneath the enchanted well");
    set_long("A red portal stands in the front of the wall.  The colors "
      "swirl into the wall begging for someone to enter it.  The entrance "
      "to the room seemed to disappear.");
    set_short("tunnels beneath the enchanted well");
    set_exits(([ "portal":ROOMS"gold", ]));
    set_pre_exit_functions( ({"portal"}), ({"go_portal"}) );
}

int go_portal() {
    write("You step in closer to the portal and vanish.\n");
    return 1;
}

