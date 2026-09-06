/* Advent - Dead End Crawl -- Mateese, 19-Aug-96
 *
 * A dead end north of the Large Low Room.
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
  Set(P_INT_SHORT, "Dead End Crawl");
  Set(P_INT_LONG,
"This is a dead end crawl.\n"
     );
  Set(P_BRIGHT, 0);

  // Exits
  AddExit("south", ADVENT("r/lowroom"));
}

/*************************************************************************/
