/* Advent - Sloping Corridor -- Mateese, 24-Aug-96
 *
 * The entrance to the Chasm area from the Large Low Room.
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
  Set(P_INT_SHORT, "Sloping Corridor");
  Set(P_INT_LONG,
"You are in a long winding corridor sloping out of sight in both directions.\n"
     );
  Set(P_BRIGHT, 0);

  // Exits
  AddExit("up", ADVENT("r/lowroom"));
  AddExit("down", ADVENT("r/swchasm"));
  Set(P_NOWAY_MSG, "The corridor slopes steeply up and down.\n");
}

/*************************************************************************/
