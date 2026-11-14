/* Advent - Cul-de-Sac -- Mateese, 22-Aug-96
 *
 * The down end of the corridor descending from the Shell Room.
 * The player will find the pearl from the clam here.
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
  Set(P_INT_SHORT, "Cul-de-Sac");
  Set(P_INT_LONG,
"You are in a cul-de-sac about eight feet across.\n"
     );
  Set(P_BRIGHT, 0);

  // Exits
  AddExit("up", ADVENT("r/raggedcorr"));
}

/*************************************************************************/
