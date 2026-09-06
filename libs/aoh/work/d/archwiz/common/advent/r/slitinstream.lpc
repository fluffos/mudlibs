/* Advent - Slit in Streambed -- Mateese, 12-Aug-96
 *
 * Part of the old pregame of Advent, this is here now just to have it.
 * To make clear that this is not part of normal Nightfall, the sky
 * is always of a uniform grey.
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
  Set(P_INT_SHORT, "Slit in Streambed");
  Set(P_INT_LONG,
"At your feet all the water of the stream splashes into a 2-inch slit "
"in the rock. Downstream the streambed is bare rock.\n"
     );
  Set(P_INT_SMELL, "The air smells fresh and cool.\n");
  Set(P_INT_NOISE, 
"A few birds sing in the distance, hardly audible over the flow of the water.\n"
     );
  Set(P_BRIGHT, 90);

  // Exits
  AddExit(({ "east", "west" }), ADVENT("r/forest1"));
  AddExit(({ "north", "up" }), ADVENT("r/valley"));
  AddExit("south", ADVENT("r/outsidegrate"));
  HideExit("up", HIDE_ALWAYS);
  AddNowayMsg("down", "You don't fit through a 2-inch slit!\n");
    
  // Details
  AddOrigDetail(({ "sky", "heaven" }), "It is or a uniform, unearthly grey.\n");
  AddOrigDetail("gully", "An gully in the rock.\n");
  AddOrigDetail(({ "bed", "streambed", "rocky bed", "rocky streambed" }),
"A rocky bed for a stream to tumble along.\n"
	   );
  AddOrigDetail(({"slit", "2-inch slit", "2 inch slit"}), 
"It's just a 2-inch slit in the rock, through which the stream is flowing.\n"
	   );

  // Items
  AddItem(ADVENT("o/water"), REFRESH_REMOVE
         , ([ P_WATEREXTRA:
"The stream flows down the valley and into a 2-inch slit in the streambed.\n"
           ])
	 );
}

/*************************************************************************/
