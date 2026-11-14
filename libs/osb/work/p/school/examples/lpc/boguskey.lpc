/*   A bogus key (Mateese, 09-Aug-1994)
**
** This key fits into the lock of the door in xroom2.
*/

#include <properties.h>

inherit "/std/thing";

  /* Inititalize us */
create() 
{
  ::create();

    /* We need a short description */
  Set(P_SHORT, "a bogus key");

    /* also a long one */
  Set(P_LONG, "A really bogus key.\n");

    /* We have a weight of 100 grams.
    ** Note that the old obj/treasure (implicitely) counted in kilograms.
    */
  Set(P_WEIGHT, 100);

    /* We also have a value of 10 coins.
  Set(P_VALUE, 10);

    /* This key reacts just on "bogus key". This is bad practice, though. */
  AddId("bogus key");

    /* No special keycode necessary */
}

/* that's all */
