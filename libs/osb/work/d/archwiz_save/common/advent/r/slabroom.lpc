/* Advent - Slab Room -- Mateese, 19-Aug-96
 *
 * The Slab Room west-northwest of the Twopit Room. North is the Bedquilt,
 * up the Secret N/S Canyon 0.
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
  Set(P_INT_SHORT, "Slab Room");
  Set(P_INT_LONG,
"You are in a large low circular chamber whose floor is an immense slab "
"fallen from the ceiling. East and west there once were large passages, "
"but they are now filled with boulders. Low small passages go north and south, "
"and the south one quickly bends west oround the boulders.\n"
     );
  Set(P_BRIGHT, 0);

  // Exits
  AddExit("north", ADVENT("r/bedquilt"));
  AddExit("up", ADVENT("r/s-nscanyon0"));
  AddExit("south", ADVENT("r/westtwopit"));
 
  // Details
  AddOrigDetail(({ "boulders", "rocks", "stones" })
           , "They're just ordinary boulders.\n"
           );
  AddOrigDetail(({ "slab", "immense slab" }), "It is now the floor here.\n");
}

/*************************************************************************/
