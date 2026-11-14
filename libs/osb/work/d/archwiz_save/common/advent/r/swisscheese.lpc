/* Advent - Swiss Cheese Room -- Mateese, 19-Aug-96
 *
 * The west of the three vital junctions in the lower cave.
 * East are Bedquilt and the Complex Junction, west the Twopit Room.
 */

#include <properties.h>
#include <rooms.h>
#include <moving.h>
#include "advent.h"

inherit ADVENT("i/stdroom");

/*-----------------------------------------------------------------------*/
public int CheckAction (string action, string verb, string arg, int method)
{
  if ("exit" == action 
   && (   ("south" == verb && random(100) <= 80)
       || ("northwest" == verb && random(100) <= 50)
      )
     )
    return 0;
  return ::CheckAction(action, verb, arg, method);
}

/*-----------------------------------------------------------------------*/
public void create()
{
  ::create();

  // Main description
  Set(P_INT_SHORT, "Swiss Cheese Room");
  Set(P_INT_LONG,
"You are in a room whose walls resemble swiss cheese. Obvious passages "
"go west, east, northeast and northwest. Part of the room is occupied by "
"a large bedrock block.\n"
     );
  Set(P_BRIGHT, 0);
    
  // Exits
  AddExit("west", ADVENT("r/easttwopit"));
  AddExit("south", ADVENT("r/tallewcanyon"));
  AddExit("northeast", ADVENT("r/bedquilt"));
  AddExit("northwest", ADVENT("r/oriental"));
  AddExit("east", ADVENT("r/softroom"));
  CheckExit(({ "south", "northwest" }), DACT_CHECK);

  Set(P_NOWAY_MSG, 
"You have crawled around in some little holes and wound up back in the main "
"passage.\n"
     );
    
  // Details
  AddOrigDetail(({ "block", "large block", "bedrock", "large bedrock" })
	   , "It's just a huge block.\n");
}

/*************************************************************************/
