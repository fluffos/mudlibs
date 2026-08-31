/* Do not remove the headers from this file! see /USAGE for more info. */

//: PLAYERCOMMAND
// USAGE trip
//       trip <someone>
//
//  Kuzushi Waza is a Karate technique not very known in MMA and other martial
//  arts, it’s primarily exclusive to Karate. Kuzushi Waza consists of throwing a
//  cross as if you want to reach the opponent jaw but instead you go with your
//  hand to the side of his neck and then you step forward with your leg putting
//  it right behind the opponent, this way, your opponent becomes trapped between
//  your arm in front and your leg behind. After that all you have to do is drive
//  through your opponent and he will automatically lose his balance and you will
//  take him down effortlessly.
//
//  .. TAGS: RST

inherit SPECIAL;

private
void setup()
{
   set_reflex_cost(3);
   set_name("trip");
   set_target_required(1);
   set_starts_fight(1);
   set_other_skill("combat/special/sweep", 1);
}

int special_check(object attacker, object target)
{
   if (attacker->query_dex() < 10)
   {
      write("You need a Dexterity score of at least 10.\n");
      return 0;
   }
   return 1;
}

void special(object attacker, object target)
{
   int check = skill_check(attacker, target);
   int rank = skill_rank(attacker);
   string limb;

   if (!check)
   {
      if (target->is_limb("head"))
      {
         attacker->targetted_action("$N $vattempt a backward trip on $t, but only $vmanage a punch to the face.",
                                    target, limb);
         target->hurt_us(1 + random(5), "head");
      }
      else
         attacker->targetted_action(
             "$N $vattempt to perform a backward trip, but $t $v1prevent $n from getting into the right position.",
             target);
      return;
   }

   switch (rank)
   {
   case 0:
      limb = choice(target->query_mobile_limbs());
      if (limb)
      {
         if (random(2))
         {
            attacker->targetted_action("$N $vattempt a backward trip on $t, but only $vmanage a kick to $p1 $o.",
                                       target, limb);
            target->hurt_us(15 + random(5), limb);
            target->stun(limb, 10 + random(5));
         }
         else
         {
            attacker->targetted_action("$N $vperform a backward trip on $t, sending $t on $p1 butt.", target, limb);
            target->stun(limb, 5 + random(5));
            target->hurt_us(5 + random(5), limb);
            target->lie_down();
         }
      }
      break;
   default:
      limb = choice(target->query_mobile_limbs());
      if (limb)
      {
         attacker->targetted_action("$N $vperform a backward trip on $t, sending $t HARD on $p1 butt.", target, limb);
         target->stun(limb, 5 + random(5));
         target->hurt_us(15 + random(5), limb);
         target->lie_down();
      }
      break;
   }
}
