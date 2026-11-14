/* Advent - Steep Incline -- Mateese, 20-Aug-96
 *
 * A steep incline east/south of the Cavern with Waterfall.
 * The player may enter the Large Low Room from here.
 */

#include <properties.h>
#include <rooms.h>
#include <moving.h>
#include "advent.h"

inherit ADVENT("i/stdroom");

/*-----------------------------------------------------------------------*/
public int ExitClimb (string arg)

/* If the players tries to climb/jump up down, transform it silently into
 * an 'down' movement.
 */

{
  if (!arg)
  {
    notify_fail(capitalize(query_verb())+" what or where?\n");
    return 0;
  }

  if (!sizeof(norm_id(arg, 1) & ({ "down" }) ) )
  {
    notify_fail("That won't help.\n");
    return 0;
  }
  return UseExit("down", 0, M_GO);
}

/*-----------------------------------------------------------------------*/
public void create()
{
  ::create();

  // Main description
  Set(P_INT_SHORT, "Steep Incline");
  Set(P_INT_LONG,
"You are at the top of a steep incline above a large room. You could climb "
"down here, but you would not be able to climb up. There is a passage leading "
"back to the north.\n"
     );
  Set(P_BRIGHT, 0);

  // Exits
  AddExit("north", ADVENT("r/waterfall"));
  AddExit("down", ADVENT("r/lowroom"));
  AddExit("climb", #'ExitClimb);
  HideExit("climb", HIDE_ALWAYS);
}

/*************************************************************************/
