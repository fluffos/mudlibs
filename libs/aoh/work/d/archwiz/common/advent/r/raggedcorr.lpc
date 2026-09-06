/* Advent - Ragged Corridor -- Mateese, 22-Aug-96
 *
 * The corridor down from the Shell Room, leading to the Cul-de-Sac.
 */

#include <properties.h>
#include <rooms.h>
#include <moving.h>
#include "advent.h"

inherit ADVENT("i/stdroom");

/*-----------------------------------------------------------------------*/
public void create()
{
  ::create();

  // Main description
  Set(P_INT_SHORT, "Ragged Corridor");
  Set(P_INT_LONG,
"You are in a long sloping corridor with ragged sharp walls.\n"
     );
  Set(P_BRIGHT, 0);

  // Exits
  AddExit("up", ADVENT("r/shellroom"));
  AddExit("down", ADVENT("r/culdesac"));
}

/*************************************************************************/
