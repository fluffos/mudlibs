//Reviewed by Kriatorr, May 27th, 2003. Slow_object on all strikes? Include BP?

#include <battle.h>

BATTLE_ACTION( 1000, "animal" )

string query_action_name() {
   return "Hamstring";
}

void on_action( object victim ) {
   mixed result;
   mapping wc;
   int damage;
   string buf = "",bp;

   this_player()->add_readiness(-450);
   if( !BATTLE_DAEMON->check_legal_melee(victim, "hamstring") )
      return;


      this_player()->add_endurance(-1);


   wc = copy(this_player()->query_wc());
   if (!mappingp(wc))
     wc = (["edged":4]);
   wc["edged"] += this_player()->query_str_wc() +
                  this_player()->query_attitude("attack");

   result = BATTLE_DAEMON->execute_melee(this_player(), wc, victim, 2, 0);
   damage = result[RESULT_MOD];
   if(sizeof(result)>3)
   bp=victim->query_bp_name(result[RESULT_BP]);

   switch (result[RESULT_TYPE]) {
     case "miss":
       buf = "~[130~Name ~verbclaw the ground in front of ~targ!";
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
       if (damage ==100) {
         buf = "~[090~Name ~verbslice ~targ viciously in the leg.";
         if (present_clone("/battle/slow_object",victim))
           break;
         clone_object("/battle/slow_object")->set_victim(victim);
       } else if (damage > 0)
         buf = "~[090~Name ~verbclaw ~targ.";
       else
         buf = "~[090~Name ~verbclaw ~targ, but ~verbdo no damage.";
       break;
   }
   if (result[RESULT_MSG])
     buf += "~[060 "+result[RESULT_MSG];

   this_player()->msg_local(buf+"~CDEF");
}
