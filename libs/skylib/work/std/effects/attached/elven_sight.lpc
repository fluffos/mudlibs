/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: elven_sight.c,v 1.6 2000/05/09 08:02:29 pinkfish Exp $
 * $Log: elven_sight.c,v $
 * Revision 1.6  2000/05/09 08:02:29  pinkfish
 * Fix up some stuff.
 *
 * Revision 1.5  2000/05/08 07:51:23  pinkfish
 * Fix up all the problems with stats and stupid gloves and stuff.
 *
 * Revision 1.4  2000/05/08 03:51:07  pinkfish
 * Fix up a bunch of problems with starting/resrtarting of effects.
 *
 * Revision 1.3  2000/05/08 00:52:35  pinkfish
 * Make sure it gets an argument...
 *
 * Revision 1.2  2000/03/28 21:23:22  ceres
 * Cap/helm fixes
 *
 * Revision 1.1  1998/01/06 04:06:32  ceres
 * Initial revision
 * 
*/
/**
 * This is the effect skelton docs.  This effect
 * has a classification of "magic.stats.sight".
 * <p>
 * Describe the arguments in here.
 * <p>
 * This effect has a shadow associated with it.
 * @classification magic.stats.sight
 * @see help::effects
 */
#include "path.h"
#include <effect.h>
#include <effects/stat_adjustment.h>

/** @ignore yes */
string query_classification() { return "magic.stats.sight"; }

/** @ignore yes */
string query_shadow_ob() { return SHADOWS +"elven_sight"; }

/** @ignore yes */
mixed* beginning( object player, object arg ) {
   if (!arg) {
      arg = previous_object();
   }
   tell_object( player, "Your eyes prickle for a moment.\n" );
   player->submit_ee( "side_effects", ({ 60, 120 }), EE_CONTINUOUS );
   player->set_active( "elven sight" );
   player->add_effect(STAT_ADJUSTMENT_EFFECT,
                        ({ arg, ([ "con" : -3, "int" : 3, "wis" : 2 ]) }));

   return ({ arg, 0 });
} /* beginning() */

/** @ignore yes */
mixed merge_effect( object player, mixed pain1, int pain2, int id ) {
   if (!pointerp(pain1)) {
      call_out((: $1->delete_effect($2) :), 0, player,
               player->query_current_effect_enum());
      return ({ pain2, 0 });
   }

   if (!pain1[0] && pain2) {
      pain1[0] = pain2;
      player->add_effect(STAT_ADJUSTMENT_EFFECT,
                     ({ pain1[0], (["wis" : 2, "con": -3, "int" : 3 ]) }));
   }

   player->submit_ee( "side_effects", ({ 60, 120 }), EE_CONTINUOUS );
   return pain1;
} /* merge_effect() */

/** @ignore yes */
void end( object player, mixed arg ) {
   STAT_ADJUSTMENT_EFFECT->remove_stat_adjustment_ob(player, arg[0]);
   tell_object( player, "You feel dizzy for a moment, but it passes.\n" );
   player->set_inactive( "elven sight" );
} /* end() */

void hurt_player( object player, int pain ) {
   string race;
   switch( pain ) {
      case 0 :
         break;
      case 1 .. 50 :
         tell_object( player, "You feel a mild twinge behind your "
               "eyes.\n" );
         break;
      case 51 .. 200 :
         player->remove_hide_invis( "hiding" );
         tell_object( player, "You feel a sharp stabbing pain between "
               "your ears.\n" );
         tell_room( environment( player ), (string)player->one_short() +
               " winces.\n", player );
         break;
      case 201 .. 800 :
         player->remove_hide_invis( "hiding" );
         tell_object( player, "Your eyes bulge and you gasp with the "
               "pain exploding inside your head.\n" );
         tell_room( environment( player ), (string)player->one_short() +
               "'s eyes bulge and "+ (string)player->query_pronoun() +
               " gasps in pain.\n", player );
         break;
      default :
         player->remove_hide_invis( "hiding" );
         tell_object( player, "Your whole body goes rigid with the "
               "thunderous detonation of pain taking place behind your "
               "eyes.\n" );
         tell_room( environment( player ), (string)player->one_short() +
               " goes rigid in sudden pain and cries out loud.\n", player );
   }
   race = (string)player->query_race_ob();
   pain *= (int)race->query_weight();
   pain /= (int)HUMAN->query_weight();
   pain -= (int)player->query_ac( "mental", pain );
   if ( (int)player->adjust_hp( -pain ) < 0 )
      player->attack_by( this_object() );
} /* hurt_player() */

void side_effects( object player, mixed stuff, int id ) {
   int times;
   int pain;

   if ( userp( player ) && !interactive( player ) )
      return;
   pain = stuff[1];
   times = sizeof( filter_array( (object *)player->query_wearing(),
         (: member_array( file_name( this_object() ),
         (string *)$1->query_wear_effects() ) != -1 :) ) );
   if ( !times ) {
      player->set_inactive( "elven sight" );
      STAT_ADJUSTMENT_EFFECT->remove_stat_adjustment_ob(player, stuff[0]);
      if ( !pain ) {
         player->submit_ee( 0, 0, EE_REMOVE );
      } else if ( pain == 1 ) {
         pain = 0;
         tell_object( player, "Your headache has finally gone.\n" );
      } else {
         pain /= 4;
         hurt_player( player, pain );
         tell_object( player, "Your headache seems to be getting better.\n" );
      }
   } else
      if ( !pain ) {
         pain = 1;
         hurt_player( player, pain );
         tell_object( player, "You feel a headache coming on.\n" );
      } else {
         pain *= 2 * times;
         hurt_player( player, pain );
         tell_object( player, "Your headache seems to be getting worse.\n"
               "Maybe it's something you're wearing?\n" );
      }
   player->set_arg_of( (int)player->sid_to_enum( id ), ({ stuff[0], pain }) );
} /* side_effects() */

string query_name() { return "elven sight enchantment"; }
