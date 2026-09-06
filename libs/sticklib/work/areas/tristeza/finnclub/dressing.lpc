// Entrance to Finland is now here! Graah 23-Jun-96
#include <room.h>
#include <areas.h>
#include "../DEFS.h"

void
create_room()
{
    set_short("Pukuhuone (Dressing Room)");
    set_long("This is the Pukuhuone (Dressing Room) of Finnish Club's pride;\
 the real, genuine Savusauna! You can enter the Sauna to the south, but you have\
 to remove your armour and weapons first. The only correct way to go into\
 Sauna is naked, and both sexes and all races at the same time. Perhaps you\
 should also have a 'vihta' with you (not compulsory)?");
    // Finland area was boring and useless. The monsters didn't give
    // Good exp etc.
    set_exits(([
	"north"	: CITY_PATH+"finnclub/hall",
	//  "east"    : AREA_FINLAND+"virtual/S9_34",
	"east"    : CITY_PATH+"finnclub/shore",
	"south"	: CITY_PATH+"finnclub/sauna"
      ]));
    set(ROOM_WD, WD_INDOORS);
    set_light_level(LT_LIGHTS);
    set(PREVENT_TELEPORT);
    set(NO_PK);
    set(IN_CITY);
    set_commands(([
	"east"	: "east",
	"south" : "south"
      ]));
}

status
east()
{
    this_player()->tell_me("You step through a magical portal.");
    return 0;
}

status
south()
{
    object *inv;
    int i;

    if (this_player()->query_npc() &&
      !this_player()->query_ctrl()) return 1;

    this_player()->tell_me(
      "A small, beautiful warning nymph (hmm...looks like she is finnish!) \
arrives in a puff of smoke and makes sure that you are naked before \
entering.");

    /* Strip'em again! //Graah */
    inv = all_inventory(this_player());

    for (i = sizeof(inv) - 1; i >= 0; i--)
	if (inv[i]->query_worn() && !inv[i]->drop())
	    inv[i]->unwear_cmd(0, this_player());

    return 0;
}
