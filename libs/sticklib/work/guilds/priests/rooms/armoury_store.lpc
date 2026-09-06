#include <door_defs.h>
#include "../priest.h"
inherit "/guilds/priests/lib/storage_room";

int accept_object(object ob) {
    if (!ob->is_armour() || ob->query_thief_item()) return 0;
    return 1;
}

void create_storage() {
    add_object( ({ SHOP_DOOR,
	({ "add_door",
	  "It is a small oak door.",
	  "south",
	  PRIEST_ROOM_DIR "armoury",
	  "iron",
	  "chopin_was_here",
	  1,1,1,SHOP_PICK_LVL,
	  "It's a strong iron lock, protecting well the room behind this door.",
	}) }), 0, 0);

}

