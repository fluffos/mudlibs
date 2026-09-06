// Updated by Zarick.
//
// Updated further by Allaryin on Oct 14, 2003. Minor mathematical fix.
#include <battle.h>

BATTLE_ACTION( 1000, "sword" )

string query_action_name() {
   return "Stab";
}

void on_action( object victim ) {
   mixed result;
   mapping wc;
   int damage;
   object weapon, *weapons;
   string bp, buf = "";

        this_player()->add_readiness(-575);

   if( !BATTLE_DAEMON->check_legal_melee(victim, "stab") )
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

   // convert edged wc to piercing
   if(wc["edged"]) {
      wc["piercing"] = wc["edged"];
      wc -= (["edged"]);
   }
   wc["piercing"] += this_player()->query_str_wc();

   result = BATTLE_DAEMON->execute_melee(weapon, wc, victim, 2, 0);
   damage = result[RESULT_MOD];

        if (sizeof(result) > 3)
          bp = victim->query_bp_name(result[RESULT_BP]);

   switch (result[RESULT_TYPE]) {
     case "miss":
       buf = "~[130~Name ~verbmiss ~targ by a mile with ~poss lunge!";
       break;
     default:
       if (damage >= 100)
         buf = "~[090~Name ~verbplunge ~poss "+weapon->query_name()+" deep into ~npot "+bp+", slaying ~objt instantly!";
       else if (damage >= 40)
         buf = "~[090~Name ~verbstab ~poss "+weapon->query_name()+" into ~npot "+bp+", nearly severing it!";
            else if (damage >= 5) {
              if(result[RESULT_ARMOUR])
                buf = "~[130~Name ~verbstab ~poss "+weapon->query_name()+" into ~npot "+bp+", but ~npot "+result[RESULT_ARMOUR]->query_name()+" absorbs some of the attack.";
              else
                buf = "~[090~Name ~verbstab ~poss "+weapon->query_name()+" into ~npot "+bp+", leaving a painful wound.";
            }
       else {
              if(result[RESULT_ARMOUR])
                buf = "~[090~Name ~verbtry to stab ~poss "+weapon->query_name()+" into ~npot "+bp+", but it glances off of ~post "+result[RESULT_ARMOUR]->query_name()+".";
              else
               buf = "~[090~Name barely ~verbnick ~npot "+bp+" with ~poss "+weapon->query_name()+".";
            }
       break;
   }
   if (result[RESULT_MSG])
     buf += "~[060 "+result[RESULT_MSG];

   this_player()->msg_local(buf+"~CDEF");
}
