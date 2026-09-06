/* Advent - West End of Long Hall -- Mateese, 17-Aug-96
 *
 * East of here is the Hall of Mists, south the Different Maze.
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
  Set(P_INT_SHORT, "West End of Long Hall");
  Set(P_INT_LONG,
"You are at the west end of a very long featureless hall. The hall joins "
"up with a narrow north/south passage.\n"
"There is a note besides the south entrance, saying 'Mapper's Nightmare'.\n"
     );
  Set(P_BRIGHT, 0);
  Set(P_VMASTER, ADVENT("r/diffmaze"));
    
  // Details
  AddOrigDetail("note", "The note says, 'Mapper's Nightmare'.\n");

  // Exits
  AddExit("east", ADVENT("r/eastlonghall"));
  AddExit("north", ADVENT("r/crossover"));
  AddExit("south", ADVENT("r/dmaze01"));
}

/*************************************************************************/
