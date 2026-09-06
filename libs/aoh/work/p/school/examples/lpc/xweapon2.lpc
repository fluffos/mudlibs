/* Twohander  (Mateese, 26-Jun-92)
**
** Another example for /std/weapon.
** This one needs two hands to be handled.
**
** The combat system is not complete yet, so is this weapon.
*/

#include <properties.h>   /* for the property names */
#include <combat.h>       /* for the weapon types */

inherit "/std/weapon";

/*-------------------------------------------------------------------------
** Initialize us.
*/

create () {

  ::create();

    /* Authorinfo */
  Set(P_INFO, "Example weapon, by Mateese");

    /* This weapon is rather standard, so let's configure it the standard
    ** way: a sword of WC 12.
    ** This sets ALL, so we adapt the rest afterwards.
    */
  SetStandard (WT_SWORD, 12);

    /* We need a short description */
  Set(P_SHORT, "a twohander");

    /* and also a long one */
  Set(P_LONG, 
"This is another example weapon (/d/archwiz/common/lpc/exm/xweapon2.c).\n" +
"This is a long, heavy sword. You'll two hands to handle it.\n"
     );

    /* Our IDs: 'sword' and 'twohander'. 'sword' is already set by
    ** SetStandard()
    */
  AddId("twohander");

    /* We need two hands to use the sword */
  Set(P_NUMBER_HANDS, 2);

    /* Everything else is standard */
}

/*************************************************************************/
