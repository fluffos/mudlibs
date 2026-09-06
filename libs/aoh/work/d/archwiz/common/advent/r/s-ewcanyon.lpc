/* Advent - Secret E/W Canyon -- Mateese, 19-Aug-96
 *
 * The secret canyon between the Hall of the Mt. King and the Secret Canyon
 * with the dragon.
 * Using the canyon below one can get back to Swiss Cheese Room.
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
  Set(P_INT_SHORT, "Secret E/W Canyon");
  Set(P_INT_LONG,
"You are in a secret canyon which here runs E/W. It crosses over a very tight "
"canyon 15 feet below. If you go down, you may not be able to get back up.\n"
     );
  Set(P_BRIGHT, 0);

  // Exits
  AddExit("east", ADVENT("r/hallmtking"));
  AddExit("west", ADVENT("r/s-canyon"));
  AddExit("down", ADVENT("r/nscanyon"));
}

/*************************************************************************/
