#include <battle.h>

BATTLE_ACTION( 1000, "whip" )

string query_action_name() {
   return "Lacerate";
}

void on_action( object victim ) {
   mixed result;
   mapping wc;
   int damage;
   object weapon, *weapons;
   string buf = "";

   if( !BATTLE_DAEMON->check_legal_melee(victim, "lacerate") )
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
   wc["edged"] += this_player()->query_str_wc() + 4 +
                  this_player()->query_attitude("offense");

   result = BATTLE_DAEMON->execute_melee(weapon, wc, victim, 2, 0);
   damage = result[RESULT_MOD];

   switch (result[RESULT_TYPE]) {
     case "miss":
       buf = "~[130~Name ~verbmiss ~targ with a crack of ~poss whip!";
       break;
/*
     case "block":
     case "parry":
     case "dodge":
       if (damage)
         buf = "~[130~Targ almost ~vert"+result[RESULT_TYPE]+" ~npos punch, but not quite.";
       else
         buf = "~[130~Targ ~vert"+result[RESULT_TYPE]+" ~npos punch!";
       break;

     case "hit":
     case "counter":
*/
     default:
	   // sound
	   AUDIO_DAEMON->sfx_room(environment(victim),"whipcrack.wav");
	
       if (damage >= 10)
         buf = "~[090~Name ~verblacerate ~targ viciously!";
       else if (damage > 0)
         buf = "~[090~Name ~verbcut ~targ with ~poss "+weapon->query_name()+".";
       else
         buf = "~[130~Name barely ~verbnick ~targ with the tip of ~poss "+weapon->query_name()+".";
       break;
   }
   if (result[RESULT_MSG])
     buf += "~[060 "+result[RESULT_MSG];

   this_player()->add_readiness(-500);
   this_player()->msg_local(buf+"~CDEF");
}
