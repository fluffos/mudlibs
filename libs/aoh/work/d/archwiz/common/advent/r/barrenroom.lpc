/* Advent - Barren Room -- Mateese, 26-Aug-96
 *
 * The Barren Room with the Bear and the Golden Chain.
 * To unlock and take the golden chain, the bear must be fed.
 */

#include <properties.h>
#include <rooms.h>
#include <moving.h>
#include "advent.h"

inherit ADVENT("i/stdroom");

/*-----------------------------------------------------------------------*/
public string BearExtraLong()
{
  object bear;
    
  bear = present(ADV_BEAR, this_object());
  if (!bear)
    return "";
  if (QueryFlag(F_BEAR))
    return "There is a gentle cave bear sitting placidly in one corner.\n";
  return 
"There is a ferocious cave bear eyeing you from the far end of the room.\n";
}

/*-----------------------------------------------------------------------*/
public void create()
{
  ::create();

  // Main description
  Set(P_INT_SHORT, "Barren Room");
  Set(P_INT_LONG,
"You are inside a barren room. The center of the room is completely empty "
"except for some dust. Marks in the dust lead away toward the far end of "
"the room. The only exit is the way you came in.\n"
     );
  SetExtraEntry("broom extra long", P_INT_LONG, #'BearExtraLong);
  Set(P_BRIGHT, 0);
  Set(P_NODWARF, 1);
    
  // Exits
  AddExit("west", ADVENT("r/frontbarren"));

  // Details
 AddOrigDetail(({ "dust", "marks" }), "It just looks like ordinary dust.\n");

  // Items
  AddItem(ADVENT("o/cavebear"), REFRESH_DESTRUCT|REFRESH_HOME);
  AddItem(ADVENT("o/goldenchain"), REFRESH_REMOVE);
}

/*************************************************************************/
