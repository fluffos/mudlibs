#include <battle.h>

BATTLE_ACTION( 1000, "swamp_dragon" )

string query_action_name() {
   return "Tail";
}

void on_action( object victim ) {
   mixed result;
   mapping wc;
   int damage;
   string buf = "";

   if( !BATTLE_DAEMON->check_legal_melee(victim, "tail") )
      return;

   if (this_player()->query_endurance())
      this_player()->add_endurance(-1);
   else {
      msg("~CWRNYou are too tired to fight any more!~CDEF");
      this_player()->add_readiness(-1000);
      return;
   }

   wc = copy(this_player()->query_wc());
   if (!mappingp(wc))
     wc = (["blunt":5]);
   wc["blunt"] += this_player()->query_str_wc() +
                  this_player()->query_attitude("attack");

   result = BATTLE_DAEMON->execute_melee(this_player(), wc, victim, 2, 0);
   damage = result[RESULT_MOD];

   switch (result[RESULT_TYPE]) {
     case "miss":
       buf = "~[130~Name ~verblash ~poss tail at ~targ, missing horribly!";
       break;

     default:
       if (damage >= 10)
         buf = "~[090~Name ~verbslam ~poss tail into ~targ!";
       else if (damage > 0)
         buf = "~[090~Name ~verbwhip ~targ with ~poss tail.";
       else
         buf = "~[090~Name ~verbgraze ~targ with ~poss tail.";
       break;
   }
   if (result[RESULT_MSG])
     buf += "~[060 "+result[RESULT_MSG];

   this_player()->add_readiness(-700);
   this_player()->msg_local(buf+"~CDEF");
}
