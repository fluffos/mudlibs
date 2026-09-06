// Updated by Zarick - 10/01/03
//
// Updated by Allaryin - 10/14/13, minor typo correction.
#include <battle.h>

BATTLE_ACTION( 1000, "brawl" )

string query_action_name() {
   return "Head-butt";
}

void on_action( object victim ) {
   mixed result;
   mapping wc;
   int damage;
   string buf = "";
        string bp;

   this_player()->add_readiness(-700);
   if( !BATTLE_DAEMON->check_legal_melee(victim, "headbutt") )
      return;

        this_player()->add_endurance(-1);

   wc = copy(this_player()->query_wc());
   if (!mappingp(wc))
     wc = (["blunt":3]);
        wc["blunt"] += this_player()->query_str_wc();

   result = BATTLE_DAEMON->execute_melee(this_player(), wc, victim, 2, 0);
   damage = result[RESULT_MOD];

        if(sizeof(result) > 3)
           bp = victim->query_bp_name(result[RESULT_BP]);
   switch (result[RESULT_TYPE]) {
     case "miss":
       buf = "~[130~Npos attempt to head-butt ~targ misses.";
       break;
     default:
	   // sound
	   AUDIO_DAEMON->sfx_room(environment(victim),"smash.wav");
	
       if (damage == 100)
      	 buf = "~[090~Name ~verbsmash ~poss head into ~npot "+bp+" incredibly hard, knocking ~objt down!";
       else if (damage >= 40)
         buf = "~[090~Name ~verbram ~poss head into ~npot "+bp+" hard enough to leave a large bruise.";
       else if (damage >= 5)
         buf = "~[090~Name head-~verbbutt ~targ in the "+bp+".";
       else
         buf = "~[090~Name head-~verbbutt ~targ, but only really ~verbmanage to give ~refl a headache.";
       break;
   }
   if (result[RESULT_MSG])
     buf += "~[060 "+result[RESULT_MSG];

   this_player()->msg_local(buf+"~CDEF");
}
