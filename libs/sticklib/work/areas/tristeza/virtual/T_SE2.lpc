#include "../DEFS.h"
#include <room_defs.h>

inherit TRISTEZA_ROOM_C;
inherit TOWER_LOOK_C;

void
create_room()
{
    ::create_room();
    set(ROOM_WD, WD_INDOORS);
    set_short("Tower");
    set_long("You are now on the top of the tower. You can see a long way\
 to the south and east of "+CITY_NAME+" from up here.");
    add_exit("down", CITY_DIR+"tower_14x14");
    set_items(([
	"south"	: "Try 'look south'?",
	"east"	: "Try 'look east'?"
      ]));
    add_tower_look(({ "south", "east" }));
}
