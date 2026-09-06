/* Advent - Secret Canyon -- Mateese, 19-Aug-96
 *
 * The secret canyon between the Hall of the Mountain King and Bedquilt.
 * The dragon and the oriental rug is here.
 * As long as the dragon is here, the player can use just the exit it
 * came in.
 */

#include <properties.h>
#include <rooms.h>
#include <moving.h>
#include "advent.h"

inherit ADVENT("i/stdroom");

#define P_ALLOWED "AdvDragonAllowed"

/*-----------------------------------------------------------------------*/
public int CheckAction (string action, string verb, string arg, int method)

/* We interfere with the movement if the player tries to use a different
 * exit than it used to come in, given that the dragon is present.
 */
{
  if ("exit" == action 
   && stringp(this_player()->Query(P_ALLOWED))
   && this_player()->Query(P_ALLOWED) != verb
   && present(ADV_DRAGON, this_object())
     )
  {
    notify_fail("The dragon looks rather nasty. You'd best not try to get by.\n");
    return 0;
  }
  return ::CheckAction(action, verb, arg, method);
}

/*-----------------------------------------------------------------------*/
public void create()
{
  ::create();

  // Main description
  Set(P_INT_SHORT, "Secret Canyon");
  Set(P_INT_LONG,
"You are in a secret canyon which exits to the north and east.\n"
     );
  Set(P_BRIGHT, 0);

  // Exits
  AddExit("north", ADVENT("r/s-nscanyon0"));
  AddExit("east", ADVENT("r/s-ewcanyon"));
  CheckExit(({"north", "east"}), DACT_CHECK);

  // Items
  AddItem(ADVENT("o/dragon"), REFRESH_DESTRUCT|REFRESH_HOME);
  AddItem(ADVENT("o/rug"), REFRESH_REMOVE);
}

/*-----------------------------------------------------------------------*/
public varargs void notify_enter(object from, int method, mixed extra)
{
  if (M_GO == method && previous_object()->Query(P_IS_LIVING) && from)
  {
    if (to_string(from) == ADVENT("r/s-nscanyon0"))
      previous_object()->Set(P_ALLOWED, "north");
    if (to_string(from) == ADVENT("r/s-ewcanyon"))
      previous_object()->Set(P_ALLOWED, "east");
  }
  ::notify_enter(from, method, extra);
}

public varargs void notify_leave(mixed to, int method, mixed extra)
{
  previous_object()->Set(P_ALLOWED, 0);
  ::notify_leave(to, method, extra);
}

/*************************************************************************/
