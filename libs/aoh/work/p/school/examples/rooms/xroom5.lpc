/*   Example Room 5  (Mateese, 29-Sep-92)
**
** This is a simple indoors room.
*/

#include <properties.h>
#include "/p/school/sys/school.h"

inherit "/std/room";

void create() 
{
  ::create();

  Set(P_INT_SHORT, "The 'indoors' example room");

  Set(P_INT_LONG, 
"You are in the 'indoors' example room (/d/archwiz/common/lpc/exm/xroom5.c).\n"
"You see nothing but exits to the east and west.\n"
"The western exit leads back into the example dungeon, the eastern leads\n"
"outside.\n"
     );

  AddExit ("west", "/d/archwiz/common/lpc/exm/xroom1");
  AddExit ("east", "/d/archwiz/common/lpc/exm/xroom6");

  /* No need to set the light - there is an automatic lighting of 75% sunlight.
  ** A Set(P_INT_LIGHT) or Set(P_BRIGHT) would switch the automatic lighting 
  ** off.
  */

}

