/* Advent - Outside Grate -- Mateese, 12-Aug-96
 *
 * Part of the old pregame of Advent, this is here now just to have it.
 * To make clear that this is not part of normal Nightfall, the sky
 * is always of a uniform grey.
 * Here the players return to the Nightfall-Advent area.
 */

#include <properties.h>
#include <rooms.h>
#include <moving.h>
#include "advent.h"

inherit ADVENT("i/stdroom");

/*-----------------------------------------------------------------------*/
public int ExitDown (string arg)
{
  if (arg)
    return 0;
  if (ME_OK != this_player()->move(ADVENT("r/trdump"), M_SPECIAL
				  , ({
"leaves down through the half-open grate"
,"enters from one unseen hole"
,"squeeze yourself past the half-open grate down"
				    }))
     )
    raise_error("Move to "+ADVENT("r/trdump")+" failed.\n");
  return 1;
}

/*-----------------------------------------------------------------------*/
void create()
{
  ::create();

  // Main description
  Set(P_INT_SHORT, "Outside Grate");
  Set(P_INT_LONG,
"You are in a 20-foot depression floored with bare dirt. Set into the dirt "
"is a strong steel grate mounted in concrete. A dry streambed leads into "
"the depression.\n"
     );
  Set(P_INT_SMELL, "The air smells slightly stale.\n");
  Set(P_INT_NOISE, "Everything is silent.\n");
  Set(P_BRIGHT, 90);

  // Exits
  AddExit(({ "west", "west", "south" }), ADVENT("r/forest1"));
  AddExit(({"north", "up"}), ADVENT("r/slitinstream"));
  AddExit("down", #'ExitDown);
  HideExit(({ "up", "down" }), HIDE_ALWAYS);
    
  // Details
  AddOrigDetail(({ "sky", "heaven" }), "It is or a uniform, unearthly grey.\n");
  AddOrigDetail("gully", "A gully in the rock.\n");
  AddOrigDetail(({ "bed", "streambed", "rocky bed", "rocky streambed" }),
"A rocky bed for a stream to tumble along.\n"
	   );
  AddOrigDetail(({ "grate", "steel grate" }),
"It is a 3*3 steel grate mounted in concrete, rust affixing it in a half-open "
"position. Below the grate, a faint glow is visible in the darkness.\n"
           );
}

/*************************************************************************/
