/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: basic_charging.c,v 1.1 1998/01/06 04:14:00 ceres Exp $
 * $Log: basic_charging.c,v $
 * Revision 1.1  1998/01/06 04:14:00  ceres
 * Initial revision
 * 
*/
/**
 * This is the effect skelton docs.  This effect
 * has a classification of "charging.basic".
 * <p>
 * Describe the arguments in here.
 * @classification charging.basic
 * @see help::effects
 */
#include <effect.h>

/** @ignore yes */
void beginning( object player, int amount ) {
   player->submit_ee( 0, 1, EE_REMOVE );
} /* beginning() */

/** @ignore yes */
int merge_effect( object player, int amount1, int amount2 ) {
   return amount1 + amount2;
} /* merge_effect() */

/** @ignore yes */
void end( object player, int amount ) {
   int charge, old_gp;
   string desc;
   charge = amount + random( amount );
   if ( charge > 132 )
      charge = 132;
   old_gp = (int)player->query_gp();
   charge = (int)player->adjust_gp( charge ) - old_gp;
   if ( charge < 1 )
      return;
   switch ( charge ) {
      case 1 .. 2 :
         desc = "a touch more able";
         break;
      case 3 .. 6 :
         desc = "very slightly less tired";
         break;
      case 7 .. 12 :
         desc = "slightly less tired";
         break;
      case 13 .. 20 :
         desc = "ever so slightly more energetic";
         break;
      case 21 .. 30 :
         desc = "slightly more energetic";
         break;
      case 31 .. 42 :
         desc = "a bit more energetic";
          break;
      case 43 .. 56 :
         desc = "quite a bit more energetic";
         break;
      case 57 .. 72 :
         desc = "a lot more energetic";
         break;
      case 73 .. 90 :
         desc = "a whole lot more energetic";
         break;
      case 91 .. 110 :
         desc = "much more energetic";
         break;
      default :
         desc = "very much more energetic";
   }
   tell_object( player, "You feel "+ desc +".\n" );
} /* end() */

/** @ignore yes */
string query_classification() { return "charging.basic"; }

string query_apothecarial_effect() {
   return "will remove fatigue";
} /* query_apothecarial_effect() */
