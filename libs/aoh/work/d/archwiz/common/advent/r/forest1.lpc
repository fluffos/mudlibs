/* Advent - In Forest 1 -- Mateese, 12-Aug-96
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
public int ExitSouth (string arg)

/* There is a 50% chance to enter forest2 instead of forest1.
 * Originally this was bound to the command 'forest'.
 */
{
  object forest2;

  if (arg)
    return 0;
  forest2 = load_object(ADVENT("r/forest2"));
  if (!forest2 
   || random(100) <= 50 
   || ME_OK != this_player()->move(forest2, M_GO)
    )
    this_player()->move(this_object(), M_GO);
  return 1;
}

/*-----------------------------------------------------------------------*/
void create()
{
  ::create();

  // Main description
  Set(P_INT_SHORT, "In Forest");
  Set(P_INT_LONG,
"You are in open forest, with a deep valley to one side.\n"
     );
  Set(P_INT_SMELL, "The air smells fresh and cool.\n");
  Set(P_INT_NOISE, "A few birds sing in the distance, else it is silent.\n");
  Set(P_BRIGHT, 90);

  // Exits
  AddExit(({ "west", "north" }), ADVENT("r/forest1"));
  AddExit(({ "east", "down" }), ADVENT("r/valley"));
  AddExit("south", #'ExitSouth);
  HideExit("down", HIDE_ALWAYS);
    
  // Details
  AddOrigDetail(({ "sky", "heaven" }), "It is or a uniform, unearthly grey.\n");
  AddOrigDetail(({ "valley", "deep valley" }), "A deep valley like of a stream.\n");
  AddOrigDetail(({ "forest", "tree", "trees" }),
"The trees of the forest are large hardwood oak and maple, with an "
"occasional grove of pine or spruce. There is quite a bit of undergrowth, "
"largely birch and ash saplings plus nondescript bushes of various sorts. "
"This time of year visibility is quite restricted by all the leaves, but "
"travel is quite easy if you detour around the spruce and berry bushes.\n"
           );
}

/*************************************************************************/
