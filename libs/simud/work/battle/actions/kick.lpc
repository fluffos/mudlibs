// This action has been updated by Allaryin.
//
// Further update on Oct 14, 2003 by Allaryin. Kick now considers boots the
// attacker may be wearing. Only primary feet are checked (ie, 2nd and 3rd are
// not), but this shouldn't be an issue since the only people who should be
// using this particular kick action should be bipedal.
//
// Future update might include adjusting messaging for boots with special
// properties (spikes, flame, etc...).
#include <battle.h>

BATTLE_ACTION( 1000, "brawl" )

string query_action_name() {
   return "Kick";
}

void on_action( object victim ) {
   mixed result;
   mapping wc;
   int damage;
   string buf, bp;
   object boots;

   this_player()->add_readiness(-500);
   if( !BATTLE_DAEMON->check_legal_melee(victim, "kick") )
      return;

   this_player()->add_endurance(-1);

   wc = copy(this_player()->query_wc());
   if( !mappingp(wc) || !member(wc,"blunt") )
     wc = (["blunt":3]);
   wc["blunt"] += this_player()->query_str_wc();

   // use boots if they got 'em, and anything else they may be wearing on
   // their feet. Effects stack. So if I am wearing iron boots over socks of
   // death... they will both affect the damage ;)
   foreach (boots : all_inventory(this_player())) {
      if (!boots->query_worn() ||
          !(boots->query_body_parts() & BP_FEET))
        continue;
      if (mappingp(boots->query_wc()))
        wc += boots->query_wc();
        // This causes severe balance problems. Boots should
        // specify a WC.
//      else
//        wc["blunt"] += boots->query_base_ac() / 2;
      // kicking in boots is more tiring than kicking w/o
      this_player()->add_readiness(boots->query_weight()/-10);
   }

   result = BATTLE_DAEMON->execute_melee(this_player(), wc, victim, 2, 0);
   damage = result[RESULT_MOD];
   if (sizeof(result) > 3)
     bp = victim->query_bp_name(result[RESULT_BP]);

   switch (result[RESULT_TYPE]) {
   case "miss":
      buf = "~[130~Name almost ~verbstrain ~poss leg as ~poss kick misses ~targ!";
      break;

   case "hit":
   case "counter":
   default:
	   // sound
	   AUDIO_DAEMON->sfx_room(environment(victim),"smash.wav");
	
      if( damage >= 100 )
         buf = "~[090~Name ~verbland a solid kick squarely on ~npot "+bp+". ~Subt ~vertgrunt briefly in pain before falling to the ground, unconscious.";
      else if (damage >= 40)
         buf = "~[090~Name ~verbkick ~targ solidly in the "+bp+"!";
      else if (damage >= 5) {
         if (result[RESULT_ARMOUR])
            buf = "~[090~Name ~verbkick ~targ in the "+bp+" but ~post "+result[RESULT_ARMOUR]->query_name()+" cushions the blow.";
         else
            buf = "~[090~Name ~verbkick ~targ in ~post "+bp+".";
      }
      else {
         if (result[RESULT_ARMOUR])
            buf = "~[090~Name ~verbkick ~targ, but ~post "+result[RESULT_ARMOUR]->query_name()+" absorbs the blow.";
         else
            buf = "~[090~Name ~verbtry to kick ~targ, but ~verbmanage only a glancing hit.";
      }
      break;
   }

   if (result[RESULT_TYPE] != "hit")
     buf += "~[060 "+result[RESULT_MSG];

   this_player()->msg_local(buf+"~CDEF");
}
