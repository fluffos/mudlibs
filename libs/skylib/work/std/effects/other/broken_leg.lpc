/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: broken_leg.c,v 1.1 1998/01/06 04:20:30 ceres Exp $
 * $Log: broken_leg.c,v $
 * Revision 1.1  1998/01/06 04:20:30  ceres
 * Initial revision
 * 
*/
/**
 * This is the effect skelton docs.  This effect
 * has a classification of "body.damage.leg.broken".
 * <p>
 * Describe the arguments in here.
 * <p>
 * This effect has a shadow associated with it.
 * @classification body.damage.leg.broken
 * @see help::effects
 */
#include "path.h"
#include <effect.h>

/** @ignore yes */
string query_classification() { return "body.damage.leg.broken"; }

/** @ignore yes */
void beginning( object player, string *which ) {
   int handicap;
   player->add_extra_look( this_object() );
   handicap = (int)player->query_real_dex();
   handicap = ( sizeof( which ) * handicap ) / ( 1 + sizeof( which ) );
   player->adjust_bonus_dex( -handicap );
} /* beginning() */

void restart( object player, string *which ) {
   int handicap;
   player->add_extra_look( this_object() );
   handicap = (int)player->query_real_dex();
   handicap = ( sizeof( which ) * handicap ) / ( 1 + sizeof( which ) );
   player->adjust_bonus_dex( -handicap );
} /* restart() */

/** @ignore yes */
string *merge_effect( object player, string *which1, string *which2 ) {
   int i, handicap;
   string *which;
   handicap = (int)player->query_real_dex();
   handicap = ( sizeof( which1 ) * handicap ) / ( 1 + sizeof( which1 ) );
   player->adjust_bonus_dex( handicap );
   which = which1;
   for ( i = 0; i < sizeof( which2 ); i++ )
      if ( member_array( which2[ i ], which ) == -1 )
         which += ({ which2[ i ] });
   handicap = (int)player->query_real_dex();
   handicap = ( sizeof( which ) * handicap ) / ( 1 + sizeof( which ) );
   player->adjust_bonus_dex( -handicap );
   return which;
} /* merge_effect() */

/** @ignore yes */
void end( object player, string *which ) {
   int handicap;
   player->remove_extra_look( this_object() );
   handicap = (int)player->query_real_dex();
   handicap = ( sizeof( which ) * handicap ) / ( 1 + sizeof( which ) );
   player->adjust_bonus_dex( handicap );
} /* end() */

string extra_look( object player ) {
   int *enums;
   string *which;
   enums = (int *)player->effects_matching( "body.damage.leg.broken" );
   if ( !sizeof( enums ) )
      return "";
   which = (string *)player->arg_of( enums[ 0 ] );
   return capitalize( (string)player->query_pronoun() ) +" has broken "+
         (string)player->query_possessive() +" "+
         query_multiple_short( which ) +" leg"+
         ( sizeof( which ) == 1 ? "" : "s" ) +".\n";
} /* extra_look() */

int query_indefinite() { return 1; }

/** @ignore yes */
string query_shadow_ob() { return SHADOWS +"broken_leg"; }
