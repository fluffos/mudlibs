/**
 * This is the effect skelton docs.  This effect
 * has a classification of "body.sleep.tranquil".
 * <p>
 * Describe the arguments in here.
 * <p>
 * This effect has a shadow associated with it.
 * @classification body.sleep.tranquil
 * @see help::effects
 */

#include "path.h"
#include <effect.h>

/** @ignore yes */
void beginning( object player, int time ) {
   tell_object( player, "You feel very sleepy.\n" );
   tell_room( ENV( player ), CAP( (string)player->the_short() ) +
         " nods "+ (string)player->query_possessive() +" head sleepily.\n",
         player );
   player->submit_ee( "go_to_sleep", ({ 20, 20 }), EE_ONCE );
   player->submit_ee( 0, time, EE_REMOVE );
} /* beginning() */

void restart( object player ) {
   player->add_extra_look( TO );
} /* restart() */

/** @ignore yes */
int merge_effect( object player, int time1, int time2 ) {
   player->submit_ee( 0, time1 + time2 - (int)player->expected_tt(),
         EE_REMOVE );
   return time1 + time2;
} /* merge_effect() */
 
/** @ignore yes */
void end( object player, int time ) {
   if ( player->query_property( PASSED_OUT ) ) {
      tell_object( player, "You wake up feeling refreshed.\n" );
      tell_room( ENV( player ), CAP( (string)player->
            the_short() ) +" wakes up.\n", player );
      player->remove_property( PASSED_OUT );
      player->remove_extra_look( TO );
   } else
      tell_object( player, "You don't feel so tired anymore.\n" );
} /* end() */
 
void go_to_sleep( object player ) {
   tell_object( player, "You can't keep your eyes open anymore.  You go "+
         "to sleep.\n" );
   tell_room( ENV( player ), CAP( (string)player->the_short() ) +
         " gives a little sigh, and goes to sleep.\n", player );
   player->add_property( PASSED_OUT, 1 );
   player->add_extra_look( TO );
   player->submit_ee( "make_noises", ({ 20, 20 }), EE_CONTINUOUS );
} /* go_to_sleep() */

void make_noises( object player ) {
   switch ( random( 3 ) ) {
      case 0 :
         tell_room( ENV( player ), CAP( (string)player->
               the_short() ) +" snores gently.\n", player );
         break;
      case 1 :
         tell_room( ENV( player ), CAP( (string)player->
               the_short() ) +" snuffles in "+ (string)player->
               query_possessive() +" sleep.\n", player );
         break;
      default :
         tell_object( player, "You dream of chasing "+
               add_a( ({ "giant carrot", "rabid whelk", "large "+
               "herring", "plate of spinach", "building on wheels",
               "small hedgehog", "pair of trousers" })[ random( 7 ) ] ) +
               " through a field of "+ ({ "lobsters", "flamingoes",
               "blue daffodils", "people wearing straw hats",
               "waving sheep", "cows standing upright", "corn "+
               "with large, pink ears" })[ random( 7 ) ] +".\n" );
         tell_room( ENV( player ), CAP( (string)player->
               the_short() ) +" moves a bit in "+ (string)player->
               query_possessive() +" sleep.\n", player );
   }

   player->adjust_hp( 10 + random( 10 ) );

} /* make_noises() */

/** @ignore yes */
string query_classification() { return "body.sleep.tranquil"; }

/** @ignore yes */
string query_shadow_ob() { return SHADOWS +"tranquil_sleep"; }

string extra_look( object player ) {
  return CAP( player->HE ) +" is fast asleep.\n";
} /* extra_look() */
