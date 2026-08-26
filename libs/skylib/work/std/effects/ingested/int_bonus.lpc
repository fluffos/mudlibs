#include <effect.h>

string query_classification() { return "bonus.intelligence"; }

int beginning( object player, int time ) {
   tell_object( player, "You feel more intelligent!\n");
   player->submit_ee( 0, time, EE_REMOVE );
   player->adjust_bonus_int(1);
   return time;
}

int merge_effect( object player, int time1, int time2 ) {
   int duration;
   duration = time2 + player->expected_tt();
   player->submit_ee( 0, duration, EE_REMOVE );
   return duration;
} /* merge_effect() */
 
void end( object player, int time ) {
   player->adjust_bonus_int(-1);
   if(player->query_tmp_int() >= 0){
     tell_object( player, "You no longer feel quite so intelligent.  "
       "In fact, you feel a bit slower on the uptake than when you started.\n");
     player->adjust_tmp_int(-1);
   }else{
     tell_object( player, "You no longer feel quite so intelligent.\n");
   }
} /* end() */

