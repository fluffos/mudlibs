/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: ancient_wisdom.c,v 1.10 2000/05/08 18:07:31 pinkfish Exp $
 * $Log: ancient_wisdom.c,v $
 * Revision 1.10  2000/05/08 18:07:31  pinkfish
 * Remove the debug messages.
 *
 * Revision 1.9  2000/05/08 07:51:23  pinkfish
 * Fix up all the problems with stats and stupid gloves and stuff.
 *
 * Revision 1.8  2000/05/08 03:51:07  pinkfish
 * Fix up a bunch of problems with starting/resrtarting of effects.
 *
 * Revision 1.7  2000/05/08 02:01:23  pinkfish
 * Add in an include.
 *
 * Revision 1.6  2000/05/08 01:52:06  pinkfish
 * Fix up the effect to now use shadows and work correctly the
 * stat adjustment effect.
 *
 * Revision 1.5  2000/05/08 01:02:55  pinkfish
 * Make sure it has an arguments.
 *
 * Revision 1.4  2000/03/28 21:23:31  ceres
 * Various fixes
 *
 * Revision 1.3  1999/10/28 02:17:18  ceres
 * god knows
 *
 * Revision 1.1  1998/01/06 04:06:32  ceres
 * Initial revision
 * 
*/
/**
 * This is the effect skelton docs.  This effect
 * has a classification of "magic.stats.age".
 * <p>
 * Describe the arguments in here.
 * <p>
 * This effect has a shadow associated with it.
 * @classification magic.stats.age
 * @see help::effects
 */
#include "path.h"
#include <effect.h>
#include <effects/stat_adjustment.h>

/** @ignore yes */
string query_classification() { return "magic.stats.age"; }

/** @ignore yes */
mixed beginning( object player, object arg ) {
   if (!arg) {
      arg = previous_object();
   }
   tell_object( player, "You feel a momentary itch at the back of your "
         "neck.\n" );
   player->submit_ee( "side_effects", ({ 60, 120 }), EE_CONTINUOUS );
   player->add_effect(STAT_ADJUSTMENT_EFFECT,
                     ({ arg, (["int" : 2, "str": -3, "wis" : 3 ]) }));

   return ({ arg, 0 });
} /* beginning() */

/** @ignore yes */
mixed merge_effect( object player, mixed pain1, int pain2, int id ) {
   if (!pointerp(pain1)) {
      call_out((: $1->delete_effect($2) :), 0, player,
               player->query_current_effect_enum());
      return ;
   }

   if (!pain1[0] && pain2) {
      pain1[0] = pain2;
      player->add_effect(STAT_ADJUSTMENT_EFFECT,
                     ({ pain1[0], (["int" : 2, "str": -3, "wis" : 3 ]) }));
   }
   player->submit_ee( "side_effects", ({ 60, 120 }), EE_CONTINUOUS );
   return pain1;
} /* merge_effect() */

/** @ignore yes */
void end( object player, mixed arg ) {
   STAT_ADJUSTMENT_EFFECT->remove_stat_adjustment_ob(player, arg[0]);
   tell_object( player, "For a moment you feel like skipping, but it "
         "passes.\n" );
   player->set_inactive( "ancient wisdom" );
} /* end() */

/** @ignore yes */
void hurt_player( object player, int pain ) {
   string race;
   switch( pain ) {
      case 0 :
         break;
      case 1 .. 50 :
         tell_object( player, "You feel a mild twinge in one knee.\n" );
         break;
      case 51 .. 200 :
         player->remove_hide_invis( "hiding" );
         tell_object( player, "You feel a sharp stabbing pain at the base "+
               "of your spine.\n" );
         tell_room( environment( player ), (string)player->one_short() +
               " winces.\n", player );
         break;
      case 201 .. 800 :
         player->remove_hide_invis( "hiding" );
         tell_object( player, "Your eyes bulge and you gasp with the "
               "pain exploding in every joint of your hands.\n" );
         tell_room( environment( player ), (string)player->one_short() +
               "'s eyes bulge and "+ (string)player->query_pronoun() +
               " gasps in pain.\n", player );
         break;
      default :
         player->remove_hide_invis( "hiding" );
         tell_object( player, "Your whole body goes rigid with the "
               "thunderous detonation of pain that takes place as you try "
               "to move.\n" );
         tell_room( environment( player ), (string)player->one_short() +
               " goes rigid in sudden pain and cries out loud.\n", player );
   }
   race = (string)player->query_race_ob();
   pain *= (int)race->query_weight();
   pain /= (int)HUMAN->query_weight();
   if ( (int)player->adjust_hp( -pain ) < 0 ) {
      player->attack_by( this_object() );
   }
} /* hurt_player() */

/** @ignore yes */
void side_effects( object player, mixed arg, int id, int enum ) {
   int times;
   int pain;

   arg = player->arg_of(player->sid_to_enum(id));
   pain = arg[1];
   if ( userp( player ) && !interactive( player ) ) {
      return;
   }
   times = sizeof( filter_array( (object *)player->query_wearing(),
         (: member_array( file_name( this_object() ),
         (string *)$1->query_wear_effects() ) != -1 :) ) );
   if ( !times ) {
      player->set_inactive( "ancient wisdom" );
      STAT_ADJUSTMENT_EFFECT->remove_stat_adjustment_ob(player, arg[0]);
      if ( !pain ) {
         player->submit_ee( 0, 0, EE_REMOVE );
      } else if ( pain == 1 ) {
         pain = 0;
         tell_object( player, "You seem to be able to move without pain "
               "again.\n" );
      } else if(intp(pain)) {
         pain /= 4;
         hurt_player( player, pain );
         tell_object( player, "The ache in your joints seems to be "
                      "diminishing.\n" );
      } else { // somehow pain is nolonger an integer. :(
         player->submit_ee( 0, 0, EE_REMOVE );
      }
   } else {
      if ( !pain ) {
         pain = 1;
         hurt_player( player, pain );
         tell_object( player, "You feel old and weary.\n" );
      } else {
         pain *= 2 * times;
         hurt_player( player, pain );
         tell_object( player, "Your joints seem to be getting more "
               "inflamed.\nMaybe it's something you're wearing?\n" );
      }
   }
   player->set_arg_of( (int)player->sid_to_enum( id ), ({ arg[0], pain }) );
} /* side_effects() */

string query_name() { return "ancient wisdom enchantment"; }
