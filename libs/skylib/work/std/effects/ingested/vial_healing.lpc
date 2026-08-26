/* Modified from Healing Tea effect for Healing Vials
   by Lemming on 19/4/1999.
   Changes made:
   - Instant healing.
   - Change to heal strength.
*/
/**
 * This effect has a classification of "healing.vial".
 * It is the effect used by liquids in the TOSG healing vials
 * <p>
 * @classification healing.vial
 * @see help::effects
 */

#include <effect.h>

/** @ignore yes */
void beginning( object player, int amount ) {
   int heal, old_hp;
   string desc;

   player->submit_ee( 0, 0, EE_REMOVE );

   heal = amount + ( 2 * random( amount ) );
   old_hp = (int)player->query_hp();

   if( heal > 2400 )
      heal = 2400;

   heal = (int)player->adjust_hp( heal ) - old_hp;
   if( creatorp(player) )
      tell_object( player, "You have been healed " + heal + " hp (" +
                           amount + ").\n" );
   if( heal < 1 )
      return;

   switch( heal ) {
    case 1 .. 20 :
      desc = "a touch more whole";
      break;
    case 21 .. 50 :
      desc = "very slightly less damaged";
      break;
    case 51 .. 90 :
      desc = "slightly less damaged";
      break;
    case 91 .. 140 :
      desc = "ever so slightly better";
      break;
    case 141 .. 200 :
      desc = "slightly better";
      break;
    case 201 .. 270 :
      desc = "a bit better";
      break;
    case 271 .. 350 :
      desc = "quite a bit better";
      break;
    case 351 .. 440 :
      desc = "a lot better";
      break;
    case 441 .. 540 :
      desc = "a whole lot better";
      break;
   case 541 .. 650 :
      desc = "much better";
      break;
    default:
      desc = "very much better";
      break;
   }
   tell_object( player, "You feel " + desc + ".\n" );
} /* beginning() */

/** @ignore yes */
int merge_effect( object player, int amount1, int amount2 ) {
   return amount1 + amount2;
} /* merge_effect() */

/** @ignore yes */
string query_classification() { return "healing.vial"; }

string query_apothecarial_effect() {
   return "will aid the healing of general injuries";
} /* query_apothecarial_effect() */
