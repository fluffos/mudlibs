/* Advent - Canyon Dead End -- Mateese, 19-Aug-96
 *
 * The southern dead end of the N/S Canyon to the Swiss Cheese Room.
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
  Set(P_INT_SHORT, "Canyon Dead End");
  Set(P_INT_LONG,
"The canyon here becomes too tight to go further south.\n"
     );
  Set(P_BRIGHT, 0);

  // Exits
  AddExit("north", ADVENT("r/nscanyon"));
}

/*************************************************************************/
