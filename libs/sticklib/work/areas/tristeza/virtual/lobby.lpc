#include "../DEFS.h"

inherit TRISTEZA_ROOM_C;

#include <room_defs.h>

#include <door_defs.h>
#include <generic_items.h>

void
create_room()
{
    ::create_room();
    set_short("Hall of Justice");
    set_long("You are standing in the great hall of the Court house. A\
 stairway leads down to the horrible City Dungeons, the dread of all criminals.\
 Great door to the south leads into the Court Hall.");
    set(ROOM_WD, WD_INDOORS);
    set(PREVENT_TELEPORT);
    set_exits(([
	"north"	: CITY_DIR + "S3_4",
	"east"	: CITY_DIR +  "S4_5",
	"down"	: CITY_DIR+"dungeon1"
      ]));
    (clone_object(DOOR_FILE)) -> add_door(
      "Wow, what a great door.",
      "south", CITY_DIR+"court_hall", "huge iron",
      "judges_key", 0, 0, 1, 200, "That is a lock of finest quality."
    );

    add_object(({ GENERIC_BBOARD,
	({ "set_board", 100, 0, "court_board", 0 }),
      }), 0, 1);
    add_monster(NPC_DIR + "guard", "A cityguard arrives.", 1);
    add_monster(NPC_DIR + "guard", "A cityguard arrives.", 1);
}

void
extra_add_monster(object ob)
{
    if (!ob) return;
    ob->set_wander(0);
}
