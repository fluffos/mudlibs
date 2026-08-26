#include <effect.h>

string query_classification() {
 return "ingested.no-blind"; 
}

string query_shadow_ob() {
 return "/std/shadows/ingested/blind_prot_shadow";
}

int beginning( object player, int time ) {
 player->submit_ee( 0, time, EE_REMOVE );
 tell_object(player, "You blink, and it's as if a film covers your "
   "eyes.\n");
 return time;
}

int merge_effect( object player, int time1, int time2 ) {
   int duration;

   duration = time2 + player->expected_tt();
   player->submit_ee( 0, duration, EE_REMOVE );
   return duration;
} /* merge_effect() */
 
void end( object player, int time ) {
   tell_object( player, "You blink, and suddenly, the "
      "film covering your eyes is gone.\n");
} /* end() */
