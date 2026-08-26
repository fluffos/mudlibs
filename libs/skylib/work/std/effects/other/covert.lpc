/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: covert.c,v 1.1 1998/01/06 04:20:30 ceres Exp $
 * $Log: covert.c,v $
 * Revision 1.1  1998/01/06 04:20:30  ceres
 * Initial revision
 * 
*/
/**
 * This is the effect skelton docs.  This effect
 * has a classification of "covert.sneaking".
 * <p>
 * Describe the arguments in here.
 * <p>
 * This effect has a shadow associated with it.
 * @classification covert.sneaking
 * @see help::effects
 */
#include "path.h"
#include <effect.h>

#define COST_PER_ROUND 5

int level;

/** @ignore yes */
string query_classification() { return "covert.sneaking"; }

/** @ignore yes */
void beginning( object player, int level ) {
  tell_object( player, "Your will now attempt to move stealthily.\n" );
  player->start_sneaking(level);
  player->submit_ee( "decrease_points", ({ 10, 10 }), EE_CONTINUOUS );
} /* beginning() */

void restart( object player ) {
  player->submit_ee( 0, 0, EE_REMOVE );
} /* restart() */

/** @ignore yes */
void merge_effect( object player ) { return; }

/** @ignore yes */
void end( object player ) {
  player->remove_hide_invis("sneaking");
  player->remove_hide_invis("hiding");
  tell_object( player, "You stop sneaking.\n" );
} /* end() */

void decrease_points( object player ) {
   if ( player->query_auto_loading() )
      return;
   if ( (int)player->query_specific_gp() <= (COST_PER_ROUND * level) ) {
     player->submit_ee( 0, 0, EE_REMOVE );
     return;
   }
   player->adjust_gp( -(COST_PER_ROUND * level) );
}

/** @ignore yes */
string query_shadow_ob() { return SHADOWS +"covert"; }
