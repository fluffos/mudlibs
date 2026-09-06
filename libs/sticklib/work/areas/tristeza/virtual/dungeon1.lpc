#include "../DEFS.h"

#include <room_defs.h>
#include <door_defs.h>
#include <city_name.h>

inherit TRISTEZA_ROOM_C;

void
create_room()
{
    ::create_room();
    set_short("City Dungeon");
    set_long("You are in the dreaded jail of " CITY_NAME ". It is dark,\
 damp, and cold in here. You can hear moaning and crying from the cells.");
    set(ROOM_WD, WD_NONE);
    set(PREVENT_TELEPORT);
    set_items(([
	({ "cell", "cells" }) : "They are dirty, dark, damp, rough-walled stone."
      ]));
    set_exits(([ "up" : CITY_DIR+"lobby" ]));

    (clone_object(DOOR_FILE)) -> add_door(
      "It's a reinforced heavy metal cell door.",
      "south", CITY_DIR+"cell1", "crude steel",
      "jail_key", 1, 1, 1, 1000,
      "That is a magical lock. I bet no one can pick that!"
    );

    add_monster(NPC_DIR + "guard", "A cityguard arrives.", 1);
    add_monster(NPC_DIR + "guard", "A cityguard arrives.", 1);
    add_monster(NPC_DIR + "guard_sergeant", "A guard sergeant arrives.", 1);
}

void
extra_add_monster(object ob)
{
    if (!ob) return;
    ob->set_wander(0);
}
