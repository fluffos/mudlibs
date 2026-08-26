#include "path.h"
#include <effect.h>

string query_classification() { return "clothing.protection.no-blind"; }
string query_shadow_ob() { return SHADOWS+"goggle_shadow"; }
int query_indefinite() { return 1; }
void beginning( object player, int time, int id) {
   tell_object( player, "The world looks somewhat funny "
               "through the slightly blue-tinted goggles, "
               "but you soon adjust.\n");
}
void restart( object player, int amount, int id ){
  beginning(player, amount, id);
} /* restart() */

void merge_effect( object player, int time1, int time2 ) {
   return;
} /* merge_effect() */
void end( object player, int time ) {
   tell_object( player, "The light seems much brighter to your "
       "unprotected eyes.\n");
} /* end() */
int test_for_effect( object thing ) {
   if ( !thing )
      return 0;
   return member_array( file_name( this_object() ),
         (string *)thing->query_wear_effects() ) != -1;
} /* test_for_effect() */