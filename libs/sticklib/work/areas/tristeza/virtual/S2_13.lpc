#include "../DEFS.h"

inherit TRISTEZA_ROOM_C;

string *ld_id_list;

void
create_room()
{
    ::create_room();
    ld_id_list = ({ });
    set_short("Godshire");
    set_long("You are on the Godshire which goes east \
and west. You can see the Mages' Square to the west. There is also \
a garden to the north. You can see a house behind the garden.");
    set_exits(([
	"west"	: CITY_DIR + "S1_13",
	"east"	: CITY_DIR + "S3_13",
      ]));
    add_command("north", "north_cmd");
    add_monster(NPC_DIR + "fido");
    add_monster(NPC_DIR + "beaver");
}

/* No cityguards should go there */
status
north_cmd()
{
    if (this_player() &&
      (this_player()->id("city_guard") ||
	this_player()->id("ebonflow") ||
	this_player()->id("ebonspawn") ||
	this_player()->id("leper") ||
	this_player()->id("janitor")))
	return 1;
    return 0;
}
