#include <battle.h>

/*
 * whip.c - whip battle action (edited by kasey | may 22)
 *
 * Updated to match the slash template.
 *
 * Todo/Idea:  In real life even masters accidently whip
 * themselves.  Maybe add some kind of retort slash that does
 * like damage / 4 damage to the player or something.
 *
 * I like the idea. Implementing chance of retort when a fairly basic skill
 * check is failed. The more damage the attack does, the more likely you are
 * to nick yourself. - Al (Oct 14, 2003)
 */

BATTLE_ACTION( 1000, "whip" )

string query_action_name() {
   return "Whip";
}

void on_action( object victim ) {
   mixed result;
   mapping wc;
   int damage;
   object weapon, *weapons;
   string buf = "";
   string bp;

   this_player()->add_readiness(-500);

   if( !BATTLE_DAEMON->check_legal_melee(victim, "whip") )
      return;

   this_player()->add_endurance(-1);

   if (weapons = BATTLE_DAEMON->query_wielded_weapons(this_player(),
       (this_player()->query_form_object())->query_weapon_types()))
     weapon = weapons[random(sizeof(weapons))];
   else {
     msg("You are not wielding an appropriate weapon.");
     this_player()->adopt_best_form();
     return;
   }

   wc = copy(weapon->query_wc());

   if (!mappingp(wc)) {
     debug((string)weapon+" does not have a valid wc mapping.");
     return;
   }
   wc["edged"] += this_player()->query_str_wc();

   result = BATTLE_DAEMON->execute_melee(weapon, wc, victim, 2, 0);
   damage = result[RESULT_MOD];

   if (sizeof(result) > 3)
       bp = victim->query_bp_name(result[RESULT_BP]);

   switch (result[RESULT_TYPE]) {
     case "miss":
       buf = "~[130~Name ~verbmiss ~targ with a crack of ~poss whip!";
       break;

   default:
     if (damage == 100)
       buf = "~[090~Name ~verbmake a vicious ~verbwhip at ~targ, slitting " +
             "an artery in its " + bp + "!";
     else if (damage >= 50)
       buf = "~[090~Name ~verbwhip ~targ causing a deep and painful cut.";
     else if (damage >= 20)
       buf = "~[090~Name ~verbwhip ~targ slicing the skin.";
     else if (damage >= 5)
     {
       if (result[RESULT_ARMOUR])
         buf = "~[090~Name ~verbwhip ~targ aggressivly in the " + bp + ", but ~post " + result[RESULT_ARMOUR]->query_name() + " absorbs some of the whip.";
       else
         buf = "~[090~Name ~verbwhip ~targ hard in the " + bp + " with ~poss "+weapon->query_name()+".";
     } else {
       if (result[RESULT_ARMOUR])
         buf = "~[090~Name ~verbwhip ~npot "+bp+", but ~post " +
               result[RESULT_ARMOUR]->query_name()+" absorbs most of the blow.";
       else
         buf = "~[090~Name ~verbwhip ~npot "+bp+", but the blow seems to have little effect.";
     }
   }

   // chance of injuring yourself ;)
   if (!this_player()->skill_check("combat.weapon.flail",10+damage*3)) {
      object ro = this_player()->query_race_object();
      int bpnum = ro->query_random_bp();
      bp = ro->query_bp_name(bpnum);
      this_player()->take_damage(weapon->query_wc(),bpnum);
      buf += " ~[130~Name ~verbis caught in the "+bp+" by ~poss own whip as it retorts after the attack!";
   }

   if (result[RESULT_MSG])
     buf += "~[060 "+result[RESULT_MSG];

   this_player()->msg_local(buf+"~CDEF");
}
