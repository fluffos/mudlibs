// This tunnel leads to a crypt and out of the priest guild. Do not tell
// anything about this to the priests!

#include <room.h>
#include <guild.h>
#include "../DEFS.h"

string tunnel_long() {
    return sprintf("You are in a small tunnel which looks like it hasn't \
been used in ages. The walls are damp and water along them trickles down \
to the floor. To the south there is %s.",
      WINE_CELLAR->query_door_open() ? "an open stone door leading to a wine cellar":
      "a stone door, but no obvious way to open it");
}

void create_room()
{
    set_light_level(LT_DARKNESS);
    set(ROOM_WD, WD_INDOORS);
    set_short("An old tunnel");
    set_long(#'tunnel_long);
    set_exits(([
	"north": ROOM_DIR "tunnel2",
      ]));
}
