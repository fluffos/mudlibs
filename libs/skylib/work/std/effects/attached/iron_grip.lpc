/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: iron_grip.c,v 1.3 2000/05/09 08:02:29 pinkfish Exp $
 * $Log: iron_grip.c,v $
 * Revision 1.3  2000/05/09 08:02:29  pinkfish
 * Fix up some stuff.
 *
 * Revision 1.2  2000/05/08 03:51:07  pinkfish
 * Fix up a bunch of problems with starting/resrtarting of effects.
 *
 * Revision 1.1  1998/01/06 04:06:32  ceres
 * Initial revision
 * 
*/
/**
 * This is the effect skelton docs.  This effect
 * has a classification of "magic.hands.strength".
 * <p>
 * Describe the arguments in here.
 * @classification magic.hands.strength
 * @see help::effects
 */
#include "path.h"
#include <effect.h>
#include <effects/stat_adjustment.h>

#define GRIP 2
#define COST_PER_ROUND 30

/** @ignore yes */
string query_classification() { return "magic.hands.strength"; }

/** @ignore yes */
object beginning( object player, object arg ) {
   tell_object( player, "Your hands clench suddenly.\n" );
   player->submit_ee( "decrease_points", 1, EE_ONCE );
   player->submit_ee( "decrease_points", ({ 30, 60 }), EE_CONTINUOUS );
   player->add_effect(STAT_ADJUSTMENT_EFFECT, ({ arg, ([ "str" : GRIP ]) }));
   return arg;
} /* beginning() */

void restart( object player ) {
   //player->adjust_bonus_str( GRIP );
} /* restart() */

/** @ignore yes */
void merge_effect( object player, mixed arg, mixed arg2) {
   if (!arg && arg2) {
      player->submit_ee( "decrease_points", 1, EE_ONCE );
      player->submit_ee( "decrease_points", ({ 30, 60 }), EE_CONTINUOUS );
      player->add_effect(STAT_ADJUSTMENT_EFFECT, ({ arg, ([ "str" : GRIP ]) }));
   }
   return arg2;
} /* merge_effect() */

/** @ignore yes */
void end( object player, object arg ) {
   //player->adjust_bonus_str( -GRIP );
   STAT_ADJUSTMENT_EFFECT->remove_stat_adjustment_ob(player, arg);
   tell_object( player, "Your hands twitch and feel weak.\n" );
} /* end() */

int test_for_effect( object thing ) {
   if ( !thing ) {
      return 0;
   }
   return member_array( file_name( this_object() ),
         (string *)thing->query_wear_effects() ) != -1;
} /* test_for_effect() */

void decrease_points( object player ) {
   if ( player->query_auto_loading() ) {
      return;
   }
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

/**
 * This is called when the gloves are removed..
 */
void person_removing_item(object item, object player) {
   int* ids;

   if (!player) {
      return ;
   }
   ids = player->effects_matching(query_classification());
   if (sizeof(ids)) {
      player->delete_effect(ids[0]);
   }
} /* person_removing__item() */
