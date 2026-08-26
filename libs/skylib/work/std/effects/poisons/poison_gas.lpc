/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: poison_effect.c,v 1.1 1998/01/06 04:21:18 ceres Exp $
 * $Log: poison_effect.c,v $
 * Revision 1.1  1998/01/06 04:21:18  ceres
 * Initial revision
 * 
*/
/**
 * This is the effect skelton docs.  This effect
 * has a classification of "poison.hp".
 * <p>
 * Describe the arguments in here.
 * <p>
 * This effect has a shadow associated with it.
 * @classification poison.hp
 * @see help::effects
 */
#include <effect.h>
#include "path.h"

inherit "/std/effects/basic";

void create() {
   seteuid( (string)"/secure/master"->
         creator_file( file_name( this_object() ) ) );
} /* create() */

int beginning(object player, int amount, int id) {
  debug_printf("Adding %O", amount);
  tell_object(player, "As you inhale the gas you feel rather sick.\n");
  player->adjust_hp(-amount);
  player->submit_ee("do_poison", ({ 10, 20 }), EE_CONTINUOUS);
  return amount;
}

int merge_effect(object player, int amount1, int amount2) {
  debug_printf("%O: %O", amount1, amount2);
  player->adjust_hp(-amount2);
  tell_object(player, "As you inhale the gas you feel rather sick.\n");
  return amount1 + amount2;
}

/** @ignore yes */
void end(object player){
  tell_object(player, "You feel a lot better now.\n");
}

/** @ignore yes */
string query_classification() { return "poison.gas.hp"; }
string query_name() { return "poison gas"; }

void do_poison(object player, int amount, int id){
  debug_printf("do poison called %O", amount);
  
  if(player->query_hp() < amount) {
    tell_object( player, "You reel, and collapse with all your "+
                 "health fleeing your body.\n" );
    tell_room( environment( player ), player->one_short() +
               " collapses with a "+
               "face palid as the face Death would have if Death had "+
               "a face.\n", player );
    player->attack_by(this_object());
    player->do_death();
    player->submit_ee(0, 2, EE_REMOVE);
    return;
  }

  tell_object(player, "Your head spins and you feel very sick.\n");
  player->adjust_hp(-(amount));

  // Damage per round goes down based on their health.
  if(amount < player->query_skill_bonus("other.health")) {
    tell_object(player, "You feel better now.\n");
    player->submit_ee(0, 2, EE_REMOVE);
    return;
  }

  player->set_arg_of( (int)player->sid_to_enum( id ),
          amount - player->query_skill_bonus("other.health"));
}
