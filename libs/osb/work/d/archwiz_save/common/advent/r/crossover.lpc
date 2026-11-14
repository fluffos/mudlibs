/* Advent - N/S-E/W-Crossover -- Mateese, 17-Aug-96
 *
 * A crossover of passages between the Long Hall and the West Chamber north
 * of the Hall of Mists.
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
  Set(P_INT_SHORT, "N/S and E/W Crossover");
  Set(P_INT_LONG,
"You are at a crossover of a high N/S passage and a low E/W one.\n"
     );
  Set(P_BRIGHT, 0);

  // Exits
  AddExit("east", ADVENT("r/eastlonghall"));
  AddExit("north", ADVENT("r/deadcross"));
  AddExit("west", ADVENT("r/westchamber"));
  AddExit("south", ADVENT("r/westlonghall"));
    
  // Details
  AddOrigDetail("crossover", "You know as much as I do at this point.\n");
}

/*************************************************************************/
