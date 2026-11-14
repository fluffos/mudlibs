/* Magic Shield  (Mateese, 20-Jul-96)
**
** Another example for /std/armour.
*/

#include <properties.h>   /* for the property names */
#include <combat.h>       /* for the armour types */
#include <equipment.h>    /* for the EWF_ flags */

inherit "/std/armour";

/*-------------------------------------------------------------------------
** Initialize us.
*/

create () {

  ::create();

    /* We need a short description */
  Set(P_SHORT, "a magic shield");

    /* and also a long one */
  Set(P_LONG,
"This is an example armour (/d/archwiz/common/lpc/exm/xarmour2.c).\n"
"A tall silver shield. Your sensitive mind feel a certain touch of ...\n"
" ... magic ...\n"
         );

    /* Our IDs: 'shield', 'magic shield' and 'silver shield'
    ** 'shield' will be set by SetAT() 
    */
  AddAdjective("silver");
  AddAdjective("magic");

    /* Value and Weight */
  Set(P_VALUE, 10000);
  Set(P_WEIGHT, 10000);

    /* Our Armour type, also adds the ID 'shield' */
  Set(P_ARMOUR_TYPE, AT_SHIELD);
 
    /* Set our defences: 
    **   common defence: 10 - also sets everything else to 0
    **   against slashes: +20
    **   against pierces: + 5
    **   against bludges: +10
    */

  Set(P_AC, 10);
  SetDefence(DT_SLASH   , 20); 
  SetDefence(DT_PIERCE  ,  5); 
  SetDefence(DT_BLUDGEON, 10); 

    /* We want to issue a message on wearing, removing and defending.
    ** For wearing and removing, we just need to implement NotifyWear()
    ** and NotifyUnwear() (we don't need to use P_WEAR_OBJ et al).
    ** For defending, we could either overload Defend(), or, as it's done
    ** here, set ourselves as DefendObject.
    */

    /* On defendig, call DefendHit() */
  SetDefendObj(this_object());

}

/*-------------------------------------------------------------------------
** The 'NotifyWear()' function is to do things after wearing the armour,
** like giving messages.
** For extra checks before wearing, use the function ChkWear().
** Analogous for Unwearing.
*/

void NotifyWear (object wearer, object armour, int flags) {
  if (!(flags & EWF_SILENT))
  {
    write("As you touch the shield, it emits a faint glow.\n");
    say("Something weird happened.\n");
  }
}

void NotifyUnwear (object wearer, object armour, int flags) {
  if (!(flags & EWF_SILENT))
  {
    write("You release the shield, and it goes dark.\n");
    say("Something weird failed to happen.\n");
  }
}

/*-------------------------------------------------------------------------
** The 'DefendHit()' function allows special calculation of the defense.
** It has to return the 'less-damage' it gives.
**
** Here we just give a cute message.
*/

DefendHit (object enemy, int damage, int dtype) {
  return ({ ::CalcDefend (enemy, damage, dtype)
          , "A low hum is audible.\n" 
         });
}

/*************************************************************************/

