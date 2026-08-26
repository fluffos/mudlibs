/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: calm.c,v 1.1 1998/01/06 04:14:00 ceres Exp $
 * $Log: calm.c,v $
 * Revision 1.1  1998/01/06 04:14:00  ceres
 * Initial revision
 * 
*/
/**
 * This is the effect skelton docs.  This effect
 * has a classification of "body.calm".
 * <p>
 * Describe the arguments in here.
 * @classification body.calm
 * @see help::effects
 */
#include <effect.h>

/** @ignore yes */
string query_classification() { return "body.calm"; }

/** @ignore yes */
int beginning( object player, int amount, int id ) {
   player->submit_ee( "become_calm", 0, EE_ONCE );
   player->submit_ee( "reduce_amount", ({ 10, 20 }), EE_CONTINUOUS );
   return amount;
} /* beginning() */

/** @ignore yes */
int merge_effect( object player, int old_amount, int new_amount, int id ) {
   return player->expected_tt() + new_amount;
} /* merge_effect() */

/** @ignore yes */
void end( object player, int amount, int id ) {
   if ( player->query_property( "dead" ) )
      return;
   tell_object( player, "You suddenly feel more alert and you take a "+
         "fresh interest in your surroundings.\n" );
   tell_room( environment( player ), (string)player->one_short() +
         " perks up and looks more interested in what's going on.\n",
         player );
} /* end() */

void become_calm( object player, int amount, int id ) {
   tell_object( player, "You suddenly feel really calm and at peace "+
         "with the world.\n" );
   tell_room( environment( player ), (string)player->one_short() +
         " smiles dreamily and looks really calm.\n", player );
} /* become_calm() */

void reduce_amount( object player, int amount, int id ) {
   amount -= (int)player->query_con();
   if ( amount < 0 ) {
      player->submit_ee( 0, 0, EE_REMOVE );
      return;
   }
   player->set_arg_of( (int)player->sid_to_enum( id ), amount );
   call_out( "calm_down", 0, player );
} /* reduce_amount() */

void calm_down( object player ) {
   int gone;
   if ( sizeof( (int *)player->effects_matching( "fighting.combat" ) ) ) {
      player->stop_all_fight();
      gone = 1;
   }
   if ( sizeof( (int *)player->effects_matching( "magic.spell" ) ) ) {
      player->interrupt_spell();
      gone = 1;
   }
   if ( sizeof( (int *)player->effects_matching( "faith.ritual" ) ) ) {
      player->interrupt_ritual();
      gone = 1;
   }
   if ( gone ) {
      tell_object( player, "A wave of lassitude comes over you and you "+
            "lose interest in what you were doing.\n" );
      tell_room( environment( player ), (string)player->one_short() +
            " yawns distractedly.\n", player );
   }
} /* calm_down() */

string query_apothecarial_effect() {
   return "will bring on a period of apathy with bouts of disinterest";
} /* query_apothecarial_effect() */
