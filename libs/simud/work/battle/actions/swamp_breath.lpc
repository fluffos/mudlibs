#include <battle.h>

BATTLE_ACTION( 1500, "swamp_dragon" )

string query_action_name() {
   return "Swamp Breath";
}

void on_action( object victim ) {
   mixed result;
   mapping wc;
   int damage;
   string buf = "";

   if( !BATTLE_DAEMON->check_legal_melee(victim, "breathe") )
      return;

   if (this_player()->query_endurance())
      this_player()->add_endurance(-1);
   else {
      msg("~CWRNYou are too tired to fight any more!~CDEF");
      this_player()->add_readiness(-1000);
      return;
   }

   if (!this_player()->query_adjacent(victim))
      "/bin/walk"->main("to "+(string)victim);

   wc = ([ "acid" : this_player()->query_wc("acid") ]);

   result = BATTLE_DAEMON->execute_melee(this_player(), wc, victim, 2, 0);
   damage = result[RESULT_MOD];

   switch (result[RESULT_TYPE]) {
     case "miss":
       buf = "~[130~Name ~verbbelch at you ineffectively!";
       break;

     default:
       if (damage >= 10)
         buf = "~[090~Name ~verbcough wetly at ~targ, dislodging a ball of acidic phlegm! GROSS!";
       else if (damage > 0)
         buf = "~[090~Name ~verbcough wetly at ~targ, spraying ~objt.";
       else
         buf = "~[090~Name ~verbbelch at ~targ, but the mist dissipates harmlessly.";
       break;
   }
   if (result[RESULT_MSG])
     buf += "~[060 "+result[RESULT_MSG];

   this_player()->add_readiness(-1000);
   this_player()->msg_local(buf+"~CDEF");
}
