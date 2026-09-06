/*********************************************************************
 casino_sw.c - Guild slot machine (slot4) 
*********************************************************************/

#include <room.h>
#include "../casino.h"
#include "stealing.h"

void
create_room()
{
    set_short("Joker's casino, west slots.");
    set_long(
      "You are at the southwestern end of a large gambling hall.  The ceiling\
 is low here, but rises upward to the east in huge vaulted arches.\
  Along the west wall stands a collection of slot machines.");

    set_items(([
	"panel" : "Four reels are visible through the panel",
	"arm" : "It looks like it would be easy to pull it",
      ]));

    set_exits(([
	"east"      : AREA_PATH+"rooms/casino_s",
	"north"     : AREA_PATH+"rooms/casino_ws"
      ]));

    set(NO_PK);
    set(PREVENT_TELEPORT);
    set(ROOM_WD, WD_NONE);
    set_light_level(LT_LIGHTS);

    add_permanent(AREA_PATH+"objects/slot4" );

    set_commands( ([ "steal":"steal_cmd" ]) );

}


