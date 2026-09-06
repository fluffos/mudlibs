/* Advent - Secret N/S Canyon 1 -- Mateese, 19-Aug-96
 *
 * Connecting Bedquilt and the Junction of Three, one can reach the
 * Top of Stalactite here and enter the Alike Maze.
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
  Set(P_INT_SHORT, "Secret N/S Canyon");
  Set(P_INT_LONG,
"You are in a secret N/S canyon above a sizeable passage.\n"
     );
  Set(P_BRIGHT, 0);

  // Exits
  AddExit("north", ADVENT("r/threejunct"));
  AddExit("south", ADVENT("r/atopstalac"));
  AddExit("down", ADVENT("r/bedquilt"));
}

/*************************************************************************/
