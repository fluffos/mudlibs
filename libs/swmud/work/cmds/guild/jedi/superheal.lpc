#include <hooks.h>

inherit VERB_OB;

void perform_healing(object body);
void meditation_time(object body);
int has_special_skill_delay(string skill);

void do_superheal_liv(object living)
{
   object this_body = this_body();

   if (living->all_healthy())
   {
      if (living == this_body)
      {
         write("You are already at full health.\n");
         return;
      }
      else
      {
         write(living->short() + " is already at full health.\n");
         return;
      }
   }
   else if ((living == this_body) && this_body->has_special_skill_delay("superheal"))
   {
      write("You need to wait " + convert_time(this_body->has_special_skill_delay("superheal")) + " before you can superheal yourself again.\n");
      return;
   }
   else if ((living != this_body) && living->has_special_skill_delay("superheal"))
   {
      write(living->short() + " must wait " + convert_time(living->has_special_skill_delay("superheal")) + " before they can undergo superhealing again.\n");
      return;
   }
   else if ((living != this_body) && this_body->has_special_skill_delay("superheal other"))
   {
      write("You need to wait " + convert_time(this_body->has_special_skill_delay("superheal other")) + " before you can superheal another person again.\n");
      return;
   }
   else if (living->query_guild_level("assassin") && (living->query_jedi_alignment() < 0))
   {
      write(living->short() + " is too dedicated to the Dark side of the Force to be healed.\n");
      return;
   }

   if (living == this_body)
   {
      this_body->simple_action("$N $vclose $p eyes and $vmeditate solemnly on healing $r with the Force...\n");
   }
   else
   {
      this_body->targetted_action("$N $vclose $p eyes and $vmeditate solemnly on healing $t with the Force...\n", living);
   }

   this_body->adjust_jedi_alignment(this_body->has_buff("/d/buffs/force_focus") ? 4 : 2);

   call_out("meditation_time", 8, living);

   this_body->add_skill_delay(12);
}

void do_superheal()
{
   do_superheal_liv(this_body());
}

mixed can_superheal_liv()
{
   object this_body = this_body();

   if (!this_body->is_body()) { return 1; }

   if (this_body->query_guild_level("jedi"))
   {
      if (!this_body->has_learned_skill("superhealing"))
      {
         return "You have not learned how to superheal wounds with the Force.\n";
      }
      else if (this_body->query_guild_level("assassin"))
      {
         return "You are too dedicated to the Dark side of the Force to use it for healing.\n";
      }
      else if (this_body->has_buff("/d/buffs/anger"))
      {
         return "You are too angry to use the Force for healing.\n";
      }
      else if (this_body->get_target())
      {
         return "You are unable to concentrate on healing while in combat.\n";
      }
      else if (this_body->has_skill_delay())
      {
         return "You are too busy to concentrate on healing.\n";
      }
   }
   else
   {
      return "Only Jedi know how to use the Force for healing.\n";
   }

   return 1;
}

void perform_healing(object body)
{
   object this_body = this_body();
   int force = this_body->query_for();
   int level = this_body->query_guild_level("jedi");
   int rank = this_body->query_skill("superhealing") / 100;
   int spec = this_body->query_guild_specialization_rank("jedi", "healing");
   int rank_spec = (rank + spec) < 0 ? 0 : (rank + spec);
   int amount = body->query_max_health() * (level + (level * rank_spec * force / 2000)) / 100;
   int delay = 600 - (150 * rank_spec * level * force / 100000 * 2);

   tell(body, "You " + (this_body == body ? "heal yourself" : "are healed by " + this_body->short()) + ".\n");
   body->other_action("$N $vare surrounded by a deep blue glow.\n");
   body->heal_us(amount);

   foreach (string limb in body->query_limbs())
   {
      body->heal_limb(limb, amount * 0.5);
   }

   if (body != this_body)
   {
      body->adjust_jedi_alignment(5);

      this_body->add_special_skill_delay("superheal other", delay);
      body->add_special_skill_delay("superheal", delay);
   }
   else
   {
      this_body->add_special_skill_delay("superheal", delay);
   }
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

   if (this_body->test_skill("superhealing", (alignment * (alignment < 0 ? 50 : 4)) + ((this_body->query_skill("force healing") / 2) - 500) + this_body->call_hooks("force_focus", HOOK_SUM)))
   {
      perform_healing(body);
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