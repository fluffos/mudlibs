/* Do not remove the headers from this file! see /USAGE for more info. */

//: PLAYERCOMMAND USAGE roundhouse roundhose <someone>
//
// This Karate technique consists of throwing a Mawashi geri (Roundhouse) to the
// midsection of the opponent as a distraction then following with a Choku-zuki
//(Jab) with the lead hand to the chin.
//
// .. TAGS: RST

inherit SPECIAL;

private
void setup()
{
   set_reflex_cost(5);
   set_name("roundhouse");
   set_target_required(1);
   set_starts_fight(1);
   set_other_skill("combat/special/trip", 2);
}

int special_check(object attacker, object target)
{
   if (attacker->query_agility_stat() < 20)
   {
      write("You need a Dexterity score of at least 20.\n");
      return 0;
   }
   return 1;
}

void jab(object attacker, object target)
{
   int rank = skill_rank(attacker);
   attacker->targetted_action("$N $vfollow up $p roundhouse kick with a jab to the $p1 chin.", target);
   target->hurt_us((rank * 10) + random(5), "head");
   target->stun("head", 5 + random(15));
}

void special(object attacker, object target)
{
   int check = skill_check(attacker, target);
   int rank = skill_rank(attacker);
   string limb;

   limb = target->query_random_limb();

   if (!check)
   {
      attacker->targetted_action("$N $vattempt a roundhouse kick to $p1 $o, but it's just a strafe.", target, limb);
      target->hurt_us(5 + random(5), limb);
      return;
   }

   if (limb)
   {
      if (limb != "head")
      {
         attacker->targetted_action("$N roundhouse $vkick $p1 $o, failing to follow up.", target, limb);
         target->hurt_us((rank * 5) + random(5), limb);
      }
      else
      {
         attacker->targetted_action("$N roundhouse $vkick $p1 $o. Whap!", target, limb);
         target->hurt_us((rank * 7) + random(5), limb);
         call_out("jab", 2, attacker, target);
      }
   }
}
