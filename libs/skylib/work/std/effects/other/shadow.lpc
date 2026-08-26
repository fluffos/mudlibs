/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: shadow.c,v 1.1 1998/01/06 04:20:30 ceres Exp $
 * $Log: shadow.c,v $
 * Revision 1.1  1998/01/06 04:20:30  ceres
 * Initial revision
 * 
*/
/**
 * This is the effect skelton docs.  This effect
 * has a classification of "covert.shadowing".
 * <p>
 * Describe the arguments in here.
 * <p>
 * This effect has a shadow associated with it.
 * @classification covert.shadowing
 * @see help::effects
 */
#include "path.h"
#include <effect.h>

#define COST_PER_ROUND 5

/** @ignore yes */
void beginning( object player, mixed *args ) {
  
  tell_object( player, "You will now attempt to shadow "+
              args[0]->the_short()+".\n" );
  player->start_shadowing(args[0], args[1]);
  player->submit_ee( "decrease_points", ({ 10, 10 }), EE_CONTINUOUS );
} /* beginning() */

void restart( object player ) {
  player->submit_ee( 0, 0, EE_REMOVE );
} /* restart() */

/** @ignore yes */
void merge_effect( object player, mixed *old, mixed *args ) {
  player->start_shadowing(args[0], args[1]);
  return;
}

/** @ignore yes */
void end( object player ) {
  object shadowee;
  
  shadowee = player->query_shadow_victim();
  
  player->remove_hide_invis("sneaking");
  player->remove_hide_invis("hiding");

  if(objectp(shadowee))
    tell_object( player, "You stop shadowing "+shadowee->the_short()+".\n" );
} /* end() */

void decrease_points( object player ) {
  int level;

  if ( player->query_auto_loading() )
    return;

  level = player->query_shadow_level();

  if ( (int)player->query_specific_gp("covert") < (COST_PER_ROUND * level)) {
    tell_object(player, "You can't concentrate sufficiently to shadow "
                "anymore.\n");
    player->submit_ee( 0, 0, EE_REMOVE );
    return;
  }

  // yes, set_gp() is used deliberately to prevent huge gp tms
  // since this is continuous.
  player->set_gp(player->query_gp() - (COST_PER_ROUND * level));
}

/** @ignore yes */
string query_classification() { return "covert.shadowing"; }

/** @ignore yes */
string query_shadow_ob() { return SHADOWS +"shadow"; }
