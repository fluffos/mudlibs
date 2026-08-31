/* Do not remove the headers from this file! see /USAGE for more info. */

#include <spells.h>

inherit COMBAT_SPELL;
inherit M_DICE;

// Inspired by D&D SRD, but modified for an interactive MUD.

void setup()
{
   set_level(2);
   set_name("acid arrow");
   set_category("evocation");
   set_targets(TARGET_LIVING);
   set_damage_type("acid");
   set_cast_time(1);
   set_description("A shimmering green arrow streaks toward a single living "
                   "target within range and bursts in a spray of acid. "
                   "On a hit, the target takes acid damage immediately "
                   "and more acid damage on-going.");
}

varargs int calculate_damage(int success, object target)
{
   return x_dice(success ? 2 : 4, 4) + spell_skill_rank(target);
}

void ongoing_damage(object attacker, object target, string limb)
{
   int damage = calculate_damage(1) / 2;
   if (!attacker)
      return;
   target->targetted_action("$P1 acid arrow continues to burn $n on the $o.", attacker, limb);
   do_spell_damage(attacker, target, damage, limb, 1);
}

void cast_spell(object ob, object reagent, int success)
{
   if (!ob)
   {
      write("Your target has disappeared??");
   }
   else
   {
      string limb = success ? choice(({"head", "torso"})) : ob->query_random_limb();
      // Two different messages based on success.
      this_body()->targetted_action("$N $vcast a " + (success ? "radiant" : "shimmering") + " green arrow at $t1.", ob);

      // On a hit, the target takes acid damage immediately and more acid damage on-going.
      // On success, either the head or torso is targeted.
      do_spell_damage(this_body(), ob, ( : calculate_damage, success, ob:), limb);

      // The acid arrow is a transient object that will handle the ongoing damage.
      // Move it to the target.
      if (!ob->test_skill("combat/defense/dodge"), SKILL_D->pts_for_rank(query_level()))
         transient("acid arrow", 1, 3, 0, limb)->move(ob);
      else
         ob->simple_action("$N $vdodge the acid arrow.");
   }
}