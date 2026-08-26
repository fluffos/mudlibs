#include <hooks.h>

inherit CMD; 
inherit M_EXIT;

int get_reduction();
int get_duration();
void concentration();

void main(string arg)
{
   object this_body = this_body();

   if (this_body->query_guild_level("jedi"))
   {
      if (this_body->query_guild_level("assassin"))
      {
         write("You are too dedicated to the Dark side of the Force to use it for defense.\n");
      }
      else if (this_body->has_buff("/d/buffs/anger"))
      {
         out("You are too angry to use the Force for defense.\n");
      }
      else if (!this_body->has_learned_skill("force reflect"))
      {
         out("You have not learned how to create a Force reflection shield.\n");
      }
      else if (this_body->has_blocked_skill("force reflect"))
      {
         out("Your ability to use this command has been disabled.\n");
      }
      else if (this_body->has_skill_delay())
      {
         out("You are too busy to concentrate on manipulating the Force.\n");
      }
      else if (this_body->has_special_skill_delay("force reflect"))
      {
         write("You need to wait " + convert_time(this_body->has_special_skill_delay("force reflect")) + " before you can create another Force reflection shield.\n");
      }
      else
      {
         this_body->adjust_jedi_alignment(this_body->has_buff("/d/buffs/force_focus") ? 4 : 2);
         this_body->add_skill_delay(12);

         concentration();
      }
   }
   else
   {
      out("Only Jedi know how to manipulate the Force.\n");
   }
}

void concentration(object room)
{
   object this_body = this_body();
   int alignment = this_body->query_jedi_alignment();

   if (this_body->test_skill("force reflect", (alignment * (alignment < 0 ? 20 : this_body->query_skill("force shield") / 2)) + this_body->call_hooks("force_focus", HOOK_SUM)))
   {
      int level = this_body->query_guild_level("jedi");
      int force = this_body->query_for();
      int rank = this_body->query_skill("force reflect") / 100;
      int spec = this_body->query_guild_specialization_rank("jedi", "defense");
      int rank_spec = (rank + spec) < 0 ? 0 : (rank + spec);
      int reduction = 5 + (level * force * rank * 9 / 5000);
      int duration = 8 + (level * force * rank_spec * 16 / 50000) * 2;
      int delay = 600 - ((level + (rank_spec * 2)) * 2);

      load_object("/d/buffs/force_reflect");
      this_body->add_buff(new("/d/buffs/force_reflect", reduction, duration));

      this_body->add_special_skill_delay("force reflect", delay);
   }
   else
   {
      this_body->simple_action("$N $vlose focus.\n");
   }
}