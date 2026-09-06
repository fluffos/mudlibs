#include <battle.h>

BATTLE_ACTION( 1000, "dragon" )

string query_action_name() {
   return "Dragon Tail";
}

void on_action( object victim ) {
   mixed result;
   mapping wc;
   int damage;
   string buf = "";

   this_player()->add_readiness(-1000);
   if( !BATTLE_DAEMON->check_legal_melee(victim, "dragon_tail") )
      return;

   if (this_player()->query_endurance())
      this_player()->add_endurance(-2);
   else {
      msg("~CWRNYou are too tired to fight any more!~CDEF");
      this_player()->add_readiness(-1000);
      return;
   }

   wc = copy(this_player()->query_wc());
   wc["blunt"] += this_player()->query_str_wc();

   result = BATTLE_DAEMON->execute_melee(this_player(), wc, victim, 2, ATT_NO_PARRY);
   damage = result[RESULT_MOD];

   switch (result[RESULT_TYPE]) {
     case "miss":
       buf = "~[130~Npos tail lashes at ~targ but does not strike ~objt.";
       break;

     default:
	   // sound
	   AUDIO_DAEMON->sfx_room(environment(victim),"whipcrack.wav");
	
       if (damage)
         victim->add_readiness(-damage*5);

	   if (damage >= 100)
	     buf = "~[090~Targ ~vertis crushed by ~npos tail!";
	   else if (damage >= 50) {
         buf = "~[090~Name ~verbslam ~targ with ~poss tail!";
         victim->add_busy(3);
       } else if (damage >= 5) {
         buf = "~[090~Targ ~vertis struck a glancing blow of ~npos tail.";
         victim->add_busy(1);
       } else
         buf = "~[130~Npos tail strikes ~targ harmlessly.";
       break;
   }
   if (result[RESULT_MSG])
     buf += "~[060 "+result[RESULT_MSG];

   this_player()->msg_local(buf+"~CDEF");
}
