#include "../DEFS.h"
#include <room_defs.h>

inherit TRISTEZA_ROOM_C;

#define	HQ	CITY_DIR+"guard_HQ"

object guard;

void
create_room()
{
    ::create_room();
    set_short("Hall to Guard HQ");
    set_long("You have entered the Guard HQ building. This hallway leads\
 to the actual Headquarters.");
    set_outdoors(WD_INDOORS);
    set_exits(([
	"north"	: HQ,
	"south"	: CITY_DIR + "S2_7"
      ]));
    set_commands(([ "north" : "check_north" ]));
    add_monster(NPC_DIR + "guard_sergeant", "Guard sergeant arrives.", 1);
    // Load HQ here too
    (HQ) -> load_me_now();
}

status
check_north()
{
    if (guard && environment(guard) == this_object() &&
      !this_player() -> query_coder_level()) {
	this_player() -> tell_me("Guard blocks your way!");
	return 1;
    }
    return 0; // Let's allow normal movement if no guard or we're coders.
}
