/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: sneak.c,v 1.1 1998/01/06 04:20:30 ceres Exp $
 * $Log: sneak.c,v $
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

#define COST_PER_ROUND 3


/** @ignore yes */
void beginning( object player, int lev ) {
//tell_object( player, "You will now attempt to move stealthily.\n" );
  player->start_sneaking(lev);
  player->submit_ee( "decrease_points", ({ 10, 10 }), EE_CONTINUOUS );
} /* beginning() */

void restart( object player ) {
  player->submit_ee( 0, 0, EE_REMOVE );
} /* restart() */

/** @ignore yes */
void merge_effect( object player, int old, int lev ) {
  player->start_sneaking(lev);
  return;
}

/** @ignore yes */
void end( object player ) {
  player->remove_hide_invis("sneaking");
  if(query_verb() != "hide")
    player->remove_hide_invis("hiding");
} /* end() */

void decrease_points( object player ) {
  int level;
  
   if ( player->query_auto_loading() )
      return;

  level = player->query_sneak_level();
  if ( (int)player->query_specific_gp("covert") < (COST_PER_ROUND * level)) {
    tell_object(player, "You can't concentrate sufficiently to sneak "
                "anymore.\n");
    player->submit_ee( 0, 0, EE_REMOVE );
    return;
  }

  // yes, set_gp() is used deliberately to prevent huge gp tms
  // since this is continuous.
  player->set_gp(player->query_gp() - (COST_PER_ROUND * level));
}

/** @ignore yes */
string query_classification() { return "covert.sneaking"; }

/** @ignore yes */
string query_shadow_ob() { return SHADOWS +"sneak"; }
