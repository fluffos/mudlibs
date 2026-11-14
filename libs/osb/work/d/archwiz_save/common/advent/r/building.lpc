/* Advent - Inside Building -- Mateese, 10-Aug-96
 *
 * Part of the old pregame of Advent, this is here now just to have it.
 * To make clear that this is not part of normal Nightfall, the sky
 * is always of a uniform grey.
 * Players come here by touching the floor at the treasure dump site.
 */

#include <properties.h>
#include <rooms.h>
#include <moving.h>
#include "advent.h"

inherit ADVENT("i/stdroom");

/*-----------------------------------------------------------------------*/
void create()
{
  ::create();

  // Main description
  Set(P_INT_SHORT, "Inside Building");
  Set(P_INT_LONG,
"You are inside a building, a well house for a large spring.\n"
     );
  Set(P_INT_SMELL, "The air smells fresh and cool.\n");
  Set(P_INT_NOISE, "It is silent, except for the flow of the water.\n");
  Set(P_BRIGHT, 80);

  Set(P_EXPLORABLE, 1);
    
  // Exits
  AddExit(({"out", "west"}), ADVENT("r/endofroad"));
  HideExit("out", HIDE_ALWAYS);
    
  // Details
  AddOrigDetail("spring", 
"A spring of clear water, flowing out of a pair of 1 foot diameter "
"sewer pipes.\n"
	   );
  AddOrigDetail(({ "pipe", "pipes", "sewer", "sewer pipes" }),
"A pair of 1 foot diameter sewer pipes.  A constant stream of water flows "
"out of them.\n"
	   );
    
  // Items
  AddItem(ADVENT("o/water"), REFRESH_REMOVE
         , ([ P_WATEREXTRA:
"It flows out of a pair of sewer pipes and out of the door.\n"
           ])
	 );
}

/*************************************************************************/
