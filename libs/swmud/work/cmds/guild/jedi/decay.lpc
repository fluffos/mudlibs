#include <hooks.h>

inherit VERB_OB;

void decay_class(object thing, int amount);

void do_decay_obj_by_str(object thing, string value)
{
   object this_body = this_body();
   int amount = to_int(value);

   if (thing->is_living())
   {
      if (thing != this_body)
      {
         write("There are easier ways to cause decay in living beings.\n");
      }
      else
      {
         write("Your life is going through enough decay as it is.\n");
      }
   }
   else if (thing->is_armor() || thing->is_weapon())
   {
      int alignment = this_body->query_jedi_alignment();

      if (thing->is_armor())
      {
         this_body->adjust_jedi_alignment(alignment < 0 ? -4 : this_body->has_buff("/d/buffs/force_focus") ? -12 : -8);
      }

      if (this_body->test_skill("force decay", (alignment * (thing->is_armor() ? (alignment < 0 ? -5 : -10) : (alignment < 0 ? -5 : 5))) + (thing->is_weapon() ? this_body->call_hooks("force_focus", HOOK_SUM) : 0)))
      {
         object env = environment(thing);

         decay_class(thing, amount);

         if (env->is_living() && !env->is_body() && (random(env->query_per() + 1) > random(100)))
         {
            env->attacked_by(this_body, 1);
         }
      }
      else
      {
         this_body->simple_action("$N $vfail to cause $o to decay.", thing);
      }

      this_body->add_skill_delay(8);
   }
   else
   {
      write("You don't know how to cause decay in something like that.\n");
   }
}

void do_decay_obj(object thing)
{
   do_decay_obj_by_str(thing, "100");
}

void do_decay()
{
   write("Decay what?\n");
}

mixed can_decay_obj_by_str()
{
   object this_body = this_body();

   if (this_body->query_guild_level("jedi"))
   {
      if (this_body->is_body() && !this_body->has_learned_skill("force decay"))
      {
         return "You have not learned how to cause decay through the Force.\n";
      }
      else if (this_body->has_skill_delay())
      {
         return "You are too busy to concentrate on causing decay through the Force.\n";
      }
      else if (this_body->has_special_skill_delay("force decay"))
      {
         return "You need to wait " + convert_time(this_body->has_special_skill_delay("force decay")) + " before you can cause decay through the Force again.\n";
      }
   }
   else
   {
      return "Only Jedi know how to cause decay through the Force.\n";
   }

   return 1;
}

mixed can_decay_obj()
{
   object this_body = this_body();

   if (this_body->query_guild_level("jedi"))
   {
      if (this_body->is_body() && !this_body->has_learned_skill("force decay"))
      {
         return "You have not learned how to cause decay through the Force.\n";
      }
      else if (this_body->has_skill_delay())
      {
         return "You are too busy to concentrate on causing decay through the Force.\n";
      }
      else if (this_body->has_special_skill_delay("force decay"))
      {
         return "You need to wait " + convert_time(this_body->has_special_skill_delay("force decay")) + " before you can cause decay through the Force again.\n";
      }
   }
   else
   {
      return "Only Jedi know how to cause decay through the Force.\n";
   }

   return 1;
}

mixed can_decay()
{
   object this_body = this_body();

   if (this_body->query_guild_level("jedi"))
   {
      if (this_body->is_body() && !this_body->has_learned_skill("force decay"))
      {
         return "You have not learned how to cause decay through the Force.\n";
      }
      else if (this_body->has_skill_delay())
      {
         return "You are too busy to concentrate on causing decay through the Force.\n";
      }
      else if (this_body->has_special_skill_delay("force decay"))
      {
         return "You need to wait " + convert_time(this_body->has_special_skill_delay("force decay")) + " before you can cause decay through the Force again.\n";
      }
   }
   else
   {
      return "Only Jedi know how to cause decay through the Force.\n";
   }

   return 1;
}

void decay_class(object thing, int amount)
{
   object this_body = this_body();
   int force = this_body->query_for();
   int level = this_body->query_guild_level("jedi");
   int rank = this_body->query_skill("force decay") / 100;
   int spec = this_body->query_guild_specialization_rank("jedi", "affliction");
   int rank_spec = (rank + spec) < 0 ? 0 : (rank + spec);
   int adjustment = (force + level) * rank_spec / 100;
   int delay = 600 - (rank_spec * 12) - (level * 2) - ((force / 5) * 4);

   if (adjustment < 1)
   {
      adjustment = 1;
   }

   if (amount > adjustment)
   {
      amount = adjustment;
   }

   if (amount > level)
   {
      amount = level;
   }

   if (environment(thing)->is_living())
   {
      this_body->targetted_action("$N $vcause $p1 $o to decay.", environment(thing), thing);
   }
   else
   {
      this_body->simple_action("$N $vcause $o to decay.", thing);
   }

   if (thing->is_armor() || thing->is_weapon())
   {
      thing->decrease_durability(amount);
   }

   this_body->add_special_skill_delay("force decay", delay);
}

void create()
{
   add_rules( ({ "", "OBJ", "OBJ by STR" }) );
}