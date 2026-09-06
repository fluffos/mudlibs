// Updated by Zarick.
//
// This action is the strongest attack in the brawl form. In addition to doing
// slightly more damage than a normal punch, it also stuns the target for 1-3
// heartbeats every time it lands. The more damage it does, the longer they are
// stunned.
//
// Further update should make the attack only target upper body, eh?
#include <battle.h>

BATTLE_ACTION( 1500, "brawl" )

string query_action_name() {
   return "Uppercut";
}

void on_action( object victim ) {
   mixed result;
   mapping wc;
   int damage;
   string bp, buf = "";

   this_player()->add_readiness(-1000);

   if( !BATTLE_DAEMON->check_legal_melee(victim, "uppercut") )
      return;

   this_player()->add_endurance(-2);

   wc = copy(this_player()->query_wc());
   if( !mappingp(wc) )
      wc = (["blunt":4]);
   else
      wc["blunt"] += 1;

   result = BATTLE_DAEMON->execute_melee(this_player(), wc, victim, 2, 0);
   damage = result[RESULT_MOD];

   switch (result[RESULT_TYPE]) {
     case "miss":
       buf = "~[130~Name ~verbthrow a wild punch into the air.";
       break;
     default:
            if (damage >=100)
              buf = "~[090~Name ~verbdrive ~poss fist with extreme force into ~npot chin, shattering bone and knocking ~objt out!";
       if (damage >=40) {
      	 buf = "~[090~Name ~verbdrive ~poss fist into ~npot chin so hard that it stuns ~objt for a moment!";
         victim->add_held(3);
       } else if (damage >= 20) {
         buf = "~[090~Name ~verbland an uppercut on ~npot chin, dazing ~objt slightly.";
         victim->add_held(2);
       } else if (damage >= 5) {
         buf = "~[090~Name ~verbpunch ~targ in the chin, leaving ~objt a bit winded.";
         victim->add_held(1);
       } else
         buf = "~[090~Name ~verbgraze ~npot chin lightly.";
       break;
   }
   if (result[RESULT_MSG])
     buf += "~[060 "+result[RESULT_MSG];

   this_player()->msg_local(buf+"~CDEF");
}
