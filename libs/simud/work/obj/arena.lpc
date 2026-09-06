#include <object.h>
#include <wizard.h>

void init() {
   add_action( "do_flee", "flee" );
}

int do_flee() {
   msg("~CWRNYou can't run away from an arena fight!\n");
   return 1;
}

void de_aggrify(object killer, object victim) {
   object *targets;
   int index;
   if( !objectp(killer) || !objectp(victim) )
      return;
   targets = killer->query_targets();
   index = member( targets, victim );
   if( index == -1 )
      return;
   //debug( as_lpc(targets) );
   targets = targets[..index-1] + targets[index+1..];
   killer->set_targets( targets );
   //debug( as_lpc(targets) );
}

void on_death(object who) {
   string kname, tmp, cause = who->query_env_var("cause_of_death");
   object killer;

   //debug(as_lpc(who->query_env_var("cause_of_death")));
   if (!cause) {
      debug("cause_of_death glitch in arena");
      return;
   }
   sscanf(cause,"was killed by %s.",kname);
   if( !kname )
      sscanf(cause,"was slain by %s's %s",kname,tmp);
    else
       killer = single_present( lower_case(kname), environment(who) );

   if( !killer ) {
      who->death_shout();
      "/daemon/chat"->chat("death", "system", "~CDEF[~CTITARENA~CDEF] Yeah, I know it's bugged...");
   } else {
      string buf = "~CDEF[~CTITARENA~CDEF] ";
      mapping winner, loser;
      int win, loss;

      // de-aggrify the killer
      de_aggrify(killer, who);

      loser = who->query_env_var( "arena_wins" );
      if( !mappingp(loser) ) {
         loser = ([]);
         who->set_env_var( "arena_wins", loser );
      }
      loss = loser[ killer->query_name() ];

      winner = killer->query_env_var( "arena_wins" );
      if( !mappingp(winner) ) {
         winner = ([]);
         killer->set_env_var( "arena_wins", winner );
      }
      win = winner[ who->query_name() ] + 1;
      winner[who->query_name()] = win;
      killer->set_env_var( "arena_wins", winner );

      buf += killer->query_cap_name()+" has defeated "+who->query_cap_name()+"!";

      //debug("win = "+as_lpc(winner));
      //debug("lose = "+as_lpc(loser));

      "/daemon/chat"->chat("death", "system", buf);

      buf = "~CDEF[~CTITARENA~CDEF] ";
      if( win > loss )
         buf += killer->query_cap_name()+": "+win+", "+who->query_cap_name()+": "+loss;
      else
         buf += who->query_cap_name()+": "+loss+", "+killer->query_cap_name()+": "+win;
      "/daemon/chat"->chat("death", "system", buf);
   }


   // move them to the rest area
   who->move_player( find_thing(";ch;oldtown;recovery"), "lose" );
   who->validate_position();

   who->set_endurance( 1 );
   who->set_mana( 1 );
   who->set_readiness( 0 );
   who->set_held( 0 );
   who->set_busy( 0 );

   who->stop_combat();
   who->set_actions( 0 );
   who->revive();   // fixes hp, heart beat, and food
}
