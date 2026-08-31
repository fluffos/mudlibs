/* Do not remove the headers from this file! see /USAGE for more info. */

// combat_spell.c - Base object for damage-causing magic spells. Whenever
//                  your spells cause the damage, call do_spell_damage().
//                  Combat will automatically start between the caster and
//                  the target.
// Iizuka, 4-28-98: Created.

inherit SPELL;
inherit M_DAMAGE_SOURCE;

//: FUNCTION do_spell_damage
// Inflicts damage on the target and initiates combat between the attacker and the target.
// Parameters:
// - attacker: The object performing the attack.
// - target: The target object to receive the damage.
// - damage: The amount of damage to inflict, or a function to calculate the damage.
// - limb: (optional) The specific limb to apply the damage to. If not specified, a random limb is chosen.
// - no_dodge: (optional) If set to 1, the target cannot dodge the attack.
varargs void do_spell_damage(object attacker, object target, mixed damage, string limb, int no_dodge)
{
   int s_level = query_level();
   int opposing_dodge = SKILL_D->pts_for_rank(s_level);

   if (!attacker || !target)
      return;

   if (functionp(damage))
   {
      damage = evaluate(damage);
   }
   if (!no_dodge && target->test_skill("combat/defense/dodge"), SKILL_D->pts_for_rank(query_level()))
   {
      damage = damage / 2;
   }
   attacker->add_event(target, this_object(), target->query_random_limb(), damage);
   if (attacker != target)
      attacker->start_fight(target);
}

//: FUNCTION is_combat_spell
// Indicates that this is a combat spell.
int is_combat_spell()
{
   return 1;
}

//: FUNCTION short
// Returns a short description of the spell.
string short()
{
   return add_article(query_name());
}
void create()
{
   set_damage_type("force");

   // Generic spell messages that uses the damage type for description.
   set_combat_messages("combat-generic-spell");
#ifdef USE_SKILLS
   set_magic_skill_used("magic/technique/casting");
#endif
   // Call create down here so the defaults above can be overwritten.
   ::create();
}
