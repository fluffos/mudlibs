/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: life_saving.c,v 1.1 1998/01/06 04:35:11 ceres Exp $
 * $Log: life_saving.c,v $
 * Revision 1.1  1998/01/06 04:35:11  ceres
 * Initial revision
 * 
*/
#include "path.h"

inherit "/std/effect_shadow";

void do_death( object killed_by ) {
   int i;
   object *things;
   i = -1;
   things = arg();
   while ( sizeof( things ) && ( i == -1 ) ) {
      i = random( sizeof( things ) );
      if ( !things[ i ] ) {
         things = delete( things, i, 1 );
         i = -1;
      } else
         if ( (object)things[ i ]->query_worn_by() != player ) {
            things = delete( things, i, 1 );
            i = -1;
         }
   }
   if ( i == -1 ) {
      player->do_death( killed_by );
      call_out( "remove_this_effect", 0 );
      return;
   }
   tell_object( player, "Out of the corner of your eye, you think you "+
         "see a tall, black-cloaked figure with a scythe, but it "+
         "wavers and is gone.\n" );
   player->set_hp( (int)player->query_max_hp(), player );
   things[ i ]->remove_life();
   set_arg( things );
} /* do_death() */

void taken_off( object thing, string wear_effect ) {
   int i;
   object *things;
   if ( wear_effect != EFFECTS +"life_saving" )
      player->taken_off( thing, wear_effect );
   things = arg();
   i = member_array( thing, things );
   if ( i != -1 ) {
      things = delete( things, i, 1 );
      if ( sizeof( things ) )
         set_arg( things );
      else
         call_out( "remove_this_effect", 0 );
   }
} /* taken_off() */
