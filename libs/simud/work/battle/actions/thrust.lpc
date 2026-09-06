#include <battle.h>

BATTLE_ACTION( 1000, "polearm" )

string query_action_name() {
   return "Thrust";
}

void on_action( object victim ) {
   mixed result;   //10
   mapping wc;
   int damage;
   object weapon, *weapons;
   string buf = "";

   if( !BATTLE_DAEMON->check_legal_melee(victim, "thrust") )
      return;

   if (this_player()->query_endurance())
      this_player()->add_endurance(-1);         //20
   else {
      msg("~CWRNYou are too tired to fight any more!~CDEF");
      this_player()->add_readiness(-1000);
      return;
   }

   if (weapons = BATTLE_DAEMON->query_wielded_weapons(this_player(),
       (this_player()->query_form_object())->query_weapon_types()))
     weapon = weapons[random(sizeof(weapons))];
   else {                    //30
     msg("You are not wielding an appropriate weapon.");
     this_player()->adopt_best_form();
     return;
   }

   wc = copy(weapon->query_wc());
   if (!mappingp(wc)) {
     debug((string)weapon+" does not have a valid wc mapping.");
     return;
   }               //40
   wc["piercing"] += this_player()->query_str_wc() + 1 +
                  this_player()->query_attitude("offense");

   result = BATTLE_DAEMON->execute_melee(weapon, wc, victim, 2, 0);
   damage = result[RESULT_MOD];

   switch (result[RESULT_TYPE]) {
     case "miss":
       buf = "~[130~Name ~verbmiss ~targ with a poor thrust!";
       break;             //50

     default:
       if (damage >= 40)
         buf = "~[090~Name ~verbimpale ~npot body on ~poss "+weapon->query_name()+"!";
       else if (damage >= 20)
         buf = "~[090~Name ~verbstab ~targ with ~poss "+weapon->query_name()+"!";
       else if (damage > 0)
         buf = "~[090~Name ~verbprod ~targ with ~poss "+weapon->query_name()+".";                            //61
       else
         buf = "~[130~Npos "+weapon->query_name()+" barely ~vertgraze ~targ, doing no damage.";
       break;
   }
   if (result[RESULT_MSG])
     buf += "~[060 "+result[RESULT_MSG];

   this_player()->add_readiness(-1300);              //70
   this_player()->msg_local(buf+"~CDEF");
}
