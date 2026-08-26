/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: see_invisible.c,v 1.1 1998/01/06 04:06:32 ceres Exp $
 * $Log: see_invisible.c,v $
 * Revision 1.1  1998/01/06 04:06:32  ceres
 * Initial revision
 * 
*/
/**
 * This is the effect skelton docs.  This effect
 * has a classification of "magic.sight.invisible".
 * <p>
 * Describe the arguments in here.
 * <p>
 * This effect has a shadow associated with it.
 * @classification magic.sight.invisible
 * @see help::effects
 */
#include "path.h"
#include <effect.h>

#define COST_PER_ROUND 30

/** @ignore yes */
string query_classification() { return "magic.sight.invisible"; }

/** @ignore yes */
string query_shadow_ob() { return SHADOWS +"see_invisible"; }

/** @ignore yes */
void beginning( object player ) {
   tell_object( player, "Your eyes tingle momentarily.\n" );
   player->submit_ee( "decrease_points", 1, EE_ONCE );
   player->submit_ee( "decrease_points", ({ 30, 60 }), EE_CONTINUOUS );
} /* beginning() */

/** @ignore yes */
void merge_effect( object player ) { return; }

/** @ignore yes */
void end( object player ) {
   tell_object( player, "Everything goes dark, as if you'd blinked, but "+
         "then returns to normal.\n" );
} /* end() */

int test_for_effect( object thing ) {
   if ( !thing )
      return 0;
   return member_array( file_name( this_object() ),
         (string *)thing->query_wear_effects() ) != -1;
} /* test_for_effect() */

void decrease_points( object player ) {
   if ( player->query_auto_loading() )
      return;
   if ( !sizeof( filter_array( (object *)player->query_armours(),
         "test_for_effect", this_object() ) ) ) {
      player->submit_ee( 0, 0, EE_REMOVE );
      return;
   }
   if ( (int)player->query_gp() <= COST_PER_ROUND ) {
      player->submit_ee( 0, 0, EE_REMOVE );
      return;
   }
   player->clear_gp_info();
   player->adjust_gp( -COST_PER_ROUND );
} /* decrease_points() */
