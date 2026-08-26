/**
 * This is the effect skelton docs.  This effect
 * has a classification of "healing.basic".
 * <p>
 * Describe the arguments in here.
 * @classification healing.basic
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
   int heal, old_hp;
   string desc;

   heal = amount + random( amount );
   if ( heal > 660 )
      heal = 660;
   old_hp = (int)player->query_hp();
   heal = (int)player->adjust_hp( heal ) - old_hp;
   if ( creatorp(player) )
      tell_object( player, "You have been healed " + heal + " hp.\n");
   if ( heal < 1 )
      return;
   switch ( heal ) {
    case 1 .. 10 :
      desc = "a touch more whole";
      break;
    case 11 .. 30 :
      desc = "very slightly less damaged";
      break;
    case 31 .. 60 :
      desc = "slightly less damaged";
      break;
    case 61 .. 100 :
      desc = "ever so slightly better";
      break;
    case 101 .. 150 :
      desc = "slightly better";
      break;
    case 151 .. 210 :
      desc = "a bit better";
      break;
    case 211 .. 280 :
      desc = "quite a bit better";
      break;
    case 281 .. 360 :
      desc = "a lot better";
      break;
    case 361 .. 450 :
      desc = "a whole lot better";
      break;
   case 451 .. 550 :
      desc = "much better";
      break;
    default:
      desc = "very much better";
      break;
   }
   tell_object( player, "You feel "+ desc +".\n" );
} /* end() */

/** @ignore yes */
string query_classification() { return "healing.basic"; }

string query_apothecarial_effect() {
   return "will aid the healing of general injuries";
} /* query_apothecarial_effect() */
