/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: elven_sight.c,v 1.4 2000/06/08 01:48:53 pinkfish Exp $
 * $Log: elven_sight.c,v $
 * Revision 1.4  2000/06/08 01:48:53  pinkfish
 * *** empty log message ***
 *
 * Revision 1.3  2000/05/08 00:46:46  pinkfish
 * Update to use the new stat adjustment effect.
 *
 * Revision 1.2  2000/03/28 21:19:09  ceres
 * cap/helm adjustments
 *
 * Revision 1.1  1998/01/06 04:35:11  ceres
 * Initial revision
 * 
 */
#include <effects/stat_adjustment.h>
inherit "/std/effect_shadow";

int active;

int query_active( string words ) {
   if ( words != "elven sight" ) {
      return (int)player->query_active( words );
   }
   return active;
} /* query_active() */

void set_active( string words ) {
   if ( words != "elven sight" ) {
      return (void)player->set_active( words );
   }
   active = 1;
} /* set_active() */

void set_inactive( string words ) {
   if ( words != "elven sight" ) {
      player->set_inactive( words );
   } else {
      active = 0;
   }
} /* set_inactive() */

int check_dark( int number ) {
   if ( !active ) {
      return (int)player->check_dark( number );
   }
   if ( number < 5 ) {
      return -2;
   }
   if ( number > 125 ) {
      return 2;
   }
   if ( number > 200 ) {
      return 1;
   }
   return 0;
} /* check_dark() */
