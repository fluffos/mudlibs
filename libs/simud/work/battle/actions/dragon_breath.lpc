#include <battle.h>

BATTLE_ACTION( 1000, "dragon" )

string query_action_name() {
   return "Dragon Breath";
}

void on_action( object victim ) {
   mixed result;
   mapping wc;
   int damage;
   string bp, buf = "";

   this_player()->add_readiness(-1500);
   set_target(this_object());
   set_target(victim);

   if( !BATTLE_DAEMON->check_legal_melee(victim, "dragon_breath") )
      return;

   this_player()->add_endurance(-10);

   wc = (["fire":10 + random(10)]);
   result = BATTLE_DAEMON->execute_melee(this_player(), wc, victim, 2, 0);
   damage = result[RESULT_MOD];

   if (sizeof(result) > 3)
     bp = victim->query_bp_name(result[RESULT_BP]);

   switch (result[RESULT_TYPE]) {
     case "miss":
       buf = "~[130~Name ~verbcough up a cloud of smoke.";
       break;
     default:
	   // sound
	   AUDIO_DAEMON->sfx_room(environment(victim),"fire2.wav");
	
       if (damage >= 100)
         buf = "~[090~Name ~verbbelch a jet of white flame at ~targ, reducing ~objt to a pile of ash!";
       else if (damage >= 40)
         buf = "~[090~Name ~verbbreathe a thin stream of fire, burning ~targ rather badly!";
       else if (damage >= 5) {
         if(result[RESULT_ARMOUR])
           buf = "~[130~Name ~verbspit a ball of flame at ~targ, but ~post "+result[RESULT_ARMOUR]->query_name()+" absorbs some of the attack.";
         else
           buf = "~[090~Name ~verbspit a ball of flame at ~targ, striking ~post "+bp+".";
       }
       else {
         if(result[RESULT_ARMOUR])
            buf = "~[090~Name ~verbtry to burn ~targ with ~post breath, but it glances off of ~post "+result[RESULT_ARMOUR]->query_name()+".";
         else
            buf = "~[090~Name ~verbbreathe a harmless cloud of warm air in ~npot general direction.";
       }
       break;
   }
   if (result[RESULT_MSG])
     buf += "~[060 "+result[RESULT_MSG];

   this_player()->msg_local(buf+"~CDEF");
}
