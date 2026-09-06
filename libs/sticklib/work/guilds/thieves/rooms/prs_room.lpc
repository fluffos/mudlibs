#include <room.h>
#include <door_defs.h>
#include <generic_items.h>

#include "dirs.h"

void
create_room() {
    set_outdoors(1);
    set_light_level(LT_DIM);
    set(PREVENT_TELEPORT);
    set(IN_CITY);
    set_short("Priestess' Room");
    set_long(
      "This room is very Spartan (whatever that is), as the Priestess spends "+
      "almost all her time in the Temple. The only furniture is a bed.");
    add_exit("south", GDIR + "rooms/temple");

    add_object( ({
	DOOR_FILE, ({
	  "add_door",
	  "It is a very strong-looking steel door.\n",
	  "east", GDIR + "rooms/temple_tre", "complex steel",
	  "skert_temple", 1, 1, 1, 180,
	  "It is an extremely complex lock.\n",
	})
      }), 0, 0);
    add_object(GDIR+"obj/rose", 0, 1);
}
