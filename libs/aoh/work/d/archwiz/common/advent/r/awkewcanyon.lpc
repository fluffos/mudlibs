/* Advent - Awkward Sloping E/W Canyon -- Mateese, 15-Aug-96
 *
 * The connection between the Debris Room and the Bird Chamber.
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
  Set(P_INT_SHORT, "Sloping E/W Canyon");
  Set(P_INT_LONG,
"You are in an awkward sloping E/W canyon.\n"
     );
  Set(P_BRIGHT, 0);
  Set(P_NODWARF, 1);
    
  // Exits
  AddExit(({ "east", "down" }), ADVENT("r/debrisroom"));
  AddExit(({ "west", "up" }), ADVENT("r/birdchamber"));
  HideExit(({ "up", "down" }), HIDE_ALWAYS);
}

/*************************************************************************/
