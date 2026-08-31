/* Do not remove the headers from this file! see /USAGE for more info. */

//: PLAYERCOMMAND
// USAGE sweep
//       sweep <someone>
//
// Sweep someones feet or limbs they use to move around with.
//
//  .. TAGS: RST

/*
** Sweep version 1.1
** * Added more damage and made the messages better.
*/

inherit SPECIAL;

private
void setup()
{
   set_reflex_cost(2);
   set_name("sweep");
   set_target_required(1);
   set_starts_fight(1);
}

// https://en.wikipedia.org/wiki/Foot_sweep

void special(object attacker, object target)
{
   int check = skill_check(attacker, target);
   int rank = skill_rank(attacker);
   string limb;

   if (!check)
   {
      attacker->targetted_action("$N $vattempt to do a foot sweep, but $t $v1are too quick.", target);
      return;
   }

   switch (rank)
   {
   case 0:
      limb = choice(target->query_mobile_limbs());
      if (limb)
      {
         attacker->targetted_action("$N $vperform a simple single-leg sweep on $p1 $o.", target, limb);
         target->stun(limb, 1 + random(5));
         target->hurt_us(5 + random(2), limb);
      }
      break;
   case 1:
      limb = choice(target->query_mobile_limbs());
      if (limb)
      {
         attacker->targetted_action("$N $vperform a drop sweep on $p1 $o.", target, limb);
         target->stun(limb, 5 + random(5));
         target->hurt_us(10 + random(5), limb);
      }
      break;
   default:
      limb = choice(target->query_mobile_limbs());
      if (limb)
      {
         attacker->targetted_action("$N $vperform a trap sweep on $p1 $o.", target, limb);
         target->stun(limb, 5 + random(5));
         target->hurt_us(15 + random(5), limb);
      }
      limb = choice(target->query_mobile_limbs() - ({limb}));
      if (limb)
      {
         target->stun(limb, 5 + random(5));
         target->hurt_us(10 + random(5), limb);
      }
      break;
   }
}
