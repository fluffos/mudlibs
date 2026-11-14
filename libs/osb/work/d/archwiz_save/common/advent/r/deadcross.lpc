/* Advent - Deadend -- Mateese, 17-Aug-96
 *
 * The deadend north of the N/S-E/W-Crossover.
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
  Set(P_INT_SHORT, "Dead End");
  Set(P_INT_LONG,
"You have reached a dead end.\n"
     );
  Set(P_BRIGHT, 0);

  // Exits
  AddExit(({"south", "out" }), ADVENT("r/crossover"));
  HideExit("out", HIDE_ALWAYS);
  Set(P_NOWAY_MSG, "You'll have to go back the way you came.\n");
}

/*************************************************************************/
