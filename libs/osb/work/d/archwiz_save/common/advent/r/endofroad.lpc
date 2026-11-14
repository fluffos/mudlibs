/* Advent - End Of Road -- Mateese, 10-Aug-96
 *
 * Part of the old pregame of Advent, this is here now just to have it.
 * To make clear that this is not part of normal Nightfall, the sky
 * is always of a uniform grey.
 * This was the old starting point.
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
  Set(P_INT_SHORT, "End Of Road");
  Set(P_INT_LONG,
"You are standing at the end of a road before a small brick building.\n"
"Around you is a forest. A small stream flows out of the building "
"and down a gully.\n"
     );
  Set(P_INT_SMELL, "The air smells fresh and cool.\n");
  Set(P_INT_NOISE, "A few birds sing in the distance, else it is silent.\n");
  Set(P_BRIGHT, 90);

  // Exits
  AddExit(({ "west", "up" }), ADVENT("r/hillinroad"));
  AddExit(({ "east", "in" }), ADVENT("r/building"));
  AddExit(({ "south", "down" }), ADVENT("r/valley"));
  AddExit( "north", ADVENT("r/forest1"));
  HideExit(({ "up", "in", "down" }), HIDE_ALWAYS);
    
  // Details
  AddOrigDetail(({ "sky", "heaven" }), "It is or a uniform, unearthly grey.\n");
  AddOrigDetail("gully", "A gully in the rock.\n");
  AddOrigDetail(({"building", "house" }),
"It's a small brick building. It seems to be a well house.\n"
	   );
  AddOrigDetail(({ "road", "street", "path" }),
"A road leading through the forest.\n"
           );
  AddOrigDetail(({ "forest", "tree", "trees" }),
"The trees of the forest are large hardwood oak and maple, with an "
"occasional grove of pine or spruce. There is quite a bit of undergrowth, "
"largely birch and ash saplings plus nondescript bushes of various sorts. "
"This time of year visibility is quite restricted by all the leaves, but "
"travel is quite easy if you detour around the spruce and berry bushes.\n"
           );
  // Items
  AddItem(ADVENT("o/water"), REFRESH_REMOVE
         , ([ P_WATEREXTRA:
"It flows out of the door of the building and into a gully.\n" 
           ])
	 );
}

/*************************************************************************/
