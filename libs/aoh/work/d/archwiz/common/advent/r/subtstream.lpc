/* Advent - Subterranean Streambed -- Mateese, 14-Aug-96
 *
 * The water stream flows from north to south through the tunnel.
 * This mimicks the original room In A Valley.
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
  Set(P_INT_SHORT, "Subterranean Streambed");
  Set(P_INT_LONG,
"You are in a low subterranean tunnel. A stream of clear water tumbles along "
"in a rocky bed towards the south.\n"
     );
  Set(P_INT_SMELL, "The air smells fresh and cool.\n");
  Set(P_INT_NOISE, "It is silent, except for the flow of the water.\n");
  Set(P_BRIGHT, 0);
  Set(P_NODWARF, 1);
  Set(P_NOORIG, 1);

  // Exits
  AddExit("north", ADVENT("r/subtwell"));
  AddExit("south", ADVENT("r/subtslit"));
    
  // Details
  AddDetail(({ "bed", "streambed", "rocky bed", "rocky streambed" }),
"A rocky bed for a stream to tumble along.\n"
	   );
    
  // Items
  AddItem(ADVENT("o/water"), REFRESH_REMOVE
         , ([ P_WATEREXTRA: "It tumbles along a rocky bed.\n" ])
	 );
}

/*************************************************************************/
