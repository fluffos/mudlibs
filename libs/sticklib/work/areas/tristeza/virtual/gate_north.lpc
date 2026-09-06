#include "../DEFS.h"

inherit TRISTEZA_ROOM_C;

/* TODO: Gate closed or open */

object *guard;

void
reset_room() {
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
    set_short("At the North Gate of "+CITY_NAME);
    set_long("You are at the North Gate of " + CITY_NAME + ".");
    set_exits(([
#ifdef AREA_HIGHWAYS
	"north"	: NORTHERN_HIGHWAY,
#endif
	"south"	: CITY_DIR + "S7_1"
      ]));
    add_command("north", "block_north");
    reset_room();
}

status
block_north()
{
    if (!interactive(this_player()) && this_player() ->
      id("city_"+(string)this_player()->query_real_name()))
	return 1;
    return 0;
}
/* Let's prevent guards etc. to leave the city. */
