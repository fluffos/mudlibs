// Will not work unless they also have the talk ai module
#include <ai_module.h>

void shopkeeper( string text, object actor, object target );
void take_job();

string query_master() {
   if( !environment() ) return 0;
   return environment()->query_var("master");
}

void set_master( string x ) {
   environment()->set_var("master", x);
}

int on_hire() {
   if( query_master() == this_player()->query_name() ) {
      command("say to " + this_player()->query_name() + " I already work for you!", environment());
   }
   else if( query_master() )
      command("say to " + this_player()->query_name() + " Sorry, I already work for someone else.", environment());
   else {
      set_master( this_player()->query_name() );
      command("say to " + query_master() + " All right, I work for you now!", environment());
      command("introduce to "+query_master(), environment());
      command("trust "+query_master(), environment());
   }
   return 1;
}

void do_please( string txt, object targ ) {
   string comm, command;
   mapping forbidden;

   forbidden = ([ "tell", "shout", "rep", "im", "mail", "bug", "idea", "newsoul", "typo", "nohelp", "cryo", "rally", "raze", "party" ]);

   if( targ && targ != environment() ) return;
   if( txt[..6] != "please " ) return;
   txt = txt[7..];

   if (strstr(txt, " ") == -1)
      command = txt;
   else
      command = txt[0..(strstr(txt, " ")-1)];

   if( m_contains(forbidden, command) == 0 ) {
      if( command( txt, environment() ) ) {
         command("emote nods obediently.", environment());
      } else if( query_notify_fail() ) {
         command("say Can't do dat, 'cuz...", environment());
         command("say \""+query_notify_fail()+"\"", environment());
      } else {
         command("emote frowns confusedly.", environment());
      }
   } else
      command("say to " + query_master() + " I'm not s'posed ta do dat.", environment());
}

void retire() {
   string master = query_master();

   debug("Retiring " + environment()->query_name() + " from " + master, "gp");

   foreach(string trustee: m_indices(environment()->query_trust())) {
      command( "trust " + trustee, environment() );
   }

   foreach(object leader: environment()->query_leaders() ) {
      command( "unfollow " + leader->query_name(), environment() );
   }

   set_master( 0 );
}

void setup() {
   object me = environment();
   if( !me ) return;
   me->set_default_doing( "looking for work" );
   me->add_talk_response( "hello", ({ "bow $(SPEAKER)", "say $(SPEAKER): Hello!" }) );
   me->add_talk_response( "follow me", "follow $(SPEAKER)", (: $2->query_name() == query_master() :) );
   me->add_talk_response( "stay here", "unfollow $(SPEAKER)", (: $2->query_name() == query_master() :) );
   me->add_talk_response( "be a shopkeeper", (: shopkeeper($1,$2,$3) :), (: $2->query_name() == query_master() && $3 == environment() :) );
   me->add_talk_response( "release", ({ "cry", "say to $(SPEAKER) Well, then we shall part ways!",
            (: retire() :) }), (: $1 == "release" && $2->query_name() == query_master() && $3 == environment() :) );
   me->add_talk_response( "please", ({ (: do_please($1, $3) :) }), (: $2->query_name() == query_master() :) );
   me->add_talk_response( "work here", ({ (: take_job() :) }), (: $2->query_name() == query_master() :) );
}

void shopkeeper( string text, object actor, object target ) {
   clone_object("/ai/buy")->move(environment());
   command( "say OK, I'll be a shopkeeper.", environment() );
}

void take_job() {
   object ob, env;
   env = environment(environment());
   foreach( ob : all_inventory(env) ) {
      if( ob->apply_for_job(environment()) ) {
         string job = ob->query_work_name();
         if( member(([ "a", "e", "i", "o", "u", "h" ]), job[0..0]) )
            job = "an " + job;
         else
            job = "a " + job;
         command( "say OK, I will become " + job + ".", environment() );
         destruct( this_object() );
         return;
      }
   }
   command( "say Sorry, I can't find any jobs to do here.", environment() );
}

ScriptBegin
   Script( "on_tick" )
      If( !query_master() )// masked due to errant wandering. --gp|| !present(query_master(), environment(Myself)) )
         Lpc( Myself->wander() )
   End
   Script( "on_sight" )
      If( query_master() )
         Abort
      If( Actor->query_is_player() )
      Do
         Delay( 2 )
         Say( Actor->query_name() + ": I'm looking for work, could you GREEN(hire) me?" )
      End
   End
   Script( "on_hunger" )
      If( find_food(Myself) )
      Do
         Lpc( eat_food_in_inventory() );
      Else If( query_master() && environment(query_master()) == my_room() )
         Say( query_master()->query_name() + ": I'm hungry, please give me something to eat." )
      End
   End
   Script( "on_thirst" )
      Lpc( Myself->add_drink(100) )
   End
End
