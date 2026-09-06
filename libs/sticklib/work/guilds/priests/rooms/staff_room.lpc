#include "priest_room.h"

object carpenter;

void create_room()
{
    set_light_level(LT_LIGHTS);
    set(ROOM_GUILD);
    set(ROOM_WD, WD_INDOORS);
    set(PREVENT_TELEPORT);
    set_short("Carpenter's chamber");
    set_long(
      "You are in the chamber of the guild carpenter. He is the person who makes \
the powerful Staffs of " GOD_NAME " for priests. There isn't much furniture \
here, just the carpenter's workbench.");

    add_exit("southeast", PRIEST_ROOM_DIR "nave");
    set_items(([
	"workbench": "It's an old wooden workbench. There are some tools on it.",
	"tools": "You can see some tools on the workbench; a hammer, \
a saw, and some others.",
      ]));

    add_monster(PRIEST_MON_DIR "carpenter","The carpenter comes back.",1);
}
