/* Advent - In A Valley -- Mateese, 10-Aug-96
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
  Set(P_INT_SHORT, "In A Valley");
  Set(P_INT_LONG,
"You are in a valley in the forest beside a stream tumbling along a rocky bed.\n"
     );
  Set(P_INT_SMELL, "The air smells fresh and cool.\n");
  Set(P_INT_NOISE, 
"A few birds sing in the distance, hardly audible over the flow of the water.\n");
  Set(P_BRIGHT, 90);

  // Exits
  AddExit("north", ADVENT("r/endofroad"));
  AddExit(({ "east", "west", "up" }), ADVENT("r/forest1"));
  AddExit(({ "south", "down" }), ADVENT("r/slitinstream"));
  HideExit(({ "up", "down" }), HIDE_ALWAYS);
    
  // Details
  AddOrigDetail(({ "sky", "heaven" }), "It is or a uniform, unearthly grey.\n");
  AddOrigDetail(({ "forest", "tree", "trees" }),
"The trees of the forest are large hardwood oak and maple, with an "
"occasional grove of pine or spruce. There is quite a bit of undergrowth, "
"largely birch and ash saplings plus nondescript bushes of various sorts. "
"This time of year visibility is quite restricted by all the leaves, but "
"travel is quite easy if you detour around the spruce and berry bushes.\n"
           );
  AddOrigDetail(({ "valley", "deep valley" }), "You're in it.\n");
  AddOrigDetail(({ "bed", "streambed", "rocky bed", "rocky streambed" }),
"A rocky bed for a stream to tumble along.\n"
	   );

  // Items
  AddItem(ADVENT("o/water"), REFRESH_REMOVE
         , ([ P_WATEREXTRA: "It tumbles along a rocky bed.\n" ])
	 );
}

/*************************************************************************/
