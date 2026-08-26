/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: fluster.c,v 1.1 1998/01/06 04:20:30 ceres Exp $
 * $Log: fluster.c,v $
 * Revision 1.1  1998/01/06 04:20:30  ceres
 * Initial revision
 * 
*/
/**
 * This is the effect skelton docs.  This effect
 * has a classification of "mind.fluster".
 * <p>
 * Describe the arguments in here.
 * <p>
 * This effect has a shadow associated with it.
 * @classification mind.fluster
 * @see help::effects
 */
#include "path.h"
#include <effect.h>

/** @ignore yes */
string query_classification() { return "mind.fluster"; }

/** @ignore yes */
string query_shadow_ob() { return SHADOWS +"fluster"; }

/** @ignore yes */
void beginning( object player, int duration, int id ) {
   tell_object( player, "You become flustered!\n" );
   player->submit_ee( 0, duration, EE_REMOVE );
} /* beginning() */

/** @ignore yes */
int merge_effect( object thing, int old_duration, int new_duration, int id ) {
   thing->submit_ee( 0, old_duration + new_duration
         - (int)thing->expected_tt(), EE_REMOVE );
   return old_duration + new_duration;
} /* merge_effect() */

/** @ignore yes */
void end( object player, int duration, int id ) {
   tell_object( player, "You no longer feel flustered.\n" );
} /* end() */
