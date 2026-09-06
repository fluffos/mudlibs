// Updated May 27th, 2003 by Kriatorr
//
// Updated further by Zarick.
//
// Updated even further by Allaryin on Oct 14, 2003. Minor mathematical fix.
//
// This is the biggest baddest meanest attack in the animal form. If the
// attacker somehow doesn't have a WC set, it defaults to 7, otherwise it
// simply adds 2 points to the edged wc of the attack.
//
// In addition to raw damage, this attack opens up a wound on the target that
// essentially doubles the damage actually inflicted by the attack. Consecutive
// uses of the attack will strengthen the bleeder.
#include <battle.h>

BATTLE_ACTION( 1000, "animal" )

string query_action_name() {
   return "Rend";
}

void on_action( object victim ) {
   mixed result;
   mapping wc;
   int damage;
   object bleeder;
   string buf = "",bp;

   this_player()->add_readiness(-500);
   if( !BATTLE_DAEMON->check_legal_melee(victim, "rend") )
      return;


      this_player()->add_endurance(-2);

   wc = copy(this_player()->query_wc());
   if (!mappingp(wc))
     wc = (["edged":7]);
   else
     wc["edged"] += 2;
   wc["edged"] += this_player()->query_str_wc();

   result = BATTLE_DAEMON->execute_melee(this_player(), wc, victim, 2, 0);
   damage = result[RESULT_MOD];
   if(sizeof(result)>3)
   bp=victim->query_bp_name(result[RESULT_BP]);
   if (damage > 0) {
     bleeder = present_clone("/battle/bleeder_object",victim);
     if (bleeder)
       if (bleeder->query_type() == "wound") {
         bleeder->add_strength(5+damage-victim->query_stat("con"));
       } else
         bleeder = 0;

     if (!bleeder) {
       bleeder = clone_object("/battle/bleeder_object");
       bleeder->set_dam_type("edged");
       bleeder->set_hit_msg("You are losing ~CBRTblood~CWRN!");
       bleeder->set_end_msg("The bleeding finally stops.");
       bleeder->set_victim(victim);
     }
     bleeder->set_heart_beat(1);
   }

   switch (result[RESULT_TYPE]) {
     case "miss":
       buf = "~[130~Name ~verblunge at ~targ with claws bared, but ~verbmiss horribly!";
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
       if (damage == 100)
         buf = "~[090~Name ~verbtear gaping, life-extinguishing wounds across ~npot "+bp+" with ~poss claws.";
       else if (damage >= 40)
         buf = "~[090~Name ~verbshred ~npot "+bp+" ferociously!";
       else if (damage>=5){
         if(result[RESULT_ARMOUR])
           buf="~[090~Name ~verbswing out quickly with ~poss claws, but ~npot "+result[RESULT_ARMOUR]->query_name()+" prevents the strike from reaching a critical point.";
       else
           buf="~[090~Name ~verbslice ~targ violently, leaving bloody trails on ~post "+bp+".";
      }else{
         if(result[RESULT_ARMOUR])
           buf="~[090~Name ~verbstrike at ~targ, but ~post "+result[RESULT_ARMOUR]->query_name()+" impairs the strike.";
       else
           buf="~[090~Name ~verbcut ~targ with ~poss claws, but does little damage.";
       }
       break;
   }
   if (result[RESULT_MSG])
     buf += "~[060 "+result[RESULT_MSG];

   //this_player()->add_readiness(-1000);(unsure)
   this_player()->msg_local(buf+"~CDEF");
}
