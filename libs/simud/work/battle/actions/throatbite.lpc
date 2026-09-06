//Reviewed May 27th, 2003, by Kriatorr. include BP? chance of kill on EACH strike?
#include <battle.h>

BATTLE_ACTION( 1000, "animal" )

string query_action_name() {
   return "Throat Bite";
}

void on_action( object victim ) {
   mixed result;
   mapping wc;
   int damage;
   string buf = "";

   if( !BATTLE_DAEMON->check_legal_melee(victim, "throatbite") )
      return;

   if (this_player()->query_endurance() >= 2)
      this_player()->add_endurance(-2);
   else {
      msg("~CWRNYou are too tired to fight any more!~CDEF");
      this_player()->add_readiness(-1000);
      return;
   }

   wc = copy(this_player()->query_wc());
   if (!mappingp(wc))
     wc = (["piercing":7]);
   wc["piercing"] += wc["edged"] +
                     this_player()->query_str_wc() +
                     this_player()->query_attitude("attack");
   wc -= (["edged"]);

   result = BATTLE_DAEMON->execute_melee(this_player(), wc, victim, 2, 0);
   damage = result[RESULT_MOD];

   switch (result[RESULT_TYPE]) {
     case "miss":
       buf = "~[130~Name ~verbsnap ~poss teeth centimeters from ~npot neck!";
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
       if (damage > 10 && random(100) < 30-(victim->query_constitution())) {
         buf = "~[090~Name ~verbtear ~npot throat wide open with a ferocious bite!";
         victim->add_hp(-(victim->query_hp()));
         break;
       }
       if (damage >= 15)
         buf = "~[090~Name ~verbsink ~poss teeth into ~post neck!";
       else if (damage > 0)
         buf = "~[090~Name ~verbbite ~targ viciously on the shoulder!";
       else
         buf = "~[090~Name barely ~verbmanage to bite ~targ.";
       break;
   }
   if (result[RESULT_MSG])
     buf += "~[060 "+result[RESULT_MSG];

   this_player()->add_readiness(-1700);
   this_player()->msg_local(buf+"~CDEF");
}
