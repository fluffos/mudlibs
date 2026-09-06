/*********************************************************************
 casino_nc.c - Baccarat table 
*********************************************************************/

#include <room.h>
#include "../casino.h"
#include "stealing.h"

void
create_room()
{
    set_short("Joker's casino, baccarat table.");
    set_long(
      "This is the northerly center of the gambling hall, which spreads\
 out all around you.  From all directions come the quiet sounds of\
 gambling machines and the muttering of distant players.");

    set_exits(([
	"north"    : AREA_PATH+"rooms/casino_n",
	"east"     : AREA_PATH+"rooms/casino_en",
	"south"    : AREA_PATH+"rooms/casino_sc",
	"west"     : AREA_PATH+"rooms/casino_wn"
      ]));


    set(NO_PK);
    set(PREVENT_TELEPORT);
    set(ROOM_WD, WD_NONE);
    set_light_level(LT_LIGHTS);

    add_permanent(AREA_PATH+"objects/baccarat" );
    add_monster(AREA_PATH+"npc/employee","The dealer arrives.", 1);

    set_commands( ([ "steal":"steal_cmd" ]) );


}



