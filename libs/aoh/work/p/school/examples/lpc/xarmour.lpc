/* Paratrooper Boots  (Mateese, 15-Jun-92)
**
** An example for /std/armour.
** As you'll see, /std/armour is just another child of /std/thing.
*/

#include <properties.h>   /* for the property names */
#include <combat.h>       /* for the armour types */

inherit "/std/armour";

/*-------------------------------------------------------------------------
** Initialize us.
*/

create () {

  ::create();

    /* This armour is rather standard, so we use a standard setting:
    ** Boots of AC 1
    */
  SetStandard(AT_BOOTS, 1);

    /* We need a short description */
  Set(P_SHORT, "Paratrooper Boots");

    /* and also a long one */
  Set(P_LONG,
"This is an example armour (/d/archwiz/common/lpc/exm/xarmour.c).\n" +
"A pair of combat boots as they were worn by paratroopers.\n"
         );

    /* Our IDs: 'boots', 'paratrooper boots' and 'para boots'
    ** 'boots' has already been set by SetStandard() 
    */
  AddAdjective("para");
  AddAdjective("paratrooper");
}

/*************************************************************************/

