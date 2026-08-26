#include <effect.h>

string query_classification() { return "jewellery.ring.lag"; }

void beginning(object player, int time ) { 
          
   tell_object( player, "You feel like you have trouble moving...\n" );
   player->submit_ee( "test_worn", 1, EE_ONCE );
   player->submit_ee( "test_worn", 20, EE_CONTINUOUS );
   player->submit_ee( "messages", ({ 50, 110 }), EE_CONTINUOUS );
}

int merge_effect( object player, int old_state, int new_state ) {
   return new_state;
} /* merge_effect() */

int test_for_effect( object thing ) {
   if ( !thing )
      return 0;
   return member_array( file_name( this_object() ),
         (string *)thing->query_wear_effects() ) != -1;
} /* test_for_effect() */

void test_worn( object player ) {
   if ( player->still_auto_loading() )
      return;
   if ( !sizeof( filter_array( (object *)player->query_armours(),
         "test_for_effect", this_object() ) ) ) {
      player->submit_ee( 0, 0, EE_REMOVE );
      return;
   }
} /* test_worn() */

void end(object player) { 
   tell_object( player, "You feel able to move at normal pace again.\n" );
} /* end() */

void messages( object person ) {
  tell_object( person, ({ "The air around you feels like syrup.\n",
                          "Each moment feels like an eternity.\n",
                          "The world races past you...\n",
                          "You have trouble moving...\n" })[random(4)] );
} /* messages() */

