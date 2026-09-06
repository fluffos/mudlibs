/*********************************************************************
 casino_en.c - magical blue poker machine (vidpoker1) 
*********************************************************************/

#include <room.h>
#include "../casino.h"
#include "stealing.h"

void
create_room()
{
    set_short("Joker's casino, poker row.");
    set_long(
      "You are at the east side of the gambling hall.  The\
 sounds of bustling activity emanate from the direction of the\
 huge vaulted room the stretches to your west. Along\
 the east wall stands a row of magical poker machines."); 

    set_exits(([
	"north" : AREA_PATH+"rooms/casino_ne",
	"west"  : AREA_PATH+"rooms/casino_nc",
	"south" : AREA_PATH+"rooms/casino_es"

      ]));

    set_items(([
	"window" : "A deck of cards is visible through the window.",
	"button" : "You could probably press it.",
	"slot"   : "It is just the right size for gold coins."
      ]));


    set(NO_PK);
    set(PREVENT_TELEPORT);
    set(ROOM_WD, WD_NONE);
    set_light_level(LT_LIGHTS);

    add_permanent(AREA_PATH+"objects/vidpoker1" );

    set_commands( ([ "steal":"steal_cmd" ]) );

}



