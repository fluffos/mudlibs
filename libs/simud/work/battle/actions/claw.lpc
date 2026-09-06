//Updated May 25 by Kriatorr

#include <battle.h>

BATTLE_ACTION( 1000, "animal" )

string query_action_name() {
   return "Claw";
}

void on_action( object victim ) {
   mixed result;
   mapping wc;
   int damage;
   string buf = "", bp;

   this_player()->add_readiness(-300);
   if( !BATTLE_DAEMON->check_legal_melee(victim, "claw") )
      return;


      this_player()->add_endurance(-1);




   wc = copy(this_player()->query_wc());
   if (!mappingp(wc))
     wc = (["edged":4]);
   wc["edged"] += this_player()->query_str_wc() +
                  this_player()->query_attitude("attack");

   result = BATTLE_DAEMON->execute_melee(this_player(), wc, victim, 2, 0);
   damage = result[RESULT_MOD];
   if (sizeof(result)>3)//is 3 an arbitrary number, necessary by code, or does it have meaning?
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
         buf = "~[130~Targ almost ~vert"+result[RESULT_TYPE]+" ~npos claw, but not quite.";
       else
         buf = "~[130~Targ ~vert"+result[RESULT_TYPE]+" ~npos claws!";
       break;

     case "hit":
     case "counter":
*/
     default:
	   // sound
	   AUDIO_DAEMON->sfx_room(environment(victim),"slice.wav");
	
       if (damage == 100)
         buf = "~[090~Name ~verbslice ~post "+bp+" viciously with ~poss claws, extinguishing ~post life!";
       if (damage>=40)
         buf = "~[090~Name ~verbcut ~targ deeply in the "+bp+" with ~poss claws.";
       else if (damage >= 5)
       {
          if(result[RESULT_ARMOUR])//must be specific to bodypart! helm does not protect legs, etc.
             buf="~[090~Name violently ~verbclaw ~targ, but ~post "+result[RESULT_ARMOUR]->query_name()+" provides a little protection.";
          else
             buf = "~[090~Name ~verbclaw ~post "+bp+".";
       }
       else
       {
          if(result[RESULT_ARMOUR])
          buf = "~[090~Name ~verbclaw ~targ, but ~verbdo nearly no damage, as ~post "+result[RESULT_ARMOUR]->query_name()+" deflects the strike!";
          else
          buf="~[090~Name ~verbtry a daring swipe with ~poss claws, but ~targ will be just fine!";
       }
       break;
   }
   if (result[RESULT_MSG])
     buf += "~[060 "+result[RESULT_MSG];

   this_player()->msg_local(buf+"~CDEF");
}
