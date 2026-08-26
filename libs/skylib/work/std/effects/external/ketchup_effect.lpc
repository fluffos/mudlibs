/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: ketchup_effect.c,v 1.1 1998/01/06 04:10:22 ceres Exp $
 * $Log: ketchup_effect.c,v $
 * Revision 1.1  1998/01/06 04:10:22  ceres
 * Initial revision
 * 
*/
/**
 * This is the effect skelton docs.  This effect
 * has a classification of "misc.ketchup".
 * <p>
 * Describe the arguments in here.
 * @classification misc.ketchup
 * @see help::effects
 */
#include <effect.h>

/** @ignore yes */
string query_classification() { return "misc.ketchup"; }

/** @ignore yes */
int amount;
void beginning( object player, int time ) {
   player->add_extra_look( this_object() );
   amount=699;
   player->submit_ee( "decrease_amount", 15, EE_CONTINUOUS );
} /* beginning() */

void restart( object player, int time ) {
   player->add_extra_look( this_object() );
} /* restart() */

/** @ignore yes */
int merge_effect( object player, int time ) {
   amount=699;
   return 1;
} /* merge_effect() */

/** @ignore yes */
void end( object player, int time ) {
   player->remove_extra_look( this_object() );
} /* end() */

void decrease_amount( object player, int time ) {
   amount -= 3 + random(random(random(amount)));
   if ( amount < 0 ) {
      amount = 0;
      player->submit_ee( 0, 1, EE_REMOVE );
   }
} /* decrease_amount() */

string extra_look( object player ) {
   string desc;
   switch ( amount ) {
      case 0 .. 99 :
         desc = " has a wee bit of ketchup";
         break;
      case 100 .. 199 :
         desc = " has a bit of ketchup";
         break;
      case 200 .. 299 :
         desc = " has a good bit of ketchup";
         break;
      case 300 .. 399 :
         desc = " has a quite a bit of slimy ketchup";
         break;
      case 400 .. 499 :
         desc = " has lots of ketchup";
         break;
      case 500 .. 599 :
         desc = " has quite a large mess of ketchup";
         break;
      case 600 .. 699 :
         desc = " has a ruddy, ketchupy mess";
         break;
      default :
         desc = " has a ruddy, ketchupy mess";
         break;
   }
   if (living(player))
     return capitalize( (string)player->query_pronoun() ) + desc +" on "+
         (string)player->query_possessive() +" head and shoulders.\n";
   return "It is smothered in ketchup.\n";

} /* extra_look() */
