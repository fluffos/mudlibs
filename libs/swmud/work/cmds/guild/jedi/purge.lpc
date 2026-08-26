#include <hooks.h>

inherit VERB_OB;

void perform_purge(object body);
void meditation_time(object body);

void do_purge_liv(object living)
{
   object this_body = this_body();

   if (!living->has_effect("poison"))
   {
      if (living == this_body)
      {
         write("You are already free of toxins.\n");
         return;
      }
      else
      {
         write(capitalize(living->short()) + " is already free of toxins.\n");
         return;
      }
   }
   else if (living->query_guild_level("assassin") && (living->query_jedi_alignment() < 0))
   {
      write(living->short() + " is too dedicated to the Dark side of the Force to be purged of toxins.\n");
      return;
   }

   if (living == this_body)
   {
      this_body->simple_action("$N $vconcentrate for a moment on purging toxins with the Force...\n");
   }
   else
   {
      this_body->targetted_action("$N $vconcentrate momentarily on purging $p1 toxins with the Force...\n", living);
   }

   this_body->adjust_jedi_alignment(this_body->has_buff("/d/buffs/force_focus") ? 4 : 2);

   call_out("meditation_time", 4, living);

   this_body->add_skill_delay(8);
}

void do_purge()
{
   do_purge_liv(this_body());
}

mixed can_purge_liv()
{
   object this_body = this_body();

   if (this_body->query_guild_level("jedi"))
   {
      if (!this_body->has_learned_skill("purge toxins"))
      {
         return "You have not learned how to purge toxins with the Force.\n";
      }
      else if (this_body->query_guild_level("assassin"))
      {
         return "You are too dedicated to the Dark side of the Force to use it for purging toxins.\n";
      }
      else if (this_body->has_buff("/d/buffs/anger"))
      {
         return "You are too angry to use the Force for purging toxins.\n";
      }
      else if (this_body->get_target())
      {
         return "You are unable to concentrate on purging toxins while in combat.\n";
      }
      else if (this_body->has_skill_delay())
      {
         return "You are too busy to concentrate on purging toxins.\n";
      }
   }
   else
   {
      return "Only Jedi know how to use the Force for purging toxins.\n";
   }

   return 1;
}

mixed can_purge()
{
   object this_body = this_body();

   if (this_body->query_guild_level("jedi"))
   {
      if (!this_body->has_learned_skill("purge toxins"))
      {
         return "You have not learned how to purge toxins with the Force.\n";
      }
      else if (this_body->query_guild_level("assassin"))
      {
         return "You are too dedicated to the Dark side of the Force to use it for purging toxins.\n";
      }
      else if (this_body->has_buff("/d/buffs/anger"))
      {
         return "You are too angry to use the Force for purging toxins.\n";
      }
      else if (this_body->get_target())
      {
         return "You are unable to concentrate on purging toxins while in combat.\n";
      }
      else if (this_body->has_skill_delay())
      {
         return "You are too busy to concentrate on purging toxins.\n";
      }
   }
   else
   {
      return "Only Jedi know how to use the Force for purging toxins.\n";
   }

   return 1;
}

void perform_purge(object body)
{
   object toxin = body->has_effect("poison");

   if (toxin)
   {
      object this_body = this_body();
      int force = this_body->query_for();
      int level = this_body->query_guild_level("jedi");
      int rank = this_body->query_skill("purge toxins") / 100;
      int spec = this_body->query_guild_specialization_rank("jedi", "healing");
      int rank_spec = (rank + spec) < 0 ? 0 : (rank + spec);
      int amount = (rank * 2) + (30 * rank_spec * level * force / 100000);

      if (amount < 1) { amount = 1; }

      tell(body, (this_body == body ? "You purge" : capitalize(this_body->short()) + " purges") + " some of the toxins in your body.\n");
      body->other_action("$N $vare surrounded by a faint white glow.\n");
      toxin->add_poison_strength(amount * -1);

      if (body != this_body)
      {
         body->adjust_jedi_alignment(2);
      }
   }
   else
   {
      write(capitalize(body->short()) + " doesn't have any toxins in " + body->query_possessive() + " body to purge.\n");
   }
}

void meditation_time(object body)
{
   object this_body = this_body();
   int alignment;

   if (!this_body) { return; }
   else if (this_body->get_target())
   {
      write("You lose concentration on purging toxins as you defend yourself!\n");

      return;
   }
   else if (!body || (environment(this_body) != environment(body)))
   {
      write(body->short() + " left and your concentration was broken.\n");

      return;
   }

   alignment = this_body->query_jedi_alignment();

   if (this_body->test_skill("purge toxins", (alignment * (alignment < 0 ? 25 : 10)) + this_body->call_hooks("force_focus", HOOK_SUM)))
   {
      perform_purge(body);
   }
   else
   {
      this_body->simple_action("$N $vlose focus.\n");
   }
}

void create()
{
   add_rules( ({ "", "LIV" }) );
}