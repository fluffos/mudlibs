/*********************************************************************
 casino_sc.c - Roulette wheel 
*********************************************************************/

#include <room.h>
#include "../casino.h"
#include "stealing.h"

void
create_room()
{
    set_short("Joker's casino, roulette wheel.");
    set_long("This is the center of a huge gambling hall.  The\
 high vaulted ceiling is shadowed in darkness above the fine hanging\
 chandaliers that illuminate the various tables.  The sounds of the\
 whirring and humming machines quietly permeate the background noise.");


    set_exits(([
	"north" : AREA_PATH+"rooms/casino_nc",
	"east"  : AREA_PATH+"rooms/casino_es",
	"west"  : AREA_PATH+"rooms/casino_ws",
	"south" : AREA_PATH+"rooms/casino_s"
      ]));

    set(PREVENT_TELEPORT);
    set(ROOM_WD, WD_NONE);
    set_light_level(LT_LIGHTS);

    add_permanent(AREA_PATH+"objects/roulette" );
    add_monster(AREA_PATH+"npc/employee","The dealer arrives.", 1);

    set_commands( ([ "steal":"steal_cmd" ]) );


}


