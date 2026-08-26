#include <hooks.h>

inherit VERB_OB;

void increase_speed();
void concentration();

void do_fspeed()
{
   object this_body = this_body();

   this_body->simple_action("$N $vconcentrate on increasing $p speed through the Force...\n");

   this_body->add_skill_delay(8);

   concentration();
}

mixed can_fspeed()
{
   object this_body = this_body();

   if (this_body->query_guild_level("jedi"))
   {
      if (!this_body->has_learned_skill("force speed"))
      {
         return "You have not learned how to increase your speed through the Force.\n";
      }
      else if (this_body->has_skill_delay())
      {
         return "You are too busy to concentrate on increasing your speed through the Force.\n";
      }
      else if (this_body->has_special_skill_delay("force speed"))
      {
         return "You need to wait " + convert_time(this_body->has_special_skill_delay("force speed")) + " before you can increase your speed through the Force again.\n";
      }
   }
   else
   {
      return "Only Jedi know how to use the Force to increase their speed.\n";
   }

   return 1;
}

void increase_speed()
{
   object this_body = this_body();
   int force = this_body->query_for();
   int level = this_body->query_guild_level("jedi");
   int rank = this_body->query_skill("force speed") / 100;
   int spec = this_body->query_guild_specialization_rank("jedi", "control");
   int rank_spec = (rank + spec) < 0 ? 0 : (rank + spec);
   int amount = (level * force * (rank_spec * 3)) / 19000;
   int delay = 420 - ((level + (rank_spec * 2)) * 4);
   int duration = ((rank_spec * 2) + level) * 4;

   if (amount < 1) { amount = 1; }

   load_object("/d/buffs/force_speed");
   this_body->add_buff(new("/d/buffs/force_speed", amount, duration));

   this_body->add_special_skill_delay("force speed", delay);
}

void concentration()
{
   object this_body = this_body();
   int alignment = this_body->query_jedi_alignment();

   if (!this_body) { return; }

   if (this_body->test_skill("force speed", (alignment * (alignment < 0 ? -5 : 5)) + this_body->call_hooks("force_focus", HOOK_SUM)))
   {
      increase_speed();
   }
   else
   {
      this_body->simple_action("$N $vlose focus.\n");
   }
}

void create()
{
   add_rules( ({ "" }) );
}