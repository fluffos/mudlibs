#include <hooks.h>

inherit VERB_OB;

void perform_valor();
void meditation_time();

void do_valor()
{
   object this_body = this_body();

   this_body->simple_action("$N $vconcentrate on strengthening $p body through the Force...\n");

   this_body->adjust_jedi_alignment(this_body->has_buff("/d/buffs/force_focus") ? 4 : 2);

   this_body->add_skill_delay(8);

   call_out("meditation_time", 4);
}

mixed can_valor()
{
   object this_body = this_body();

   if (this_body->query_guild_level("jedi"))
   {
      if (!this_body->has_learned_skill("force valor"))
      {
         return "You have not learned how to strengthen your body through the Force.\n";
      }
      else if (this_body->query_guild_level("assassin"))
      {
         return "You are too dedicated to the Dark side of the Force to use it for strengthening your body.\n";
      }
      else if (this_body->has_buff("/d/buffs/anger"))
      {
         return "You are too angry to use the Force for strengthening your body.\n";
      }
      else if (this_body->get_target())
      {
         return "You are unable to concentrate on strengthening your body through the Force while in combat.\n";
      }
      else if (this_body->has_skill_delay())
      {
         return "You are too busy to concentrate on strengthening your body through the Force.\n";
      }
      else if (this_body->has_special_skill_delay("force valor"))
      {
         return "You need to wait " + convert_time(this_body->has_special_skill_delay("force valor")) + " before you can strengthen your body through the Force again.\n";
      }
   }
   else
   {
      return "Only Jedi know how to use the Force to strengthen their body.\n";
   }

   return 1;
}

void perform_valor()
{
   object this_body = this_body();
   int force = this_body->query_for();
   int level = this_body->query_guild_level("jedi");
   int rank = this_body->query_skill("force valor") / 100;
   int spec = this_body->query_guild_specialization_rank("jedi", "control");
   int rank_spec = (rank + spec) < 0 ? 0 : (rank + spec);
   int amount = (level * force * (rank_spec * 3)) / 5000;
   int delay = 420 - ((level + (rank_spec * 2)) * 4);
   int duration = ((rank_spec * 2) + level) * 4;

   if (amount < 1) { amount = 1; }

   load_object("/d/buffs/force_valor");
   this_body->add_buff(new("/d/buffs/force_valor", amount, duration));

   this_body->add_special_skill_delay("force valor", delay);
}

void meditation_time()
{
   object this_body = this_body();
   int alignment = this_body->query_jedi_alignment();

   if (!this_body) { return; }

   if (this_body->test_skill("force valor", (alignment * (alignment < 0 ? 25 : 5)) + this_body->call_hooks("force_focus", HOOK_SUM)))
   {
      perform_valor();
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