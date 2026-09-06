#include <battle.h>

BATTLE_ACTION( 1000, "axe" )

string query_action_name() {
   return "Hack";
}

void on_action( object victim ) {
   mixed result;
   mapping wc;
   int damage;
   object weapon, *weapons;
   string bp, buf = "";

        this_player()->add_readiness(-800);

   if( !BATTLE_DAEMON->check_legal_melee(victim, "hack") )
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
   wc["edged"] += this_player()->query_str_wc() + 1;

   wc["blunt"] += this_player()->query_str_wc();

   result = BATTLE_DAEMON->execute_melee(weapon, wc, victim, 2, 0);
   damage = result[RESULT_MOD];

   set_target(victim);

        if(sizeof(result) > 3)
           bp = victim->query_bp_name(result[RESULT_BP]);
   switch (result[RESULT_TYPE]) {
     case "miss":
       buf = "~[130~Name ~verbmiss ~targ with a wild swing of ~poss "+weapon->query_name()+"!";
       break;

     default:
	   // sound
	   AUDIO_DAEMON->sfx_room(environment(victim),"chop.wav");
	
       if (damage >= 100)
         buf = "~[090~Name ~verbhack into ~npot "+bp+", severing it and instantly killing ~objt!";
       else if (damage >= 40)
         buf = "~[090~Name ~verbhack into ~npot "+bp+", nearly severing it!";
       else if (damage >= 5) {
              if(result[RESULT_ARMOUR])
           buf = "~[090~Name ~verbhack into ~npot "+bp+", but ~post "+result[RESULT_ARMOUR]->query_name()+" absorbs some of the strike.";
              else
                buf = "~[090~Name ~verbhack into ~npot "+bp+", tearing open a long gash.";
            }
            else {
              if(result[RESULT_ARMOUR])
                buf = "~[090~Name ~verbhack at ~npot "+bp+", but the blow is deflected by ~post "+result[RESULT_ARMOUR]->query_name()+".";
              else
                buf = "~[090~Name ~verbhack into ~npot "+bp+", but only ~verbmanage to leave a small cut.";
            }
       break;
   }
   if (result[RESULT_MSG])
     buf += "~[060 "+result[RESULT_MSG];

   this_player()->msg_local(buf+"~CDEF");
}
