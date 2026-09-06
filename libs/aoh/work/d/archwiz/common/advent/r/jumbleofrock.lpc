/* Advent - Jumble Of Rock -- Mateese, 18-Aug-96
 *
 * Just a jumble of rocks, east/up of Y2. Further up is the Hall of Mists.
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
  Set(P_INT_SHORT, "Jumble of Rock");
  Set(P_INT_LONG,
"You are in a jumble of rock, with cracks everywhere.\n"
     );
  Set(P_BRIGHT, 0);
    
  // Exits
  AddExit("down", ADVENT("r/y2"));
  AddExit("up", ADVENT("r/hallofmists"));
}

/*************************************************************************/
