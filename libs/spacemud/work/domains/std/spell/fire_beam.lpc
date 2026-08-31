/* Do not remove the headers from this file! see /USAGE for more info. */

#include <spells.h>

inherit COMBAT_SPELL;

void setup()
{
   set_level(1);
   set_cast_time(1);
   set_name("fire beam");
   set_category("evocation");
   set_targets(TARGET_LIVING);
   set_channeling_interval(5);
   set_description("This spell creates an ongoing beam of fire that flies at the target.");
}

int calculate_damage(int success)
{
   return random(6) * (success + 1) + 1 + spell_skill_rank();
}

void cast_spell(object target, object reagent, int success)
{
   if (success)
      this_body()->targetted_action("$N $vchannel a <221>fire beam<res> at $t1.", target);
   else
      this_body()->targetted_action("$N $vchannel a wavering fire beam at $t1.", target);

   do_spell_damage(this_body(), target, ( : calculate_damage:));
}