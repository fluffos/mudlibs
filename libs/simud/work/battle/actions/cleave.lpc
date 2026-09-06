#include <battle.h>

BATTLE_ACTION( 1000, "axe" )

string query_action_name() {
   return "Cleave";
}

void on_action( object victim ) {
   mixed result;
   mapping wc;
   int damage;
   object weapon, *weapons;
   string buf = "";

   if( !BATTLE_DAEMON->check_legal_melee(victim, "cleave") )
      return;

   if (this_player()->query_endurance())
      this_player()->add_endurance(-1);
   else {
      msg("~CWRNYou are too tired to fight any more!~CDEF");
      this_player()->add_readiness(-1000);
      return;
   }

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
   wc["edged"] += this_player()->query_str_wc() + 6 +
                  this_player()->query_attitude("offense");

   wc["blunt"] += this_player()->query_str_wc() + 1 +
                  this_player()->query_attitude("offense");

   result = BATTLE_DAEMON->execute_melee(weapon, wc, victim, 2, 0);
   damage = result[RESULT_MOD];

   switch (result[RESULT_TYPE]) {
     case "miss":
       buf = "~[130~Name ~verbmiss ~targ with a wild swing of ~poss "+weapon->query_name()+"!";
       break;

     default:
	   // sound
	   AUDIO_DAEMON->sfx_room(environment(victim),"chop2.wav");
	
       if (damage >= 50)
         buf = "~[090~Name ~verbcleave ~poss "+weapon->query_name()+" deep into ~npot flesh!";
       else if (damage >= 30)
         buf = "~[090~Name ~verbcleave into ~targ!";
       else if (damage > 0)
         buf = "~[090~Name ~verbswing ~poss "+weapon->query_name()+" across ~targ.";
       else
         buf = "~[130~Npos "+weapon->query_name()+" glances off of ~targ, doing no damage.";
       break;
   }
   if (result[RESULT_MSG])
     buf += "~[060 "+result[RESULT_MSG];

   this_player()->add_readiness(-1600);
   this_player()->msg_local(buf+"~CDEF");
}
