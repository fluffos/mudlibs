/*********************************************************************
 casino_s.c - Wheel of fortune
*********************************************************************/

#include <room.h>
#include "../casino.h"
#include "stealing.h"

void
create_room()
{
    set_short("Joker's casino, wheel of fortune.");
    set_long("You are standing at the south end of a large vaulted room.\
  Impressive chandaliers illuminate the various gaming tables that are\
 scattered throughout the hall.  Nearby, a huge stone wheel of fortune\
 stands embedded in the south wall, luring gamblers who pass through\
 the south exit."); 


    set_exits(([
	"north" : AREA_PATH+"rooms/casino_sc",
	"east"  : AREA_PATH+"rooms/casino_se",
	"west"  : AREA_PATH+"rooms/casino_sw",
	"south" : AREA_PATH+"rooms/entrance"
      ]));

    set(NO_PK);
    set(PREVENT_TELEPORT);
    set(ROOM_WD, WD_NONE);
    set_light_level(LT_LIGHTS);

    add_permanent(AREA_PATH+"objects/wheel" );
    add_monster(AREA_PATH+"npc/employee", "The dealer arrives.", 1 );



    set_commands( ([ "steal":"steal_cmd" ]) );

}


