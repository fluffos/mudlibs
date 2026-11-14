/* Advent - Alcove -- Mateese, 21-Aug-96
 *
 * The Alcove before the Emerald in the Plover Room and the Pyramid
 * in the Dark Room.
 * To enter the Plover Room, the player must carry at max one item (not
 * counting autoloaders).
 */

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
  if ("exit" == action && "east" == verb)
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
  Set(P_INT_SHORT, "Alcove");
  Set(P_INT_LONG,
"You are in an alcove. A small northwest path seems to widen after a short "
"distance. An extremely tight tunnel leads east. It looks like a very tight "
"squeeze. An eerie light can be seen at the other end.\n"
     );
  Set(P_BRIGHT, 1);

  // Exits
  AddExit("northwest", ADVENT("r/mistycavern"));
  AddExit("east", ADVENT("r/plover"));
  CheckExit("east", DACT_CHECK);
}

/*************************************************************************/
