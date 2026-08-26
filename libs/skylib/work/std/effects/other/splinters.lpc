/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: splinters.c,v 1.1 1998/01/06 04:20:30 ceres Exp $
 * $Log: splinters.c,v $
 * Revision 1.1  1998/01/06 04:20:30  ceres
 * Initial revision
 * 
*/
/**
 * This is the effect skelton docs.  This effect
 * has a classification of "body.damage.skin.splinters".
 * <p>
 * Describe the arguments in here.
 * <p>
 * This effect has a shadow associated with it.
 * @classification body.damage.skin.splinters
 * @see help::effects
 */
/*
 * argument when starting effect should be of the format:
 *
 *    ({ "hand", 0, 1 })
 *         |     |  | 
 *         |     |  how nasty it is
 *         |     how deep it is (shallow, deep, very deep)
 *         where it is
 */

#include "path.h"
#include <effect.h>

/** @ignore yes */
string query_classification() { return "body.damage.skin.splinters"; }

int make_handicap( object player, mixed *args ) {
   int i, total;
   for ( i = 1; i < sizeof( args ); i++ )
      total += ( args[ i ][ 1 ] + 1 ) * args[ i ][ 2 ];
   total /= 4;
   if ( total > 3 )
      total = 3;
   player->adjust_bonus_dex( -total );
   return total;
} /* make_handicap() */

/** @ignore yes */
mixed *beginning( object player, mixed *which ) {
   player->submit_ee( "fester", ({ 60, 60 }), EE_CONTINUOUS );
   return ({ make_handicap( player, ({ 0, which }) ), which });
} /* beginning() */

void restart( object player, mixed *args ) {
   player->adjust_bonus_dex( -args[ 0 ] );
} /* restart() */

/** @ignore yes */
mixed *merge_effect( object player, mixed *args, string *which ) {
   player->adjust_bonus_dex( args[ 0 ] );
   return ({ make_handicap( player, args + ({ which }) ) }) +
         delete( args, 0, 1 ) + ({ which });
} /* merge_effect() */

/** @ignore yes */
void end( object player, mixed *args ) {
   player->adjust_bonus_dex( args[ 0 ] );
} /* end() */

/* That's the complete end function. Something needs to be put in for
   if just one splinter is removed, though. */

void fester( object player, string *which ) {
   tell_object( player, "Your splinter"+ ( sizeof( which ) > 2 ? "s hurt" :
         " hurts" ) +".\n" );
} /* fester() */

string splinters_long( object player ) {
   int i, *enums;
   string *places;
   mapping counts;
   mixed *args;
   enums = (int *)player->effects_matching( "body.damage.skin.splinters" );
   if ( !sizeof( enums ) )
      return "";
   args = (mixed *)player->arg_of( enums[ 0 ] );
   counts = ([ ]);
   for ( i = 1; i < sizeof( args ); i++ )
      if ( !counts[ args[ i ][ 0 ] ] )
         counts += ([ args[ i ][ 0 ] : 1 ]);
      else
         counts[ args[ i ][ 0 ] ]++;
   places = m_indices( counts );
   for ( i = 0; i < sizeof( places ); i++ )
      places[ i ] = query_num( counts[ places[ i ] ] ) +" splinter"+
            ( counts[ places[ i ] ] > 1 ? "s" : "" ) +" in your "+
            places[ i ];
   return "You have "+ query_multiple_short( places ) +".\n";
} /* splinters_long() */

/** @ignore yes */
string query_shadow_ob() { return SHADOWS +"splinters"; }
