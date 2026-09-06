/* Advent - Junction with Warm Walls -- Mateese, 25-Aug-96
 *
 * The last junction before the Volcano. East is the Chamber of Boulders
 * with some rare spices.
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
  Set(P_INT_SHORT, "Junction with Warm Walls");
  Set(P_INT_LONG,
"The walls are quite warm here. From the north can be heard a steady roar, "
"so loud that the entire cave seems to be trembling. Another passage leads "
"south, and a low crawl goes east.\n"
     );
  Set(P_BRIGHT, 0);
  Set(P_INT_NOISE, "A loud roar flows in from the north.\n");
  Set(P_NODWARF, 1);
    
  // Exits
  AddExit("north", ADVENT("r/volcano"));
  AddExit("south", ADVENT("r/forkinpath"));
  AddExit("east", ADVENT("r/boulders"));
}

/*************************************************************************/
