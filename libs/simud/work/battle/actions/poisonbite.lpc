//Updated May 25, 2003, by Kriatorr
#include <battle.h>

BATTLE_ACTION( 1000, "animal" )

string query_action_name() {
   return "Poison Bite";
}

void do_bleeder( object victim, int damage ) {
   object ob, *obs;
   obs = filter( all_inventory(victim), (: $1->query_is_bleeder() && $1->query_type() == "poison" :) );
   if( sizeof(obs) ) ob = obs[0];
   if( !ob ) {
      ob = clone_object("/battle/bleeder_object");
      ob->set_speed( max(damage / 5, 1) );
      ob->set_strength( max(5, damage / 2) );
      ob->set_victim( victim );
   } else {
      ob->add_speed(1);
      ob->add_strength( max(5, damage / 2) );
   }
   msg_object(victim,"~[100Poison is injected into your body!~CDEF");
}

void on_action( object victim ) {
   mixed result;
   mapping wc;
   int damage, ohp, dhp;
   string buf = "",bp;

   this_player()->add_readiness(-400);
   if( !BATTLE_DAEMON->check_legal_melee(victim, "poisonbite") )
      return;

   this_player()->add_endurance(-1);

   wc = copy(this_player()->query_wc());
   if (!mappingp(wc))
     wc = (["edged":3]);
   wc["edged"] += this_player()->query_str_wc();
   wc["poison"] += wc["edged"] / 2;

   ohp = victim->query_hp();
   result = BATTLE_DAEMON->execute_melee(this_player(), wc, victim, 2, 0);
   damage = result[RESULT_MOD];
   dhp = ohp - victim->query_hp();
   if(sizeof(result)>3)
      bp=victim->query_bp_name(result[RESULT_BP]);

   switch (result[RESULT_TYPE]) {
     case "miss":
       buf = "~[130Venom drips from ~npos teeth.";
       break;
     default:
       if (damage == 100)
         buf = "~[090~Name ~verbtear at the flesh of ~npot "+bp+" with ~poss vicious bite, killing ~Targ!";
       else if (damage>=40)
         buf="~[090~Name brutally ~verbmaim ~npot "+bp+" with much gnashing of teeth!";
       else if (damage>=5){
        if(result[RESULT_ARMOUR])
         buf="~[090~Name ~verbclamp down onto ~npot "+bp+", but ~verbget a shock from ~post "+result[RESULT_ARMOUR]->query_name()+".";
        else
         buf="~[090~Name ~verbclamp onto ~npot "+bp+" with ~poss nasty big pointy teeth.";
     } else {
        if(result[RESULT_ARMOUR])
         buf="~[090~Name ~verbattempt a good chomp, but ~npot "+result[RESULT_ARMOUR]->query_name()+" absorbs most of the force.";
       else
         buf = "~[090~Name ~verbbite ~targ, but ~verbdo no damage.";
       }
       break;
   }
   if (result[RESULT_MSG])
     buf += "~[060 "+result[RESULT_MSG];
   this_player()->msg_local(buf+"~CDEF");

   // and now for the fun part ;)
   if (dhp)
      do_bleeder(victim, dhp);
}
