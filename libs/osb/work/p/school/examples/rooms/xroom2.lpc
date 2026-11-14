/*   Example Room 2  (Mateese, 20-Jul-96)
**
** Here we play around with two doors and two keys.
** Furthermore we use a special features of the long description and
** of properties in general.
*/

  /* Include what we need */

#include <doors.h>          /* for the doors */
#include <properties.h>     /* for examining the door status */
#include <rooms.h>          /* for the (wrong) key */
#include "/p/school/sys/school.h"  // for the school macros

inherit "/std/room";

/*------------------------------------------------------------------------*/
void create() 
{
  ::create();

  Set(P_INT_SHORT, "The second example room");
  Set(P_INT_LONG,
   "You are in the 'doors' example room. It features two doors, one in "
   "the east wall and one in the west. The latter is locked per default. "
   "There is also a 'normal' exit (without door) to the south.\n"
  );

    /* The normal 'non-door' exit...*/
  AddExit("south", EXROOMS("exroom1"));

    /* Now add the two doors:
    ** the east one closed, but unlocked.
    */
  AddDoor("east", EXROOMS("xroom3"), "wooden door",
          "An old wooden door.\n", 0, LOCK_CLOSED);
    /* arg1: The command to exit via this door, also giving
    **       the direction it leads.
    ** arg2: The room to which the door leads. If in that room a door
    **       with the same <arg3> is defined, both doors are connected
    **       and synchronized automatically.
    ** arg3: A short description of the door. When looking into the room,
    **       the door will appear as "There is a <arg3> to the <arg1> here."
    **       This is also the identification for the remote door.
    ** arg4: The long description, subject to process_string() as
    **       mentioned before (though we don't use it here).
    ** arg5: The Key-id(). Since we don't use one, this is 0.
    ** arg6: The initial status of the door.
    */

    /* The door to the west is special because it has no counterpart
    ** in the other room. So we have to use the more flexible variant
    ** of AddDoor().
    ** Note the appearance of P_OTHERROOM which prevents this entry from 
    ** being filled in by AddDoor().
    */
  AddDoor("west", "/d/archwiz/common/lpc/exm/xroom4"
         , ([ P_SHORT    :"a small door"
            , P_LONG     :"An old small door.\n"
            , P_ADS      : ({ "small" })
            , P_DOORCODE : "small door"
            , P_DIRECTION: "west"
            , P_KEYIDS   : ({ "bogus key" })
            , P_LOCKSTATE: LOCK_LOCKED
            , P_OTHERROOM: 0
           ])
         );

   /* To fool the player, we place a wrong key here.
   ** The key will be refreshed on every reset if it was taken away.
   */
  AddItem("/d/archwiz/common/lpc/exm/weirdkey", REFRESH_REMOVE);
}
