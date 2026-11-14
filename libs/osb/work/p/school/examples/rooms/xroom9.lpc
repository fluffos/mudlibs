/*   Example Room 9  (Mateese, 29-Sep-92)
**
** This is an outdoors room with dimmed daylight.
*/

#include <config.h>
#include <properties.h>

inherit "/std/room";

void create() 
{
  ::create();

  Set(P_INT_SHORT, "The 'outdoors' example room with dimmed daylight");

  Set(P_INT_LONG,
"You are in another 'outdoors' exm. room (/d/archwiz/common/lpc/exm/xroom9.c).\n"
"This one features a dimmed daylight.\n"
"You are in a thick forest. You can hardly see the sky.\n"
"A path leads west from here.\n"
     );

  AddExit("west", "/d/archwiz/common/lpc/exm/xroom6");

    /* Mark this room as being outdoors.
    ** This also takes care of setting the light.
    */
  Set(P_INDOORS, 0);

    /* This is thick forest, so let the sun shine with half power.
    ** This must be done after the call to SetIndoors(0) since that
    ** also does an SetSunBright().
    */
  Set(P_SUNBRIGHT, MAX_SUNBRIGHT / 2);
}

