/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: coerce.c,v 1.1 1998/01/06 04:14:00 ceres Exp $
 * $Log: coerce.c,v $
 * Revision 1.1  1998/01/06 04:14:00  ceres
 * Initial revision
 * 
*/
/**
 * This is the effect skelton docs.  This effect
 * has a classification of "potion.coerce".
 * <p>
 * Describe the arguments in here.
 * <p>
 * This effect has a shadow associated with it.
 * @classification potion.coerce
 * @see help::effects
 */
#include "path.h"
#include <effect.h>

/** @ignore yes */
string query_classification() { return "potion.coerce"; }

/** @ignore yes */
string query_shadow_ob() { return SHADOWS + "coerce"; }

/** @ignore yes */
mixed beginning(object player, int strength, int id) {
    player->submit_ee(0, strength, EE_REMOVE);
    //player->submit_ee("pre_end", strength);
    tell_object(player, "You suddenly feel very commanding.\n");
    return strength;
}

/** @ignore yes */
//void pre_end(object player, int strength, int id) {
//    player->remove_cmd();
//    player->submit_ee(0, 1, EE_REMOVE);
//}

/** @ignore yes */
void end(object player, int strength, int id) {
    player->remove_cmd();
    tell_object(player, "You return to normal.\n");
}
