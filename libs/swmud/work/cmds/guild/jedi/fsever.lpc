#include <hooks.h>
#include <playerflags.h>

inherit VERB_OB;

void sever_target(object living);
void concentration(object living);

mixed can_fsever_liv()
{
   object this_body = this_body();

   if (this_body->query_guild_level("jedi"))
   {
      if (this_body->is_body() && !this_body->has_learned_skill("force sever"))
      {
         return "You have not learned how to sever someone's connection to the Force.\n";
      }
      else if (this_body->has_skill_delay())
      {
         return "You are too busy to concentrate on severing someone's connection to the Force.\n";
      }
      else if (this_body->has_special_skill_delay("force sever"))
      {
         return "You need to wait " + convert_time(this_body->has_special_skill_delay("force sever")) + " before you can sever someone's connection to the Force again.\n";
      }
   }
   else
   {
      return "Only Jedi know how to wipe someone's memory with the Force.\n";
   }

   return 1;
}

void do_fsever_liv(object living)
{
   object this_body = this_body();

   if (living->is_adversary())
   {
      if (living != this_body)
      {
         if (living->has_buff("/d/buffs/sever_force") || !living->test_flag(F_FORCE_SENSITIVE))
         {
            write("You sense that " + title_capitalize(living->short()) + " is already unaware of the Force which surrounds " + living->query_objective() + ".\n");
         }
         else
         {
            concentration(living);
         }
      }
      else
      {
         write("You find yourself unable to use the Force to sever your own connection to the Force.\n");
      }

      return;
   }

   write("You can forget about severing " + living->query_possessive() + " connection to the Force.\n");
}

mixed can_fsever()
{
   object this_body = this_body();

   if (!this_body->query_guild_level("jedi"))
   {
      return "Only Jedi know how to sever someone's connection to the Force.\n";
   }

   return 1;
}

void do_fsever()
{
   object target = this_body()->get_target();

   if (!this_body()->is_body())
   {
      concentration(target);

      return;
   }

   if (target) { do_fsever_liv(target); }
   else { write("Sever who's connection to the Force?\n"); }
}

void sever_target(object living)
{
   object this_body = this_body();
   int force = this_body->query_for();
   int level = this_body->query_guild_level("jedi");
   int target_force = living->query_for();
   int target_level = living->query_guild_level("jedi");
   int rank = this_body->query_skill("force sever") / 100;
   int spec = this_body->query_guild_specialization_rank("jedi", "control");
   int rank_spec = (rank + spec) < 0 ? 0 : (rank + spec);
   int delay = 600 - (rank_spec * 6) - (((level / 5) + (force / 5)) * 4);
   int duration = 60 + (rank_spec * 24) + ((level + (force / 2)) * 2);
   int resistance = ((target_force / 5) + target_level) * 2;

   if (resistance > 0)
   {
      duration -= resistance;

      if (duration < 16) { duration = 16; }
   }

   load_object("/d/buffs/sever_force");
   living->add_buff(new("/d/buffs/sever_force", duration));

//   tell(this_body, "Severed them from the Force for " + convert_time(duration) + ".\n");
   this_body->add_special_skill_delay("force sever", delay);
}

void concentration(object living)
{
   object this_body = this_body();
   int alignment = this_body->query_jedi_alignment();

   this_body->add_skill_delay(12);

   if (this_body->test_skill("force sever", (this_body->query_guild_level("jedi") * 10) + this_body->call_hooks("force_focus", HOOK_SUM)))
   {
      this_body->targetted_action("$N $vconcentrate on severing $t from the Force.\n", living);

      sever_target(living);

      if (!living->is_body() && (random(living->query_per() + 1) > random(100)))
      {
         living->attacked_by(this_body, 1);
      }
   }
   else
   {
      this_body->targetted_action("$N $vattempt to sever $t from the Force and $vfail.\n", living);
   }
}

void create()
{
   add_rules( ({ "", "LIV" }) );
}