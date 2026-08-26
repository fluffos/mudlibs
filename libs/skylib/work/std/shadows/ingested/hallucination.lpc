/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: hallucination.c,v 1.1 1998/01/06 04:36:51 ceres Exp $
 * $Log: hallucination.c,v $
 * Revision 1.1  1998/01/06 04:36:51  ceres
 * Initial revision
 * 
*/
#include "path.h"

#define THINGS (string)( EFFECTS +"hallucination" )->strange_things()

inherit "/std/effect_shadow";

int query_hallucinating() { return 1; }

int look_me( string words ) {
   if ( !words ) {
      if ( random( 10 ) > 3 )
         tell_object( player, "Your vision is obscurred by the "+
               THINGS +".\n");
      else {
         tell_object( player, "You can just see through the cloud of "+
               THINGS +".\n" );
         player->look_me();
      }
      return 1;
   }
   tell_object( player, "You can't get a clear view at "+ words +
         " while the "+ THINGS +" are in the way.\n" );
   return 1;
} /* look_me() */

int glance( string words ) {
   tell_object( player, "Your vision is obscurred by the "+
         THINGS +".\n");
   return 1;
} /* glance() */

void attack() {
   if ( random( 2 ) ) {
      tell_object( player, "You can't move your arms and legs while "+
            "all the "+ THINGS +" are sitting on them.\n" );
      return;
   }
   player->attack();
} /* attack() */

int cast( string words ) {
   if ( random( 2 ) ) {
      tell_object( player, "A horde of "+ THINGS +" goes marching "+
            "past which you find much more interesting.\n" );
      return 1;
   }
   return (int)player->cast( words );
} /* cast() */
