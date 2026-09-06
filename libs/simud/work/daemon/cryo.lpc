#include <time.h>

/*

Cryo daemon

Purpose:  Allow players to have a normal life by allowing them to specify certain days they are not allowed to be on.

Usage instructions:
Clone and let master object take care of minutely checks.  Optionally, you can call "is_frozen_today" with the player object as the argument if you want hard cryo enforcement at login time.  Advised for flakey souls.

*/

void create() {
   call_out("check_all_players", 60);
}

// returns 0 if player is ok.
// returns 1 if player is supposed to be frozen today

int is_frozen_today(object player) {
   int today = localtime(time())[TM_WDAY];
   int *days = player->query_env_var("cryo_days");
   if (days == 0)
      return 0;//if no cryo has been set, not frozen ANYTIME
   if (member(days,today) != -1)
      return 1;
   else
      return 0;
}

void cryo_boot(object offender) {
   foreach(object who : users() ) {
      set_actor( offender );
      set_listener( who );
      msg_object(who,"~[140~Name spontaneously ~verbfreeze into cryo-stasis!~CDEF");
   }
   offender->quit(1);
}

void check_all_players() {
   while(remove_call_out("check_all_players") != -1)
      continue;
   foreach(object who : users() ) {
//      if (who->query_name() != "gp")
//         continue;//debug patch for testing
      if (is_frozen_today(who)) {
         //todo: check for in combat.
         cryo_boot(who);
      }
   }
   call_out("check_all_players", 60);
}
