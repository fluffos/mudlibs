#include <room.h>
#include <door_defs.h>
#include "thief.h"

void
create_room()
{
    set_outdoors(1);
    set_light_level(LT_DARKNESS);
    set(PREVENT_TELEPORT);
    set(IN_CITY);
    set_short("Temple Treasury");
    set_long("In this very strong-looking small room the High Priestess "+
      "keeps the treasures of the temple.");
    add_object( ({
	DOOR_FILE, ({
	  "add_door",
	  "It is a very strong-looking steel door.\n",
	  "west", GDIR + "rooms/prs_room", "complex steel",
	  "skert_temple", 1, 1, 1, 180,
	  "It is an extremely complex lock.\n",
	})
      }), 0, 0);
}
