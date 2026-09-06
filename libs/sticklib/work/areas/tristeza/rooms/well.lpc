#include <room.h>
#include <door_defs.h>
#include <areas.h>
#include "/areas/tristeza/DEFS.h"

void
create_room()
{
    set_short("Down the well");
    set_long("You are down the well. It is damp and slippery here. Below\
 the ledge that you are standing on is water. Also there is a door to the west,\
 and a lever beside the door. A tight hole leads north into the darkness.");
    set(ROOM_WD, WD_OUTDOORS);
    set_light_level(LT_DARKNESS);
    set(IN_CITY);
    set(NO_PK);
    set_exits(([
	"up"    : AREA_TRISTEZA+"virtual/S7_7",
	"north" : AREA_TRISTEZA+"well_maze/maze1"
      ]));
    set_items(([
	"hole" : "It's a dark hole, leading north.",
	"lever" : "The lever can be moved between two positions.",
	"water" : "The water smells pretty bad. This well seems to be contaminated."
      ]));
    set_commands(([
	"open"	: "open",
	"close"	: "open",
	"pull"	: "pull",
	"turn"	: "pull",
	"move"	: "pull",
      ]));
}

void
coin_drop()
{
    object ob, hit;
    ob = first_inventory();
    while (ob)
    {
	if (interactive(ob))
	{
	    ob->tell_me(
	      "OUCH!!! A coin hits you in your head, and rolls into a hole.");
	    (AREA_TRISTEZA+"virtual/S7_7")->tell_here(
	      "You hear a scream from the well.");
	    tell_here("A coin hits "+ob->query_name()
	      +" and rolls into the sewer.", ob );
	    ob->add_hp(-1);
	    break;
	}
	ob = next_inventory(ob);
    }
}

status
open(string str)
{
    if ( !str || strstr(str,"door")==-1) return 0;
    this_player()->tell_me("The door is much to heavy.");
    return 1;
}

status
pull(string str)
{
    if ( !str || strstr(str,"lever")==-1) return 0;
    (AREA_TRISTEZA+"rooms/door_trap1")->toggle_door();
    return 1;
}
