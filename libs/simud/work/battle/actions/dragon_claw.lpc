#include <battle.h>

BATTLE_ACTION( 1000, ({ "dragon" }) )

string query_action_name() {
   return "Dragon Claw";
}

void on_action( object victim ) {
   mixed result;
   mapping wc;
   int damage, attacks = 1 + random(4);
   string buf = "";
   string bp;

   if( !BATTLE_DAEMON->check_legal_melee(victim, "dragon_claw") )
      return;
   wc = copy(this_player()->query_wc());
   wc["edged"] += this_player()->query_str_wc();

   // dragon will attack multiple times with its claws
   while ( attacks && victim->query_hp() > 0 && sizeof(wc) ) {
     this_player()->add_readiness(-300);
     this_player()->add_endurance(-1);
     result = BATTLE_DAEMON->execute_melee(this_player(), wc, victim, 3, 0);
     damage = result[RESULT_MOD];
	 attacks--;

     if (sizeof(result) > 3)
       bp = victim->query_bp_name(result[RESULT_BP]);
	
     switch (result[RESULT_TYPE]) {
       case "miss":
         buf = "~[130~Name ~verbmiss ~targ with ~poss claws!";
         break;
       default:
	   // sound
	   AUDIO_DAEMON->sfx_room(environment(victim),"slice.wav");
	
  	     if( damage == 100 )
	       buf = "~[090~Name ~verbmaul ~targ viciously with ~poss claws, killing ~objt.";
	     else if (damage >= 40)
	       buf = "~[090~Name ~verbcut deep into ~npot "+bp+" with ~poss claws.";
	     else if (damage >= 5) {
	       if (result[RESULT_ARMOUR])
	          buf = "~[090~Name ~verbclaw ~targ hard in the "+bp+", but ~post "+result[RESULT_ARMOUR]->query_name()+" absorbs some of the blow.";
	       else
	          buf = "~[090~Name ~verbclaw ~targ hard in the "+bp+" with ~poss claws.";
	     } else {
	       if (result[RESULT_ARMOUR])
	          buf = "~[090~Name ~verbclaw ~npot "+bp+", but ~post "+result[RESULT_ARMOUR]->query_name()+" absorbs most of the blow.";
	       else
	          buf = "~[090~Name ~verbclaw ~npot "+bp+", but the blow seems to have little effect.";
	     }
         break;
     } // switch
     if (result[RESULT_MSG])
       buf += "~[060 "+result[RESULT_MSG];
     this_player()->msg_local(buf+"~CDEF");
	 // reduce wc of additional attacks
	 wc["edged"]--;
	 wc["piercing"]--;
	 if (wc["edged"] < 0)
	   wc -= (["edged"]);
	 if (wc["piercing"] < 0)
	   wc -= (["piercing"]);
   } // while
}
