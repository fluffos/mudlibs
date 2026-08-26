/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: deadpet.c,v 1.2 1999/09/06 01:50:04 shaggy Exp $
 * $Log: deadpet.c,v $
 * Revision 1.2  1999/09/06 01:50:04  shaggy
 * type fixed
 *
 * Revision 1.1  1998/01/06 04:20:30  ceres
 * Initial revision
 * 
*/
/**
 * This is the effect skelton docs.  This effect
 * has a classification of "priest.dead.pet".
 * <p>
 * Describe the arguments in here.
 * <p>
 * This effect has a shadow associated with it.
 * @classification priest.dead.pet
 * @see help::effects
 */
#include <effect.h>
#include "path.h";

/* arg is {type, gender, name }
 */

/** @ignore yes */
string query_classification() {return "priest.dead.pet";}
/** @ignore yes */
string query_shadow_ob() {return "/std/shadows/other/deadpet";}
/** @ignore yes */
int survive_death() {return 1;}
/** @ignore yes */
void end(object player);
void rem_pet(object player);
void weakening(object player);

/** @ignore yes */
mixed beginning(object player, mixed *arg) {
    player->remember_pet( arg );
    player->submit_ee( "weakening", 19200, EE_ONCE );
    player->submit_ee( "rem_pet", 28800, EE_ONCE );
    tell_object( player, "You notice with frustration that $C$"+ arg[ 2 ]
      +" has died.  You must hurry to a priest, before "+
      ({"it","he","she"})[ arg[ 1 ] ]+
      " takes the long walk.\n");
    return player->query_info();
}

/** @ignore yes */
mixed merge_effect(object player, mixed *arg1, mixed *arg2, int id) {
    if(!arg2[0]) return player->query_info();
    player->set_add();
/** @ignore yes */
    return beginning(player, arg2);
}

void weakening( object player ) {
    if( player->num_dead_pets() ) {
        tell_object( player, "You start to feel less hurt by the loss of your pet.\n");
    }
} /* weakening_message */


void rem_pet( object player) {
    mixed *arg;
    arg =  player->really_remove_pet();
    tell_object( player,  "Your final thoughts of $C$"+ arg[ 2 ]
      +" are happy recollections of the fine times you "
      "had.\n");
    if(!player->num_dead_pets()) {
        player->delete_effect(player->effects_matching("priest.dead.pet")[0]);
    }
} /* rem_pet() */


/** @ignore yes */
void end(object player) {
}


