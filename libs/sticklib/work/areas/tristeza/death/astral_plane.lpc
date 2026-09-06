/* Astral Plane */

#include <room.h>

#include <areas.h>
#include <generic_rooms.h>

string *dests;

void
create_room()
{
    set_short("Astral plane");
    set_long(
      "You are floating in the endless void of the Astral plane. You can\
 travel into any direction - where any direction will take you is\
 another matter then. There is no way you can know.");
    set_light_level(LT_LIGHTS);
    set(ROOM_WD, WD_NONE);
    set(PREVENT_TELEPORT);
    set(PREVENT_SHOUT);
    set(ROOM_ISOLATED);
    /* These should be elemental planes and such. */
    dests = ({ 	
      GENERIC_ROOM_CHURCH,
#ifdef AREA_KALEVALA
      AREA_KALEVALA+"kaleva/forge",
#endif
#ifdef AREA_HOBBIT_VILLAGE
      AREA_HOBBIT_VILLAGE+"rooms/tunnel7",
#endif
#ifdef AREA_ISLANDS
      AREA_ISLANDS+"r/m2/crater2",
#endif
    });
    set_commands(([
	"north"	: "anydir",
	"northeast"	: "anydir",
	"east"	: "anydir",
	"southeast"	: "anydir",
	"south"	: "anydir",
	"southwest"	: "anydir",
	"west"	: "anydir",
	"northwest"	: "anydir"
      ]));
}

int
anydir(string arg)
{
    if (random(100) > 13) {
	this_player()->tell_me(
	  "You travel in some direction and arrive nowhere.");
	return 1;
    }
    this_player()->tell_me("You are sucked through a planar wormhole.");
    this_player()->move_player("X", dests[random(sizeof(dests))]);
    return 1;
}
