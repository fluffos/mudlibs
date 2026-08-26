#include <effect.h>

#define CURE 200

string query_classification() { return "caffeine.high"; }

int beginning( object player, int arg, int sid ) {
   tell_object( player, "The drink seems to be composed "
                        "mostly of sugar syrup and gas.  "
                        "You feel a slight burning sensation "
                        "as it fizzes down your throat.\n" );
   tell_room( environment( player ), (string)player->the_short() + " seems filled with energy.\n", player);
   player->submit_ee( "soul_reactions", ({ 10, 10 }), EE_CONTINUOUS );
   player->submit_ee( 0, arg, EE_REMOVE );
   return 0;
} /* beginning() */

void merge_effect() { return; }

void end( object player, int arg, int sid ) {
   if ( !player->query_property( "dead" ) )
      tell_object( player, "The caffeine seems to have worn off.\n" );
} /* end() */

void soul_reactions( object player, int arg, int sid ) {
   switch ( random( 9 ) ) {
      case 0 :
         player->new_parser( "frolic" );
         break;
      case 1 :
         player->new_parser( "burp" );
         break;
      case 2 :
         player->new_parser( "burp all" );
         break;
      case 3 :
         player->new_parser( "bounce" );
         break;
      case 4 :
         player->run_away();
         break;
      case 5 :
         player->new_parser( "wibble" );
         break;
      case 6 :
         player->new_parser( "hiccup" );
         break;
      case 7 :
         player->run_away();
         break;
      default :
         player->new_parser( "zip" );
   }
   arg -= CURE / 10;
   if ( arg < 0 )
      arg = 0;
   player->set_arg_of( (int)player->sid_to_enum( sid ), arg );
} /* soul_reactions() */

int test_remove( object player, int arg, int enum, int bonus ) {
   arg += bonus;
   if ( arg > CURE )
      return 1;
   player->set_arg_of( enum, arg );
   return 0;
} /* test_remove() */
