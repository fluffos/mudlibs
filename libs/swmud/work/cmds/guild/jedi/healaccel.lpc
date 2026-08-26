#include <hooks.h>

inherit VERB_OB;

void perform_healaccel(object body);
void meditation_time(object body);
int has_special_skill_delay(string skill);
string format_time_left(int time);

void do_healaccel_liv(object living)
{
   object this_body = this_body();

   if (this_body->query_guild_level("jedi"))
   {
      if (this_body->query_guild_level("assassin"))
      {
         write("You are too dedicated to the Dark side of the Force to use it for healing acceleration.\n");
      }
      else if (living->query_guild_level("assassin") && (living->query_jedi_alignment() < 0))
      {
         write(living->short() + " is too dedicated to the Dark side of the Force to be affected.\n");
      }
      else if (this_body->has_buff("/d/buffs/anger"))
      {
         write("You are too angry to accelerate healing with the Force.\n");
      }
      else if (!this_body->has_learned_skill("accelerate healing"))
      {
         write("You have not learned how to accelerate healing with the Force.\n");
      }
      else if (this_body->get_target())
      {
         write("You are unable to concentrate on healing acceleration while in combat.\n");
      }
      else if (this_body->has_skill_delay())
      {
         write("You are too busy to concentrate on healing acceleration.\n");
      }
      else if ((living == this_body) && this_body->has_special_skill_delay("accelerate healing"))
      {
         write("You need to wait " + convert_time(this_body->has_special_skill_delay("accelerate healing")) + " before you can accelerate your healing again.\n");
      }
      else if ((living != this_body) && living->has_special_skill_delay("accelerate healing"))
      {
         write(living->short() + " must wait " + convert_time(living->has_special_skill_delay("accelerate healing")) + " before they can undergo healing acceleration again.\n");
      }
      else if ((living != this_body) && this_body->has_special_skill_delay("accelerate healing other"))
      {
         write("You need to wait " + convert_time(this_body->has_special_skill_delay("accelerate healing other")) + " before you can accelerate another person's healing again.\n");
      }
      else
      {
         if (living == this_body)
         {
            this_body->simple_action("$N $vconcentrate on accelerating $p body's healing with the Force...\n");
         }
         else
         {
            this_body->targetted_action("$N $vconcentrate on accelerating $p1 body's healing with the Force...\n", living);
         }

         this_body->adjust_jedi_alignment(this_body->has_buff("/d/buffs/force_focus") ? 4 : 2);

         call_out("meditation_time", 6, living);

         this_body->add_skill_delay(10);
      }
   }
   else
   {
      write("Only Jedi know how to use the Force to accelerate healing.\n");
   }
}

void do_healaccel()
{
   do_healaccel_liv(this_body());
}

void perform_healaccel(object body)
{
   object this_body = this_body();
   int force = this_body->query_for();
   int level = this_body->query_guild_level("jedi");
   int rank = this_body->query_skill("heal accel") / 100;
   int spec = this_body->query_guild_specialization_rank("jedi", "healing");
   int rank_spec = (rank + spec) < 0 ? 0 : (rank + spec);
   int amount = body->query_heal_rate() * (2 + (rank_spec * 2 * level * force / 5000));
   int delay = 600 - (180 * rank_spec * level * force / 100000 * 2);
   int duration = 120 * rank_spec * level * force / 100000 * 2;
   string output = "Your healing is accelerated" + (this_body == body ? "" : " by " + this_body->short()) + ".\n";

   if (amount < 1) { amount = 1; }

   load_object("/d/buffs/healaccel");
   body->add_buff(new("/d/buffs/healaccel", amount, duration));

   if (body != this_body)
   {
      body->adjust_jedi_alignment(3);

      this_body->add_special_skill_delay("accelerate healing other", delay);
      body->add_special_skill_delay("accelerate healing", delay);

      tell(this_body, "You have accelerated " + body->short() + "'s healing.\n");
   }
   else
   {
      this_body->add_special_skill_delay("accelerate healing", delay);
   }

   tell(body, output);
}

void meditation_time(object body)
{
   object this_body = this_body();
   int alignment = this_body->query_jedi_alignment();

   if (!this_body) { return; }
   else if (!body || (environment(this_body) != environment(body)))
   {
      write(body->short() + " left and your concentration was broken.\n");

      return;
   }

   if (this_body->test_skill("heal accel", (alignment * (alignment < 0 ? 50 : 3)) + ((this_body->query_skill("force healing") / 2) - 500 + this_body->call_hooks("force_focus", HOOK_SUM))))
   {
      perform_healaccel(body);
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