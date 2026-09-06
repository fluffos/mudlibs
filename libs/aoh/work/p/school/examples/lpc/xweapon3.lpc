/* Staff of Fire  (Mateese, 15-Sep-93)
**
** An example for a /std/weapon with non-conventional attack.
*/

#include <config.h>       /* for the brightness value */
#include <properties.h>   /* for the property names */
#include <combat.h>       /* for the weapon types */
#include <equipment.h>    /* for the EWF-flags */

inherit "/std/weapon";

/*-------------------------------------------------------------------------
** Initialize us.
*/

create () {

  ::create();

    /* We need a short description */
  Set(P_SHORT, "a fiery staff");

    /* and also a long one */
  Set(P_LONG, 
"This is an example non-conventional weapon\n"+
"                                  (/d/archwiz/common/lpc/exm/xweapon3.c).\n"+
"A normal boring staff .. well, except for the handle it is built from "+
"flames - maybe it's not that boring at all.. \n"
         );

    /* Value and Weight (*yawn*) */
  Set(P_VALUE, 1000);
  Set(P_WEIGHT, 2000);

    /* Hey, it's emitting light (what surprise!) */
  Set(P_BRIGHT, MAX_SUNBRIGHT/2);

    /* Authorinfo */
  Set(P_INFO, "Example non-conventional weapon, by Mateese");

    /* We are a club-type weapon - this also ADDs the ID 'club' */
  Set(P_WEAPON_TYPE, WT_CLUB);

    /* Our IDs: 'staff' and 'fiery staff' */
  AddId("staff");
  AddAdjective("fiery");

    /* and burn our enemies. This is a non-conventional attack
    ** so DidDamage() will be called for every hit.
    */
  Set(P_DAM_TYPE, DT_FIRE);

    /* Weapon Class 10 - type fire is bad enough */
  Set(P_WC, 10);

    /* We need only one hand two use the staff */
  Set(P_NUMBER_HANDS, 1);
}


/*-------------------------------------------------------------------------
** Give some messages when wielding/unwielding the staff.
*/

void NotifyWield (object wielder, object weapon, int flags) 
{
  if (!(flags & EWF_SILENT))
    write("A warm feeling runs through your veins.\n"); /* :-) */
}

void NotifyUnwield (object wielder, object weapon, int flags) 
{
  if (!(flags & EWF_SILENT))
    write("You feel cold...\n");
}


/*-------------------------------------------------------------------------
** The combat with the staff is non-standard. Most of it is handled by
**  defining its type as DT_FIRE, but we still need approbiate hitmessages.
**
** That is the task of the DidDamage() function...
*/

DidDamage (object attacker, int damage, int dam_type) {
  object victim;
  string what, whats, how;

  victim = previous_object();
  
  /* For this weapon, dam_type is always DT_FIRE */
  
  switch (damage) {
    case      0: what= " miss "; whats= " misses "; how= "";
                 break;
    case      1: what= " warm "; whats= " warms "; how= " the skin";
                 break;
    case  2.. 5: what= " heat "; whats= " heats "; how= " uncomfortably";
                 break;
    case  6..10: what = " burn "; whats = " burns "; how = "";
                 break;
    case 11..20: what = " flame "; whats = " flames "; how = " hard";
                 break;
    case 21..30: what = " engulf "; whats = " engulfes "; 
                 how = " in flames";
                 break;
    default    : what= " burn "; whats=" burns ";
                 how=" the flesh off the bones";
  }

  if (damage) { 
    what = " and"+what; 
    whats = " and"+whats; 
  }
  else { 
    what = ", but"+what; 
    whats = ", but"+whats; 
  }
  tell_object(attacker, what+(victim->QueryName())+how+".\n");
  tell_object(victim, whats+"you"+how+".\n");
  say(whats+(victim->QueryName())+how+".\n", ({victim, attacker}));
}

/*************************************************************************/
