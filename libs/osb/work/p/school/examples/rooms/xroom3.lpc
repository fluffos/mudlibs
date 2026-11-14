/*   Example Room 3  (Mateese, 29-Sep-92)
**
** This is a sample room featuring a door connected to a door in xroom2.
** Here we also find the right key for the locked door in xroom2.
*/

  /* Include what we need */

#include <properties.h>
#include <doors.h>     /* for the doors */
#include <rooms.h>     /* for the right key */
#include "/p/school/sys/school.h"

inherit "/std/room";

/*------------------------------------------------------------------------*/
void create() 
{
  ::create();

  Set(P_INT_SHORT, "The third example room");

  Set(P_INT_LONG,
"You are in the third example room (/d/archwiz/common/lpc/exm/xroom3.c).\n"
"It features a door west, leading to the second example room.\n"
     );

    /* Now add the door: closed, but unlocked.
    */
  AddDoor("west", EXROOMS("xroom2"), "wooden door",
          "An old wooden door.\n", 0, DOOR_STATUS_CLOSED);

   /* Now place the right key for the locked door in xroom2 here.
   ** The key will be refreshed on every reset if it was taken away.
   */
  AddItem ("/d/archwiz/common/lpc/exm/boguskey", REFRESH_REMOVE);
}

/*------------------------------------------------------------------------*/
