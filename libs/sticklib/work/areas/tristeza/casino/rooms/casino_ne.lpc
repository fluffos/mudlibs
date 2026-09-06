/*********************************************************************
 casino_ne.c - Blackjack table 
*********************************************************************/

#include <room.h>
#include "../casino.h"
#include "stealing.h"

void
create_room()
{
    set_short("Joker's casino, blackjack table.");
    set_long(
      "You are at the far northeast corner of the gambling hall.  The\
 sounds of bustling activity emanate from the direction of the\
 huge vaulted room the stretches to your west and south.  The\
 ever-popular blackjack table is here, awaiting both the wise\
 and foolish gamblers that may happen along."); 

    set_exits(([
	"west"  : AREA_PATH+"rooms/casino_n",
	"south" : AREA_PATH+"rooms/casino_en"

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

    add_permanent(AREA_PATH+"objects/blackjack" );
    add_monster(AREA_PATH+"npc/employee","The dealer arrives.", 1);

    set_commands( ([ "steal":"steal_cmd" ]) );

}



