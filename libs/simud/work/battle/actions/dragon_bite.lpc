#include <battle.h>

BATTLE_ACTION( 1000, ({ "dragon" }) )

string query_action_name() {
   return "Dragon Bite";
}

void on_action( object victim ) {
   mixed result;
   mapping wc = copy(this_player()->query_wc());
   int damage;
   string buf = "";
   string bp;

   this_player()->add_readiness(-500);

   if( !BATTLE_DAEMON->check_legal_melee(victim, "dragon_bite") )
      return;

   this_player()->add_endurance(-1);

   wc["piercing"] += this_player()->query_str_wc();

   // bite hits twice, first hit is big piercing type
   result = BATTLE_DAEMON->execute_melee(this_object(), wc, victim, 20,
            ATT_NO_PARRY | ATT_NO_BLOCK );
   damage = result[RESULT_MOD];

   if (sizeof(result) > 3)
     bp = victim->query_bp_name(result[RESULT_BP]);

   switch (result[RESULT_TYPE]) {
     case "miss":
       buf = "~[130~Name ~verbmiss ~targ with a bite!";
       break;

     default:
      // sound
      AUDIO_DAEMON->sfx_room(environment(victim),"crunch.wav");

      if( damage == 100 )
        buf = "~[090~Name ~verbbite ~targ viciously, killing ~objt.";
      else if (damage >= 40)
        buf = "~[090~Name ~verbbite deep into ~npot "+bp+".";
      else if (damage >= 5) {
        if (result[RESULT_ARMOUR])
           buf = "~[090~Name ~verbbite ~targ hard in the "+bp+", but ~post "+result[RESULT_ARMOUR]->query_name()+" absorbs some of the blow.";
        else
           buf = "~[090~Name ~verbbite ~targ hard in the "+bp+".";
      } else {
        if (result[RESULT_ARMOUR])
           buf = "~[090~Name ~verbbite ~npot "+bp+", but ~post "+result[RESULT_ARMOUR]->query_name()+" absorbs most of the blow.";
        else
           buf = "~[090~Name ~verbbite ~npot "+bp+", but the blow seems to have little effect.";
      }
       break;
   }

   if (result[RESULT_MSG])
     buf += "~[060 "+result[RESULT_MSG];

   // second part of attack, flame damage from mouth ;)
   wc = ([ "fire": 5 ]);

   result = BATTLE_DAEMON->execute_melee(this_object(), wc, victim, 20,
            ATT_NO_PARRY | ATT_NO_COUNTER );
   damage = result[RESULT_MOD];
   switch (result[RESULT_TYPE]) {
    case "block":
      buf += "~[030Flames swirl around ~targ, ";
      if ( damage >= 50 )
        buf += "scorching ~prot badly.";
      else if ( damage )
        buf += "searing ~post flesh.";
      else
       buf += "but ~prot ~vertis unharmed.";
      break;

     case "hit":
      if ( damage >= 100 )
        buf += "~[110~Subt ~vertburst into flames and ~vertis slain!";
      else if ( damage >= 40 )
       buf += "~[110~Subt ~vertis engulfed in flames!";
      else
       buf += "~[110~Npos bite sears ~npot flesh!";
      break;
   }

   if( damage )
      AUDIO_DAEMON->sfx_room(environment(victim),"meatsizzle.wav");

   this_player()->msg_local(buf+"~CDEF");
}
