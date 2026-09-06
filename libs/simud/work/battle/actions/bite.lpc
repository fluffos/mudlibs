//Updated May 25, 2003, by Kriatorr
#include <battle.h>

BATTLE_ACTION( 1000, ({ "animal", "brawl" }) )

string query_action_name() {
   return "Bite";
}

void on_action( object victim ) {
   mixed result;
   mapping wc;
   int damage;
   string buf = "",bp;

   this_player()->add_readiness(-400);
   if( !BATTLE_DAEMON->check_legal_melee(victim, "bite") )
      return;

   this_player()->add_endurance(-1);

   wc = copy(this_player()->query_wc());
   if (!mappingp(wc))
     wc = (["edged":3]);
   wc["edged"] += this_player()->query_str_wc();

   result = BATTLE_DAEMON->execute_melee(this_player(), wc, victim, 2, 0);
   damage = result[RESULT_MOD];
   if(sizeof(result)>3)
   bp=victim->query_bp_name(result[RESULT_BP]);

   switch (result[RESULT_TYPE]) {
     case "miss":
       buf = "~[130~Name ~verbsnap ~poss teeth!";
       break;
     default:
	   // sound
	   AUDIO_DAEMON->sfx_room(environment(victim),"crunch.wav");
	
       if (damage == 100)
         buf = "~[090~Name ~verbtear at the flesh of ~npot "+bp+" with ~poss vicious bite, killing ~Targ!";
       else if (damage>=40)
         buf="~[090~Name brutally ~verbmaim ~npot "+bp+" with much gnashing of teeth!";
       else if (damage>=5){
        if(result[RESULT_ARMOUR])
         buf="~[090~Name ~verbclamp down onto ~npot "+bp+", but ~verbget a shock from ~post "+result[RESULT_ARMOUR]->query_name()+".";
        else
         buf="~[090~Name ~verbclamp onto ~npot "+bp+" with ~poss nasty big pointy teeth.";
     } else {
        if(result[RESULT_ARMOUR])
         buf="~[090~Name ~verbattempt a good chomp, but ~npot "+result[RESULT_ARMOUR]->query_name()+" absorbs most of the force.";
       else
         buf = "~[090~Name ~verbbite ~targ, but ~verbdo no damage.";
       }
       break;
   }
   if (result[RESULT_MSG])
     buf += "~[060 "+result[RESULT_MSG];

   this_player()->msg_local(buf+"~CDEF");
}
