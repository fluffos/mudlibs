/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: holyweapon.c,v 1.4 1998/04/14 04:36:35 gerbil Exp $
 * $Log: holyweapon.c,v $
 * Revision 1.4  1998/04/14 04:36:35  gerbil
 * Since I fixed the typo, more people started using it, and more bugs cropped
 * up.  Fixed merge_effect and a coupla more typoes
 *
 * Revision 1.3  1998/03/30 03:48:38  gerbil
 * Corrected typo in add_attacks stopping them being added
 *
 * Revision 1.2  1998/01/11 17:03:41  pinkfish
 * fixed_up_the_extra_look_stuff,_tomake_them_ignored.
 *
 * Revision 1.1  1998/01/06 04:19:27  ceres
 * Initial revision
 * 
*/
/**
 * This effect makes the object a holy weapon.  This effect
 * has a classification of "object.holyweapon".
 * <p>
 * The argument specifies the time in seconds for the effect to
 * last.
 * <p>
 * This effect has a shadow associated with it.
 * @classification object.holyweapon
 * @see help::effects
 * @example
 * // last for 2 minutes
 * ob->add_effect("/std/effects/object/holyweapon", 120);
 */
#include <effect.h>

/* arg is duration */

/** @ignore yes */
string query_classification() { return "object.holyweapon"; }
/** @ignore yes */
string query_shadow_ob() { return "/std/shadows/object/holyweapon"; }

/** @ignore yes */
int beginning( object thing, int arg, int id ) {
    thing->submit_ee( 0, arg, EE_REMOVE );
    thing->add_extra_look( this_object() );
    thing->add_attack( "fire-holyweapon", 71, ({ 40, 5, 40 }), "fire",
      "sharp", 0 );
    thing->add_attack_mess( "fire-holyweapon",
      ({20, ({ "You touch $hcname$ with the Holy Radiance of your $wcname$.\n",
          "$mcname$ touches you with the Holy Radiance of $mposs$ $wcname$.\n",
          "$mcname$ touches $hcname$ with the Holy Radiance of $mposs$ $wcname$.\n",
        }),
        40, ({ "You scorch $hcname$ with the Holy Radiance of your $wcname$.\n",
          "$mcname$ scorches you with the Holy Radiance of $mposs$ $wcname$.\n",
          "$mcname$ scorches $hcname$ with the Holy Radiance of $mposs$ $wcname$.\n",
        }),
        80, ({ "You crisp $hcname$ with the Holy Radiance of your $wcname$.\n",
          "$mcname$ crisps you with the Holy Radiance of $mposs$ $wcname$.\n",
          "$mcname$ crisps $hcname$ with the Holy Radiance of $mposs$ $wcname$.\n",
        }),
        120, ({ "You fry $hcname$ with the Holy Radiance of your $wcname$.\n",
          "$mcname$ fries you with the Holy Radiance of $mposs$ $wcname$.\n",
          "$mcname$ fries $hcname$ with the Holy Radiance of $mposs$ $wcname$.\n",
        }),
        160, ({ "You roast $hcname$ with the Holy Radiance of your $wcname$.\n",
          "$mcname$ roasts you with the Holy Radiance of $mposs$ $wcname$.\n",
          "$mcname$ roasts $hcname$ with the Holy Radiance of $mposs$ $wcname$.\n",
        }),
        200, ({ "You burn $hcname$ with the Holy Radiance of your $wcname$.\n",
          "$mcname$ burns you with the Holy Radiance of $mposs$ $wcname$.\n",
          "$mcname$ burns $hcname$ with the Holy Radiance of $mposs$ $wcname$.\n",
        }),
        240, ({ "You incinerate $hcname$ with the Holy Radiance of your $wcname$.\n",
          "$mcname$ incinerates you with the Holy Radiance of $mposs$ $wcname$.\n",
          "$mcname$ incinerates $hcname$ with the Holy Radiance of $mposs$ $wcname$.\n",
        }),
        280, ({"You cremate $hcname$ with the Holy Radiance of your $wcname$.\n",
          "$mcname$ cremates you with the Holy Radiance of $mposs$ $wcname$.\n",
          "$mcname$ cremates $hcname$ with the Holy Radiance of $mposs$ $wcname$.\n",
        }),
        0, ({"You vapourise $hcname$ with the Holy Radiance of your $wcname$.\n",
          "$mcname$ vapourises you with the Holy Radiance of $mposs$ $wcname$.\n",
          "$mcname$ vapourises $hcname$ with the Holy Radiance of $mposs$ $wcname$.\n",
        })
      }) );
    tell_object( environment( thing ), thing->the_short()+
      " glows with a holy radiance.\n");
    return arg;
} /* beginning() */

/* simply use new args */
/** @ignore yes */
int merge_effect( object player, int old_arg, int new_arg, int id ) {
    int newtime;
    newtime = (int)player->expected_tt() + new_arg;
    player->submit_ee( 0, newtime, EE_REMOVE );
    tell_object( environment( player ), "The duration has been extended.\n");
    return newtime;
} /* merge_effect() */

/** @ignore yes */
void end( object thing, mixed args, int id ) {
    thing->remove_extra_look( this_object() );
thing->remove_attack( "fire-holyweapon" );
    tell_object( environment( thing ), thing->poss_short()+
      " stops glowing.\n" );
} /* end() */

void restart( object thing, mixed args, int id ) {
    thing->add_extra_look( this_object() );
    thing->add_attack( "holyweapon", 71, ({ 40, 5, 40 }), "fire", "sharp", 0 );
} /* restart() */

/** @ignore yes */
string extra_look( object thing ) {
    return "It is glowing with holy radiance.\n";
} /* extra_look() */

