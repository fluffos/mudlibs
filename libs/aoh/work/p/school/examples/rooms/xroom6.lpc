/*   Example Room 6  (Mateese, 29-Sep-92)
**
** This is a simple outdoors room.
*/

#include <properties.h>
#include "/p/school/sys/school.h"

inherit "/std/room";

void create() 
{

  ::create();

  Set(P_INT_SHORT, "The 'outdoors' example room");

  Set(P_INT_LONG,
"You are in the 'outdoors' example room.\n"
"You are standing on a small place under the clear sky.\n"
"To the west and north are buildings, the place itself extends to the south. "
"A path leads east into a forest.\n"
     );

  AddExit("north", "/d/archwiz/common/lpc/exm/xroom8");
  AddExit("west", "/d/archwiz/common/lpc/exm/xroom5");
  AddExit("east", "/d/archwiz/common/lpc/exm/xroom9");
  AddExit("south", "/d/archwiz/common/lpc/exm/xroom7");

   /* Mark this room as being outdoors.
   ** This switches off the automatic lighting - the sun will light
   ** the room now.
   */
  Set(P_INDOORS, 0);

   /* If you want a different server instead of the default NIGHTDAY,
   ** a 'Set(P_SERVER, <servername>)' needs to be done.
   ** The two calls to Set(P_INDOORS) and Set(P_SERVER) may be combined
   ** to 'Set(P_OUTDOORS, <servername>)'.
   */
}

