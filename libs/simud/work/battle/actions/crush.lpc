#include <battle.h>

BATTLE_ACTION( 1000, "flail" )

string query_action_name() {
   return "Crush";
}

void on_action( object victim ) {
   mixed result;
   mapping wc;
   int damage;
   object weapon, *weapons;
   string buf = "";

   if( !BATTLE_DAEMON->check_legal_melee(victim, "crush") )
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
   wc["blunt"] += this_player()->query_str_wc() + 2 +
                  this_player()->query_attitude("offense");
   wc["piercing"]+= this_player()->query_str_wc() + 1 +
                    this_player()->query_attitude("offense");

   result = BATTLE_DAEMON->execute_melee(weapon, wc, victim, 2, 0);
   damage = result[RESULT_MOD];

   switch (result[RESULT_TYPE]) {
     case "miss":
       buf = "~[130~Name ~verbmiss ~targ with a wild swing of ~poss "+weapon->query_name()+"!";
       break;

     default:
	   // sound
	   AUDIO_DAEMON->sfx_room(environment(victim),"hithard.wav");
	
       if (damage >= 40)
         buf = "~[090~Name ~verbdeliver a mighty crush to ~npot head!";
       else if (damage >= 20)
         buf = "~[090~Name ~verbcrush ~targ with ~poss flail!";
       else if (damage > 0)
         buf = "~[090~Name ~verbthwack ~targ with ~poss "+weapon->query_name()+".";
       else
         buf = "~[130~Name barely ~verbgraze ~targ with ~poss "+weapon->query_name()+".";
       break;
   }
   if (result[RESULT_MSG])
     buf += "~[060 "+result[RESULT_MSG];

   this_player()->add_readiness(-1300);
   this_player()->msg_local(buf+"~CDEF");
}
