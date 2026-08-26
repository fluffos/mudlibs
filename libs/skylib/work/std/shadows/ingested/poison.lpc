/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: poison.c,v 1.1 1998/01/06 04:36:51 ceres Exp $
 * $Log: poison.c,v $
 * Revision 1.1  1998/01/06 04:36:51  ceres
 * Initial revision
 * 
*/
inherit "/std/effect_shadow";

int active;

int query_active( string words ) {

   if ( words != "poison" )
      return (int)player->query_active( words );
   return active;
} /* query_active() */

void set_active( string words ) {

   if ( words != "poison" ) player->set_active( words );
   if ( !active ) {
      active = 1;
      player->adjust_bonus_con( -5 );
      player->adjust_bonus_dex( -2 );
   }
} /* set_active() */

void set_inactive( string words ) {

   if ( words != "poison" ) player->set_inactive( words );
   if ( active ) {
      active = 0;
      player->adjust_bonus_con( 5 );
      player->adjust_bonus_dex( 2 );
   }
} /* set_inactive() */
