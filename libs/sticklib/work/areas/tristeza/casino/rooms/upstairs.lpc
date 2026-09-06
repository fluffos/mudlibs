/*********************************************************************
 upstairs.c - poker room 
*********************************************************************/

#include <room.h>
#include "../casino.h"
#include "stealing.h"

void
create_room()
{
    set_short("Upstairs room.");
    set_long(
      "This is a small square room that is illuminated by a single chandalier\
 which hangs from the ceiling in the center of the room.  Below the\
 light is a round poker table, large enough to seat about half a dozen\
 people.  You see a plaque in the shadows of the far wall.");


    set_exits(([ "down" : AREA_PATH+"rooms/casino_n" ]));

    set(NO_PK);
    set(PREVENT_TELEPORT);
    set(ROOM_WD, WD_NONE);
    set_light_level(LT_LIGHTS);

    add_permanent(AREA_PATH+"objects/poker" );

    add_monster(AREA_PATH+"npc/employee","The dealer arrives.", 1);


    set_commands(([ "read":"read_cmd", "steal":"steal_cmd" ]));

}


/*******************************************************************
  Process the read command
*******************************************************************/

status read_cmd(string arg)
{
    string temp;

    if (!arg || sscanf(arg, "%s", temp ) != 1 || temp != "plaque" )
    {
	notify_fail("Read what?\n");
	return 0;
    }

    write("The plaque displays the winning poker hands:\n\n\
         Royal flush    - A K Q J 10, same suit\n\
         Straight flush - straight, same suit\n\
         4 of a kind    - Four cards of the same rank\n\
         Full house     - 3 of a kind and 2 of a kind\n\
         Flush          - All cards same suit\n\
         Straight       - Cards in rank order\n\
         3 of a kind    - Three cards of same rank\n\
         2 pairs        - Two pairs\n\
         1 pair         - One pair\n\
         High card      - Basically a crappy hand\n\n");

    return 1;

}

