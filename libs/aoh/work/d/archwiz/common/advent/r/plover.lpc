/* Advent - Plover -- Mateese, 21-Aug-96
 *
 * The Plover with the Emerald.
 * Northeast is the Dark Room with the Platinum Bars.
 * To enter/leave the Plover Room, the player must carry at max one item (not
 * counting autoloaders).
 */

#include <config.h>
#include <properties.h>
#include <rooms.h>
#include <moving.h>
#include "advent.h"

inherit ADVENT("i/stdroom");

/*-----------------------------------------------------------------------*/
public int CheckAction (string action, string verb, string arg, int method)

/* We interfere with the movement if the player tries to enter the Plover
 * Room with too much in his pack.
 * Note that this way we don't need to do the movement with all
 * its checks ourselves.
 */
{
  if ("exit" == action && "west" == verb)
  {
    object *obj;
      
    obj = deep_inventory(this_player());
    obj -= filter_objects(obj, "Query", P_AUTOOBJECT);
    if (sizeof(obj) > 1)
    {
      notify_fail(
  "Something you're carrying won't fit through the tunnel with you.\n"
		 );
      return 0;
    }
  }
  return ::CheckAction(action, verb, arg, method);
}

/*-----------------------------------------------------------------------*/
public void create()
{
  ::create();

  // Main description
  Set(P_INT_SHORT, "Plover Room");
  Set(P_INT_LONG,
"You're in a small chamber lit by an eerie green light. An extremely narrow "
"tunnel exits to the west. A dark corridor leads northeast.\n"
     );
  Set(P_BRIGHT, MAX_SUNBRIGHT/4);

  // Exits
  AddExit("northeast", ADVENT("r/darkroom"));
  AddExit("west", ADVENT("r/alcove"));
  CheckExit("west", DACT_CHECK);
    
  // Items
  AddItem(ADVENT("o/treasure"), REFRESH_REMOVE
	 , ([ P_SHORT: "a large emerald"
            , P_LONG: 
"An emerald of the size of a plover's egg (which are, by the way, quite large).\n"
            , P_IDS: ({ "emerald" })
            , P_ADS: ({ "large" })
            , P_WEIGHT: 3000
            , P_VALUE: 930
            , P_TREASURE: F_EMERALD
            , P_XP: 1600
           ])
	 );
}

/*************************************************************************/
