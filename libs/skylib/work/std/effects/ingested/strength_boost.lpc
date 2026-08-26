/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: strength_boost.c,v 1.1 1998/01/06 04:14:00 ceres Exp $
 * $Log: strength_boost.c,v $
 * Revision 1.1  1998/01/06 04:14:00  ceres
 * Initial revision
 * 
*/
/**
 * This is the effect skelton docs.  This effect
 * has a classification of "body.stats.boost.strength".
 * <p>
 * Describe the arguments in here.
 * @classification body.stats.boost.strength
 * @see help::effects
 */
/*
 * Strength boosting effect:
 *
 *   An amount of 1600 will increase the average human's temporary
 * strength by one point and lower the temporary dexterity by the log
 * base 2 of the strength increase. After a certain time, also proportional
 * to the log of the strength increase, the player will be given a dose of
 * the constitution poison at twice the amount.
 *
 */

#include <effect.h>

#define PLAYER capitalize( (string)player->the_short() )

int do_boosting( object player, int amount ) {
   int boost, time, twos;
   boost = amount / 2 + random( amount );
   boost /= (int)player->query_weight();
   player->adjust_tmp_str( boost );
   tell_object( player, "You feel "+ ( boost > 2 ? "much " : "" ) +
         "stronger!\n" );
   while ( boost >= twos ) {
      time += 1;
      if ( !twos )
        twos = 1;
      else
        twos *= 2;
   }
   player->adjust_tmp_dex( -time );
   return 900 * time;
} /* do_boosting() */

/** @ignore yes */
void beginning( object player, int amount ) {
   player->submit_ee( 0, do_boosting( player, amount ), EE_REMOVE );
} /* beginning() */

/** @ignore yes */
int merge_effect( object player, int amount1, int amount2 ) {
   player->submit_ee( 0, do_boosting( player, amount2 ) +
         (int)player->expected_tt(), EE_REMOVE ); 
   return amount1 + amount2;
} /* merge_effect() */
 
/** @ignore yes */
void end( object player, int amount ) {
   if ( player->query_property( "dead" ) )
      return;
   tell_object( player, "You feel slightly queasy.\n" );
   call_out( "poison_backlash", 1, player, amount );
} /* end() */

void poison_backlash( object player, int amount ) {
   if ( player )
      if ( !player->query_property( "dead" ) )
         player->add_effect( "/std/effects/poisons/constitution", 2 * amount );
} /* poison_backlash() */

/** @ignore yes */
string query_classification() { return "body.stats.boost.strength"; }
