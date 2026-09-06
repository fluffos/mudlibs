#include <room.h>
#include <armour_defs.h>
#include <areas.h>
#include <daemons.h>
#include <quests.h>

void
create_room()
{
    set_short("End of maze");
    set_long("You have now come to a dead end in the maze.");
    set(IN_CITY);
    set(ROOM_WD, WD_NONE);
    set_light_level(LT_DARKNESS);
    set_exits(([ "south" : AREA_TRISTEZA+"well_maze/maze4" ]));
    add_object( ({ ARMOUR_FILE,
	({ "set_name", "leather armour" }),
	({ "set_short", "A leather armour" }),
	({ "set_id", ({ "armour", "leather armour", "leather" }) }),
	({ "set_long", "It is a fine leather armour, obviously\
 hand-made by a skilled craftsman." }),
	({ "set_value", 110 }),
	({ "set_weight", 3 }),
	({ "set_ac", 2 }),
	({ "set_type", "armour" })
      }), 0, 1 );
}

void
init_room()
{
    /* Check minor task */
    if (!this_player()->query_quests(QUEST_M3)) 
    {
	this_player()->tell_me(
	  "You have solved a minor quest! You feel more experienced.\n\n");
	QUEST_D->add_quest(this_player(),QUEST_M3);
    }
}
