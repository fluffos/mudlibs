/* Advent - Soft Room -- Mateese, 21-Aug-96
 *
 * The Soft Room, sort of south of Bedquilt, accessible from the Swiss Cheese
 * Room to the west.
 * The Velvet Pillow which is needed to safely drop the Ming Vase is here.
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
  Set(P_INT_SHORT, "Soft Room");
  Set(P_INT_LONG,
"You are in the soft room. The walls are covered with heavy curtains, "
"the floor with a thick pile carpet. Moss covers the ceiling.\n"
     );
  Set(P_BRIGHT, 0);

  // Exits
  AddExit("west", ADVENT("r/swisscheese"));

  AddRoomCmd(({ "search", "eat" }), "fdetails");

  // Details
  AddOrigDetail(({"carpet", "thick carpet", "pile carpet", "thick pile carpet" }),
"The carpet is quite plush.\n"
	   );
  AddOrigDetail(({"curtain", "curtains", "heavy curtain", "heavy curtains" }),
"They seem to absorb sound very well.\n"
	   );
  AddOrigDetail("moss", "It just looks like your typical, everyday moss.\n");
    
  // Items
  AddItem("/std/thing", REFRESH_REMOVE
	 , ([ P_SHORT: "a velvet pillow"
            , P_LONG: "It's just a small velvet pillow.\n"
            , P_WEIGHT: 500
            , P_VALUE: 20
            , P_IDS: ({ "pillow", "cushion" })
            , P_ADS: ({ "small", "velvet" })
           ])
	 );
}

/*-----------------------------------------------------------------------*/
public int fdetails (string arg)

/* A generic function to handle some actions on the details here.
 */

{
  if (!arg)
    return 0;

  if (query_verb() == "search" && -1 != strstr(arg, "curtain"))
  {
    write("You don't find anything exciting behind the curtains.\n");
    return 1;
  }

  if (query_verb() == "eat" && -1 != strstr(arg, "moss"))
  {
    write("Eeeewwwww.\n");
    return 1;
  }

  return 0;
}

/*************************************************************************/
