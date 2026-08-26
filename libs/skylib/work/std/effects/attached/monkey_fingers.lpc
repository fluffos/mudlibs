/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: monkey_fingers.c,v 1.5 2000/05/09 11:28:20 terano Exp $
 * $Log: monkey_fingers.c,v $
 * Revision 1.5  2000/05/09 11:28:20  terano
 * Fixed a parse error.
 * W
 *
 * Revision 1.4  2000/05/09 08:02:29  pinkfish
 * Fix up some stuff.
 *
 * Revision 1.3  2000/05/08 01:41:05  pinkfish
 * Fix up some problems with yhow it does things.
 *
 * Revision 1.2  2000/05/08 01:19:59  pinkfish
 * Fix it up!
 *
 * Revision 1.1  1998/01/06 04:06:32  ceres
 * Initial revision
 * 
*/
/**
 * This is the effect skelton docs.  This effect
 * has a classification of "magic.hands.dexterity".
 * <p>
 * Describe the arguments in here.
 * @classification magic.hands.dexterity
 * @see help::effects
 */
#include "path.h"
#include <effect.h>
#include <effects/stat_adjustment.h>

#define MONKEY 2
#define FINGERS 1
#define COST_PER_ROUND 30

/** @ignore yes */
string query_classification() { return "magic.hands.dexterity"; }

/** @ignore yes */
object beginning( object player, object arg ) {
   if (!arg) {
      arg = previous_object(2);
   }
   tell_object( player, "Your fingers twitch a little.\n" );
/*
   player->adjust_bonus_dex( MONKEY );
   player->adjust_bonus_str( -FINGERS );
 */
   player->submit_ee( "decrease_points", 1, EE_ONCE );
   player->submit_ee( "decrease_points", ({ 30, 60 }), EE_CONTINUOUS );
   player->add_effect(STAT_ADJUSTMENT_EFFECT,
                      ({ arg, ([ "dex" : MONKEY,
                                  "str" : -FINGERS ]) }) ); /* :), 0, player, arg); */
   return arg;
} /* beginning() */

/** @ignore yes */
object restart( object player, object arg ) {
   player->add_effect(STAT_ADJUSTMENT_EFFECT, ({ arg, ([ "dex" : MONKEY,
                                 "str" : -FINGERS ]) }));
   return arg;
/*
   player->adjust_bonus_dex( MONKEY );
   player->adjust_bonus_str( -FINGERS );
 */
} /* restart() */

/** @ignore yes */
void end( object player, object arg ) {
   STAT_ADJUSTMENT_EFFECT->remove_stat_adjustment_ob(player, arg);
/*
   player->adjust_bonus_dex( -MONKEY );
   player->adjust_bonus_str( FINGERS );
 */
   tell_object( player, "Your fingers stiffen and feel clumsy.\n" );
} /* end() */

/** @ignore yes */
int test_for_effect( object thing ) {
   if ( !thing ) {
      return 0;
   }
   return member_array( file_name( this_object() ),
         (string *)thing->query_wear_effects() ) != -1;
} /* test_for_effect() */

/** @ignore yes */
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
