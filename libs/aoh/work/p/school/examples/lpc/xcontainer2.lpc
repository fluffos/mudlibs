/* /d/archwiz/common/lpc/exm/xcontainer2
**
** A sturdy safe. In fact, a modified chest.
*/

#include <properties.h>
#include <lock.h>

inherit "/obj/chest";

/*-------------------------------------------------------------------------
** Initialize us.
*/

create () {
    /* Initialize it.
     */
  chest::create();

    /* Set the descriptions and such. You should know this already.
     */
  Set(P_SHORT, "a sturdy safe");
  Set(P_INT_SHORT, "inside a sturdy safe");
  SetLong ("This a sturdy safe (/d/archwiz/common/lpc/exm/xcontainer2.c)\n"
          +"It shows, how an openable thing might be built. In fact, it "
          +"is a descendant of /obj/chest.\n");
  Set(P_INT_LONG, "You are inside a sturdy safe.\n");
  Set(P_PRECONTENT, "It contains:\n");
  Set(P_VALUE, 2000);
  Set(P_WEIGHT, 50000);
  Set(P_MAX_WEIGHT, 100000);

    /* If the safe is closed, it is opaque.
     */
  Set(P_TRANSPARENCY, 0);

    /* The chest added 'chest' as id. Undo that and set the id
     * to 'safe', with the adjective 'sturdy'.
     */
  Set(P_IDS, 0 );
  AddId("safe");
  AddAdjective("sturdy");

   /* It is closed by default.
    */
  Set(P_LOCKSTATE, LOCK_CLOSED);
}

/*************************************************************************/
