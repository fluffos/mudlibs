#include "../DEFS.h"
#include <areas.h>

inherit TRISTEZA_ROOM_C;

/* TODO: Gate closed or open ***/

object *guard;

void
reset_room()
{
    int i;
    for (i = 0; i < 4; i++) if (!guard[i]) {
	    guard[i] = clone_object(NPC_DIR + "guard");
	    guard[i]->move_player("foo", this_object());
	    add_monster(guard[i], 0, 0);
	}
}

void
create_room()
{
    ::create_room();
    guard = allocate(4);
    set_short("At the South Gate of "+CITY_NAME);
    set_long("You are at the South Gate of " + CITY_NAME + ".");
    set_exits(([
#ifdef AREA_HIGHWAYS
	"south"	: SOUTH_PATH,
#endif
	"north"	: CITY_DIR + "S7_13"
      ]));
    add_command("south", "block_south");
    add_monster(AREA_TRISTEZA + "npc/leper",
      "Leper arrives and cries: Unclean!", 1);
    reset_room();
}

status
block_south()
{
    if (!interactive(this_player()) && this_player() ->
      id("city_"+(string)this_player()->query_real_name()))
	return 1;
    return 0;
}
/* Let's prevent guards etc. to leave the city. */
