/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: broken_leg.c,v 1.1 1998/01/06 04:42:56 ceres Exp $
 * $Log: broken_leg.c,v $
 * Revision 1.1  1998/01/06 04:42:56  ceres
 * Initial revision
 * 
*/
#include <player.h>
#include <move_failures.h>

#define TOO_WEAK 4

inherit "/std/effect_shadow";

int cannot_walk() {
   if ( ( (int)player->query_con() < TOO_WEAK ) ||
         ( (int)player->query_str() < TOO_WEAK ) ) {
      tell_object( player, "You're too weak to move at the moment.\n" );
      return 1;
   }
   return 0;
} /* cannot_walk() */

void room_look() {
   string *args;
   player->room_look();

   player->adjust_time_left(-ROUND_TIME);

   args = arg();
   if ( !sizeof( args ) )
      return;

   tell_object( player, "That took a lot out of you.  You're really in "+
         "no state to be moving about with your "+
         query_multiple_short( args ) +" leg"+
         ( sizeof( args ) == 1 ? "" : "s" ) +" broken.\n" );
   player->adjust_tmp_con( -random( 1 + sizeof( args ) ) );
   player->adjust_tmp_str( -random( 1 + 5 * sizeof( args ) ) / 5 );

   player->adjust_time_left(-ROUND_TIME);

 } /* room_look() */
