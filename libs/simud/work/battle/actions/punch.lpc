// This action has been updated by Allaryin

#include <battle.h>

BATTLE_ACTION( 1000, "brawl" )

string query_action_name() {
   return "Punch";
}

void on_action( object victim ) {
   mixed result;
   mapping wc;
   int damage;
   string buf = "", bp;

   this_player()->add_readiness(-400);
   // Note: still deduct readiness if it's not a legal move, else we loop forever!
   if( !BATTLE_DAEMON->check_legal_melee(victim, "punch") )
      return;

   this_player()->add_endurance(-1);

   wc = copy(this_player()->query_wc());
   if (!mappingp(wc))
     wc = (["blunt":3]);
   wc["blunt"] += this_player()->query_str_wc();

   result = BATTLE_DAEMON->execute_melee(this_player(), wc, victim, 2, 0);
   damage = result[RESULT_MOD];
   if (sizeof(result) > 3)
     bp = victim->query_bp_name(result[RESULT_BP]);

   switch (result[RESULT_TYPE]) {
     case "miss":
       buf = "~[130~Name ~verbtake a good swing at ~targ with ~poss fist, but the blow never connects, swinging wildly to the side.";
       break;

     default:
	   // sound
	   AUDIO_DAEMON->sfx_room(environment(victim),"hithard.wav");
	
       if( damage == 100 )
         buf = "~[090~Npos fist powers into ~post "+bp+", knocking ~objt out completely.";
       else if (damage >= 40)
         buf = "~[090~Name ~verbpound ~targ solidly in ~post "+bp+" with ~poss fist, nearly knocking ~objt flying from the shock.";
       else if (damage >= 5) {
         if (result[RESULT_ARMOUR])
            buf = "~[090~Name ~verbpunch ~targ firmly in ~post "+bp+", but ~post "+result[RESULT_ARMOUR]->query_name()+" absorbs some of the blow.";
         else
            buf = "~[090~Name ~verbpunch ~targ firmly in ~post "+bp+", causing ~objt to wince in pain.";
       } else {
         if (result[RESULT_ARMOUR])
            buf = "~[090~Name ~verbpunch ~targ in ~post "+bp+", but ~post "+result[RESULT_ARMOUR]->query_name()+" absorbs most of the blow.";
         else
            buf = "~[090~Name ~verbpunch ~targ in ~post "+bp+", but the blow seems to have little effect.";
       }
       break;
   }
   if (result[RESULT_MSG])
     buf += "~[060 "+result[RESULT_MSG];

   this_player()->msg_local(buf+"~CDEF");
}
