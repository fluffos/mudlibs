/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: basic_healing.c,v 1.1.1.1 2000/04/05 11:03:48 gruper Exp $
 * $Log: basic_healing.c,v $
 * Revision 1.1.1.1  2000/04/05 11:03:48  gruper
 * The changes to tea buggered up the oak wand, so I
 * had to revert stuff an' such...  This should now
 * be back to the version where tea heals over time.
 *
 * Revision 1.2  2000/04/04 11:38:44  gruper
 * Complete recode...  With PT checks.
 *
 * Revision 1.1  1998/01/06 04:14:00  ceres
 * Initial revision
 * 
*/
/**
 * This is the effect skelton docs.  This effect
 * has a classification of "healing.basic".
 * <p>
 * The only effect argument is "amount", an integer.
 * @classification healing.basic
 * @see help::effects
 */
#include <effect.h>

#define TICK 5
#define MSG_TICK 30

/** @ignore yes */
void amount_description( object player, int amount, int id ) {
   string msg;
   
   switch( amount ) {
   case 0..9:
      msg = "You feel a very slight tingling sensation in your stomach.";
      break;
   case 10..13:
      msg = "You feel a slight tingling sensation in your stomach.";
      break;
   case 14..16:
      msg = "You feel a tingling sensation in your stomach.";
      break;
   case 17..19:
      msg = "You feel a very slight warming sensation in your stomach.";
      break;
   case 20..21:
      msg = "You feel a slight warming sensation in your stomach.";
      break;
   case 22..25:
      msg = "You feel a warming sensation in your stomach.";
      break;
   case 26..29:
      msg = "A feeling of fuzziness radiates from your stomach.";
      break;
   case 30..34:
      msg = "A feeling of fuzziness radiates from your stomach and makes "
         "you curl your toes.";
      break;
   case 35..39:
      msg = "A feeling of fuzziness radiates from your stomach and makes "
         "your nipples tingle.";
      break;
   case 40..49:
      msg = "A feeling of fuzziness radiates from your stomach and makes "
         "your nipples tingle pleasantly.";
      break;
   case 50..59:
      msg = "A feeling of fuzziness radiates from your stomach and makes your "
         "nipples tingle as if someone had stroked them with an ice cube.";
      break;
   case 60..69:
      msg = "The strong feeling of fuzziness which radiates from your "
         "stomach makes your head spin.";
      break;
   case 70..79:
      msg = "A pleasant feeling of numbness radiates from your stomach.";
      break;
   case 80..99:
      msg = "A feeling of numbness radiates from your stomach.";
      break;
   case 100..119:
      msg = "A feeling of numbness radiates from your stomach and makes you "
         "feel flaccid in body and soul.";
      break;
   case 120..149:
      msg = "A feeling of flaccidity radiates from your stomach and makes you "
         "feel deficient in turgor, lacking in vigor and force.";
      break;
   case 150..200:
      msg = "There's a wooly sensation that starts in your stomach and then "
         "radiates inwards in a backwards manner, but inside out, making "
         "your whole body feel numb and overly sensitive at the same time.";
      break;
   default:
      msg = "It feels as if someone stabbed you in the abdomen, using a "
         "large ice berg.";
   } // switch( amount )

   tell_object( player, msg +"\n" );
   player->submit_ee( "amount_description", MSG_TICK, EE_ONCE );
   
} // amount_description()

/** @ignore yes */
int beginning( object player, int amount, int id ) {

   player->submit_ee( "heal", TICK, EE_CONTINUOUS );
   player->submit_ee( "amount_description", 2, EE_ONCE );
   amount = sqrt( amount );

   return amount + random( amount / 2 );

} /* beginning() */


/** @ignore yes */
int merge_effect( object player, int old_amount, int new_amount, int id ) {
   new_amount = sqrt( new_amount );
   return old_amount + new_amount + random( new_amount / 2 );
} /* merge_effect() */

/** @ignore */
void heal( object player, int amount, int id ) {
   int old_hp, heal;
   
   if( amount < 1 ) {
      player->submit_ee( 0, 0, EE_REMOVE );
   } else {
      heal = amount + random( amount );
      old_hp = player->query_hp();
      heal = player->adjust_hp( heal ) - old_hp;

      if( player->query_hp() == player->query_max_hp() )
         player->submit_ee( 0, 0, EE_REMOVE );

      player->set_arg_of( player->sid_to_enum( id ), amount - 1 );
   }
} // heal()


/** @ignore yes */
void end( object player, int amount, int id ) {
   tell_object( player,
         "You feel the effects of the healing tea wear off.\n" );
} /* end() */


/** @ignore yes */
string query_classification() { return "healing.basic"; }

/** @ignore yes */
string query_apothecarial_effect() {
   return "will aid the healing of general injuries";
} /* query_apothecarial_effect() */

