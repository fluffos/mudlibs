/*   Example Room 7  (Mateese, 29-Sep-92)
**
** This is an outdoors room with background illumination.
*/

#include <properties.h>

inherit "/std/room";

void create() 
{

  ::create();

  Set(P_INT_SHORT, "The 'outdoors' example room with illumination");

  Set(P_INT_LONG,
"You are in another 'outdoors' exm. room.\n"
"This one features a steady background illumination.\n"
"You are standing on a small place under the clear sky.\n"
"The place extends to the north, where some buildings can be seen. "
"There is a lantern here, giving some light.\n"
     );

  AddExit("north", "/d/archwiz/common/lpc/exm/xroom6");

  AddDetail("lantern",
"The lantern shines dimly. It is securely mounted to the ground.\n"
           );

    /* Mark this room as being outdoors.
    ** This also takes care of setting the light.
    */
  Set(P_INDOORS, 0);

    /* Set the background illumination by the lantern, additional to 
    ** the sunlight.
    */
  Set(P_BRIGHT, 4);
}

