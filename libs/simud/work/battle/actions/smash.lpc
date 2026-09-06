// Updated by Zarick.
//
// Updated further by Allaryin on Oct 14, 2003. Minor mathematical fix.
#include <battle.h>

BATTLE_ACTION( 1000, "bludgeon" )

string query_action_name() {
   return "Smash";
}

void on_action( object victim ) {
   mixed result;
   mapping wc;
   int damage;
   object weapon, *weapons;
   string bp, buf = "";

        this_player()->add_readiness(-1300);

   if( !BATTLE_DAEMON->check_legal_melee(victim, "smash") )
      return;

   this_player()->add_endurance(-1);

   if (weapons = BATTLE_DAEMON->query_wielded_weapons(this_player(),
       (this_player()->query_form_object())->query_weapon_types()))
     weapon = weapons[random(sizeof(weapons))];
   else {
     msg("You are not wielding an appropriate weapon.");
     this_player()->adopt_best_form();
     return;
   }

   wc = copy(weapon->query_wc());
   if (!mappingp(wc)) {
     debug((string)weapon+" does not have a valid wc mapping.");
     return;
   }

   // used to be a +4 bonus, which is -obscene- under the new system
   wc["blunt"] += this_player()->query_str_wc() + 2;
   // used to be a +1 bonus regardless of whether the weapon had pointy bits
   if (wc["piercing"])
      wc["piercing"]+= this_player()->query_str_wc() + 1;

   result = BATTLE_DAEMON->execute_melee(weapon, wc, victim, 2, 0);
   damage = result[RESULT_MOD];

        if(sizeof(result) > 3)
           bp = victim->query_bp_name(result[RESULT_BP]);

   switch (result[RESULT_TYPE]) {
     case "miss":
       buf = "~[130~Name ~verbmiss ~targ with a wild swing of ~poss "+weapon->query_name()+"!";
       break;

     default:
	   // sound
	   AUDIO_DAEMON->sfx_room(environment(victim),"smash.wav");
	
       if (damage >= 100)
         buf = "~[090~Name ~verbdeliver a frightening ~[150SMASH~[090 to ~npot "+bp+", instantly snuffing out ~post life!";
       else if (damage >= 40)
         buf = "~[090~Name ~verbsmash ~npot "+bp+" with ~poss "+weapon->query_name()+"!";
       else if (damage >= 5)
         buf = "~[090~Name ~verbslam ~poss "+weapon->query_name()+" into ~npot "+bp+".";
       else
         buf = "~[130~Name barely ~verbgraze ~npot "+bp+" with ~poss "+weapon->query_name()+".";
       break;
   }
   if (result[RESULT_MSG])
     buf += "~[060 "+result[RESULT_MSG];

   this_player()->msg_local(buf+"~CDEF");
}
