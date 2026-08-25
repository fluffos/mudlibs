/* Do not remove the headers from this file! see /USAGE for more info. */

// This is a simple skills module, demonstrating one way to integrate the
// Lima skills system into the combat system
// It is designed to return a number in the range 0 to 100 for chance to hit,
// based on skills in the range 0 to MAX_SKILL_VALUE

#include <classes.h>
#include <combat_modules.h>
#include <log.h>
#include <config/skills.h>

#define DAMAGE_STAT_IMPACT 5
#define DEFEND_STAT_IMPACT 5
#define DISARM_STAT_IMPACT 2
#define TO_HIT_STAT_IMPACT 5

inherit CLASS_SKILL;

private
nosave int combat_debug = 0;

int query_level();
int query_weapon_class();
int aggregate_skill(string skill);
int query_to_hit_bonus(object target);
int query_disarm_bonus(object target);
int query_damage_bonus(object target);
int query_anti_disarm(object target);
int cached_skill_rank(string s);

int level_skill_cap()
{
   return query_level() / 5 || 1;
}

void debug_combat(int cd)
{
   combat_debug = cd;
}

int should_cap_skill(string skillname)
{
   return cached_skill_rank(skillname) >= level_skill_cap();
}

int chance_to_hit(object weapon, object target)
{
   string attack_skill = weapon ? weapon->query_skill_used() : "combat/melee/unarmed";
   string defend_skill = target->query_defend_skill_used();
   int skill_contrib = strsrch(attack_skill, "combat/guns") != -1 ? (this_object()->query_dex() / TO_HIT_STAT_IMPACT)
                                                                  : (this_object()->query_str() / TO_HIT_STAT_IMPACT);
   int attack_value;
   int defend_value;
   int attack_mod = 1;
   int defend_mod = 1;
   int res;
   int skill_test = 0;
   int train_limit;

   // Skill restrictions
   if (weapon->query_restricted())
   {
      attack_skill = weapon->query_restricted_skill();
      attack_mod = 10;
      defend_mod = 10;
   }

   attack_value = to_int(aggregate_skill(attack_skill) / attack_mod);
   defend_value = target->aggregate_skill(defend_skill) * defend_mod || 1;

   if (combat_debug)
      TBUG("This: " + this_object() + " Weapon: " + weapon + " target: " + target + "\nAttack skill: " + attack_skill +
           " (" + attack_value + ") Defend skill: " + defend_skill + " (" + defend_value + ")");
   // TBUG("Train restriction: Limit: " + weapon->query_train_limit() + " rank: " + cached_skill_rank(attack_skill));
   if (combat_debug)
      TBUG("@( ((0.0+" + attack_value + ") / " + defend_value + ") * 50)");
   train_limit = cached_skill_rank(attack_skill) >= weapon->query_train_limit() || should_cap_skill(attack_skill);
   skill_test = this_object()->test_skill(attack_skill, defend_value, train_limit); // Don't learn things.

   res = ((0.0 + attack_value) / defend_value) * 50 + skill_contrib;
   if (combat_debug)
      TBUG("Res before skill test: " + res + " skill_test:" + skill_test);

   if (skill_test)
   {
      // Calculate the value for successful skill_test
      if (weapon)
         res += weapon->query_to_hit_bonus(target) + random(weapon->query_weapon_class());
      else
         res += query_to_hit_bonus(target) + random(query_weapon_class());
   }
   if (combat_debug)
      TBUG("Res after skill test: " + res + " (clamped between 0 and 100)");

   res = CLAMP(to_int(res), 0, 100);
   return res;
}

int defend_chance(object weapon, object target)
{
   string attack_skill = weapon ? weapon->query_skill_used() : "combat/melee/unarmed";
   string defend_skill = target->query_defend_skill_used();
   int attack_value;
   int defend_value;
   int attack_mod = 1;
   int defend_mod = 1;
   int res;
   int skill_impact = 1;
   int train_limit;

   if (target->should_cap_skill(defend_skill))
      train_limit = 1;

   // Skill restrictions
   if (weapon->query_restricted())
   {
      attack_skill = weapon->query_restricted_skill();
      attack_mod = 10;
      defend_mod = 10;
   }

   attack_value = to_int(aggregate_skill(attack_skill) / attack_mod) || 1;
   defend_value = target->aggregate_skill(defend_skill) * defend_mod || 1;

   if (target->test_skill(defend_skill, attack_value, train_limit))
   {
      skill_impact = 2;
      target->dodge_message();
   }

   res = ((0.0 + defend_value) / attack_value) * MAX_SKILL_VALUE;
   res = (res * 50 / (MAX_SKILL_VALUE)) + (((target->query_dex() * skill_impact) / DEFEND_STAT_IMPACT));
   if (combat_debug)
      TBUG("defend," + defend_skill + "," + defend_value + ",attack," + attack_skill + "," + attack_value +
           " skill impact: " + skill_impact + " res: " + res + "\n");
   return res;
}

int disarm_chance(object target)
{
   int defend_mod = 1;
   int res;
   object weapon = this_object()->query_weapon();
   int chance_to_hit = chance_to_hit(weapon, target);
   int defend_disarm_value = target->aggregate_skill("combat/defense/disarm") * defend_mod;
   // Calculate anti_disarm chances from the target + her weapon.
   int disarm_prevention = (target ? target->query_anti_disarm() : 0) +
                           (target->query_weapon() ? target->query_weapon()->query_anti_disarm() : 0) +
                           ((target->query_int() / DISARM_STAT_IMPACT));
   int train_limit;

   if (target->should_cap_skill("combat/defense/disarm"))
      train_limit = 1;

   // TBUG("disarm," + "combat/disarm" + "," + chance_to_hit + "\n");
   target->test_skill("combat/defense/disarm", chance_to_hit, train_limit);

   res = chance_to_hit - ((defend_disarm_value * 50) / MAX_SKILL_VALUE);

   // TBUG("Chance_to_hit: "+chance_to_hit+" Defend_disarm: "+(defend_disarm_value/100.0)+" Res: "+res+
   //" Disarm prev:"+disarm_prevention+" To hit bonus: "+(weapon ? weapon->query_to_hit_bonus(target) :
   //query_to_hit_bonus(target))+" Disarm bonus "+query_disarm_bonus(target)); Subtract to_hit bonus and add disarm
   // bonus.
   return to_int((res - (weapon ? weapon->query_to_hit_bonus(target) : query_to_hit_bonus(target)) +
                  query_disarm_bonus(target) - disarm_prevention) /
                 10);
}

int calculate_damage(object weapon, object target)
{
   string attack_skill = weapon ? weapon->query_skill_used() : "combat/melee/unarmed";
   int skill_contrib = strsrch(attack_skill, "combat/guns") != -1 ? (this_object()->query_dex() / DAMAGE_STAT_IMPACT)
                                                                  : (this_object()->query_str() / DAMAGE_STAT_IMPACT);

   // If the weapon is set to restricted (happens when wielded in /std/adversary/wield/limbs)
   // we reduce the damage by 90% (you suck!).
   if (combat_debug)
      TBUG("Damage parts: Weapon class: " + weapon->query_weapon_class() +
           " Skill rank: " + cached_skill_rank(attack_skill) + " attack_skill: " + attack_skill +
           " dmg bonus: " + query_damage_bonus(target) + " skill_contrib: " + skill_contrib);
   return cached_skill_rank(attack_skill) + random(weapon->query_weapon_class()) + 1 + query_damage_bonus(target) +
          skill_contrib;
}
