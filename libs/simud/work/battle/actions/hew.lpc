#include <battle.h>

BATTLE_ACTION( 1000, "axe" )

string query_action_name() {
   return "Hew";
}

void on_action( object victim ) {
   mixed result;
   mapping wc;
   int damage;
   object weapon, *weapons;
   string bp, buf = "";

   this_player()->add_readiness(-1300);
   set_actor(this_player());
   set_target(victim);

   if( !BATTLE_DAEMON->check_legal_melee(victim, "hew") )
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
   wc["edged"] += this_player()->query_str_wc() + 2;

   wc["blunt"] += this_player()->query_str_wc();

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
	   AUDIO_DAEMON->sfx_room(environment(victim),"chop2.wav");
	
       if (damage >= 100)
         buf = "~[090~Name ~verbdrive ~poss "+weapon->query_name()+" deep into ~npot "+bp+", cleaving ~objt in two!";
       else if (damage >= 40)
         buf = "~[090~Name ~verbdrive ~poss "+weapon->query_name()+" deep into ~npot "+bp+", nearly hewing ~objt in half!";
       else if (damage >= 5)
         buf = "~[090~Name ~verbhew ~npot "+bp+" with ~poss "+weapon->query_name()+", leaving a large wound.";
       else
         buf = "~[090~Name ~verbhew at ~npot "+bp+", but only ~verbinflict a minor wound.";
       break;
   }
   if (result[RESULT_MSG])
     buf += "~[060 "+result[RESULT_MSG];

   this_player()->msg_local(buf+"~CDEF");
}
