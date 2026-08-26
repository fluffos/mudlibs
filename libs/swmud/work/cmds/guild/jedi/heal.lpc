#include <hooks.h>

inherit VERB_OB;

void perform_healing(object body);
void meditation_time(object body);

void do_heal_liv(object living)
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
   else if (living->query_guild_level("assassin") && (living->query_jedi_alignment() < 0))
   {
      write(living->short() + " is too dedicated to the Dark side of the Force to be healed.\n");
      return;
   }

   if (living == this_body)
   {
      this_body->simple_action("$N $vconcentrate for a moment on healing $r with the Force...\n");
   }
   else
   {
      this_body->targetted_action("$N $vconcentrate momentarily on healing $t with the Force...\n", living);
   }

   this_body->adjust_jedi_alignment(this_body->has_buff("/d/buffs/force_focus") ? 2 : 1);

   call_out("meditation_time", 2, living);

   this_body->add_skill_delay(4);
}

void do_heal()
{
   do_heal_liv(this_body());
}

mixed can_heal_liv()
{
   object this_body = this_body();

   if (this_body->query_guild_level("jedi"))
   {
      if (!this_body->has_learned_skill("force healing"))
      {
         return "You have not learned how to heal wounds with the Force.\n";
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

mixed can_heal()
{
   object this_body = this_body();

   if (this_body->query_guild_level("jedi"))
   {
      if (!this_body->has_learned_skill("force healing"))
      {
         return "You have not learned how to heal wounds with the Force.\n";
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
   int rank = this_body->query_skill("force healing") / 100;
   int spec = this_body->query_guild_specialization_rank("jedi", "healing");
   int rank_spec = (rank + spec) < 0 ? 0 : (rank + spec);
   int amount = (force / 5) + (rank_spec * 8 * level * force / 5000);

   tell(body, "You " + (this_body == body ? "heal yourself" : "are healed by " + this_body->short()) + ".\n");
   body->other_action("$N $vare surrounded by a faint blue glow.\n");
   body->heal_us(amount);

   foreach (string limb in body->query_limbs())
   {
      body->heal_limb(limb, amount * 0.5);
   }

   if (body != this_body)
   {
      body->adjust_jedi_alignment(1);
   }
}

void meditation_time(object body)
{
   object this_body = this_body();
   int alignment;

   if (!this_body) { return; }
   else if (this_body->get_target())
   {
      write("You lose concentration on healing as you defend yourself!\n");

      return;
   }
   else if (!body || (environment(this_body) != environment(body)))
   {
      write(body->short() + " left and your concentration was broken.\n");

      return;
   }

   alignment = this_body->query_jedi_alignment();

   if (this_body->test_skill("force healing", (alignment * (alignment < 0 ? 25 : 10)) + this_body->call_hooks("force_focus", HOOK_SUM)))
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