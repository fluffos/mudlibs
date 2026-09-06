/*********************************************************************
 casino_se.c - magical red poker machine 
*********************************************************************/

#include <room.h>
#include "../casino.h"
#include "stealing.h"

void
create_room()
{
    set_short("Joker's casino, poker row.");
    set_long(
      "You are at the eastern end of a large gambling hall.  The ceiling\
 is low here, but rises upward to the west in huge vaulted arches.\
  Along the east wall stands a collection magical poker machines.");


    set_items(([
	"window" : "A deck of cards is visible through the window.",
	"button" : "You could probably press it.",
	"slot"   : "It is just the right size for gold coins."
      ]));


    set_exits(([
	"west"  : AREA_PATH+"rooms/casino_s",
	"north" : AREA_PATH+"rooms/casino_es"
      ]));

    set(NO_PK);
    set(PREVENT_TELEPORT);
    set(ROOM_WD, WD_NONE);
    set_light_level(LT_LIGHTS);

    add_permanent(AREA_PATH+"objects/vidpoker3" );

    set_commands( ([ "steal":"steal_cmd" ]) );

}


