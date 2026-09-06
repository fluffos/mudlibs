#include <battle.h>

BATTLE_ACTION( 1000, ({ "staff", "bludgeon" }) )

string query_action_name() {
   return "Pound";
}

void on_action( object victim ) {
   mixed result;
   mapping wc;
   int damage;
   object weapon, *weapons;
   string bp, buf = "";

        this_player()->add_readiness(-800);

   if( !BATTLE_DAEMON->check_legal_melee(victim, "pound") )
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
   wc["blunt"] += this_player()->query_str_wc() + 1;

   result = BATTLE_DAEMON->execute_melee(weapon, wc, victim, 2, 0);
   damage = result[RESULT_MOD];

        if(sizeof(result) > 3)
           bp = victim->query_bp_name(result[RESULT_BP]);

   switch (result[RESULT_TYPE]) {
	   // sound
	   AUDIO_DAEMON->sfx_room(environment(victim),"smash.wav");
	
     case "miss":
       buf = "~[130~Name ~verbmiss ~targ with a wild swing of ~poss "+weapon->query_name()+"!";
       break;

     default:
       if (damage >= 100)
         buf = "~[090~Name ~verbslam ~poss "+weapon->query_name()+" into ~npot "+bp+", crushing it into pulp and instantly slaying ~objt!";
       else if (damage >= 40)
         buf = "~[090~Name ~verbpound ~targ in the "+bp+" with ~poss "+weapon->query_name()+", nearly crushing it!";
       else if (damage >= 5) {
              if(result[RESULT_ARMOUR])
            buf = "~[090~Name ~verbpound ~targ in the "+bp+", leaving a dent in ~post "+result[RESULT_ARMOUR]->query_name()+".";
              else
                 buf = "~[090~Name ~verbpound ~npot "+bp+", leaving a visible wound.";
            }
            else {
              if(result[RESULT_ARMOUR])
                buf = "~[090~Name ~verbpound ~npot "+bp+", but the blow glances off of ~post "+result[RESULT_ARMOUR]->query_name()+".";
              else
                buf = "~[090~Name ~verbpound ~targ in the "+bp+", leaving a small bruise.";
            }
       break;
   }
   if (result[RESULT_MSG])
     buf += "~[060 "+result[RESULT_MSG];

   this_player()->msg_local(buf+"~CDEF");
}
