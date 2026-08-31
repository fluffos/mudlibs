#include <std.h>
#include <event.h>

inherit ROOM;

void create() {
    ::create();
    set_name("a wide room beneath the enchanted well");
    set_long("The room is considerably dark compared to the "
      "tunnels that led here.  A stone pedistal sits in "
      "the middle of the room.  Cob webs hang from the "
      "ceiling.");
    set_short("a wide room beneath the enchanted well");
    new("/d/events/obj/pedistal")->move(this_object());
}

