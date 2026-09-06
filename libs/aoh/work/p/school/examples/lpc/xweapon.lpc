/* Wet Towel  (Mateese, 27-Aug-92)
**
** An example for /std/weapon.
** As you'll see, /std/weapon is just another child of /std/thing.
**
** Note: Originally this towel killed every nasty creature for sure.
**       But unfortunately some wiz gave this _example_ weapon away
**       to normal players, so I had to reduce its power.
**       Bletch!
*/

#include <properties.h>   /* for the property names */
#include <combat.h>       /* for the weapon types */
#include <equipment.h>    /* for the EWF flags */

inherit "/std/weapon";

/*-------------------------------------------------------------------------
** Initialize us.
*/

varargs void create () {

  ::create();

    /* We need a short description */
  Set(P_SHORT, "a wet towel");

    /* and also a long one */
  Set(P_LONG, 
"This is an example weapon (/d/archwiz/common/lpc/exm/xweapon.c).\n"
"Yow, this towel is really wet and heavy. No chance to dry anything "
"with it! But ... haven't you read something about wet towels in The Guide?\n"
         );

    /* Value and Weight (*yawn*) */
  Set(P_VALUE, 1000);
  Set(P_WEIGHT, 3000);

    /* Authorinfo */
  Set(P_INFO, "Example weapon, by Mateese");

    /* We are a club-type weapon - this also ADDs the ID 'club' */
  Set(P_WEAPON_TYPE, WT_CLUB);

    /* Our IDs: 'towel' and 'wet towel' */
  AddId("towel");
  AddAdjective("wet");

    /* and bludgeon our enemies */
  Set(P_DAM_TYPE, DT_BLUDGEON);

    /* Weapon Class 10 */
  Set(P_WC, 10);

    /* We need only one hand two use the towel */
  Set(P_NUMBER_HANDS, 1);

    /* Fighting with this weapon is non-standard.
    ** We could do
    **   SetHitObj (ob);
    ** then with every hit ob->WeaponHit(on_enemy)
    ** would be called. This object could even be me.
    ** We do it easier and just overload QueryDamage(enemy).
    */
}


/*-------------------------------------------------------------------------
** The 'NotifyWield()' function is called after the weapon is wielded.
** We use it to give out a message.
** If we wanted to do some additional checks before wielding, we would
** had to implement 'ChkWield()'.
*/

varargs void NotifyWield(object wielder, object weapon, int flags) 
{
  if (!(flags & EWF_SILENT))
    write("As your grip tightens, some water pours over your fingers.\n");
}


/*-------------------------------------------------------------------------
** This 'QueryDamage()' fun enables modification in the weapons characteristics
**  depending on the enemy being hit.
** The result of this fun is the damage this weapon does. On a plain weapon,
**  this is just a function of the weapons wc and the dexterity of the owner.
**  A damage of 0 would be a miss.
** To modify this, we just have to overload the standard QueryDamage() with
**  our own.
**
** This QueryDamage() implements the following features:
**  If the enemy is neither a player nor better than evil, it will be hit
**   very hard.
**  If the enemy is a player attacking us, the fight will be stopped.
**  Else, normal combat resumes.
*/

int QueryDamage(object enemy) {
  int align;

    /* What alignment is our enemy ? */
  align = enemy->Query(P_ALIGN);

    /* Handle creatures differently */
  if (!interactive(enemy) || !enemy->QueryIsPlayer()) {

      /* Eat flaming death, nasty creature ! */
    if (align <= -400) {
        /* Tell what has happened */
      write ("You hit the poor creature with a SPLASH!\n");
        /* And now hit the enemy hard */
      return 100;
    }

      /* else resume a normal combat */
    return (::QueryDamage(enemy));
  }

    /* Stop any player attacking us */
  write ("Your towel wettens "+enemy->QueryName()+" over and over.\n");
  say (this_player()->QueryName()+" wettens "+enemy->QueryName()+
       " with "+this_player()->QueryPossessive()+" towel over and over.\n"
       , enemy);
  tell_object(enemy, this_player()->QueryName()+" wettens you with "+
              this_player()->QueryPossessive()+" towel over and over.\n");

    /* If we call stop_attack() directly, the combat system will burp
    ** since upon return it assumes the combat round going on.
    */
  call_out("stop_attack", 1, enemy);

    /* But we let this swing miss */
  return 0;
}

void stop_attack(object enemy) {
  if (!enemy) {
    write ("No attacker here.\n");
    owner->StopHunting(enemy);
    return;
  }

  write (enemy->QueryName()+" gets blinded by the water.\n");
  say (enemy->QueryName()+" gets blinded by the water.\n", enemy);
  tell_object(enemy, "You get blinded by the water.\n");

  owner->StopHunting(enemy);
  enemy->StopHunting(owner);

  write ("You stop attacking the blinded "+enemy->QueryName()+".\n");
  say (owner->QueryName()+" stops attacking the blinded "+
       enemy->QueryName()+".\n", enemy);
  tell_object (enemy, owner->QueryName()+" stops attacking you.\n");
}

/*************************************************************************/
