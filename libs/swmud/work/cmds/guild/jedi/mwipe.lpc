inherit VERB_OB;

void wipe_target(object living, string skill);
void concentration(object living, string skill);
string get_internal_skill_name(string skill);

mixed can_mwipe_liv_str(object living, string skill)
{
   object this_body = this_body();

   if (this_body->query_guild_level("jedi"))
   {
      if (this_body->is_body() && !this_body->has_learned_skill("memory wipe"))
      {
         return "You have not learned how to wipe someone's memory with the Force.\n";
      }
      else if (this_body->has_skill_delay())
      {
         return "You are too busy to concentrate on wiping someone's memory with the Force.\n";
      }
      else if (this_body->has_special_skill_delay("memory wipe"))
      {
         return "You need to wait " + convert_time(this_body->has_special_skill_delay("memory wipe")) + " before you can wipe someone's memory through the Force again.\n";
      }
      else
      {
         string skill_name = get_internal_skill_name(skill);

         if (!skill_name)
         {
            return "Invalid skill name: " + skill + "\n";
         }
      }
   }
   else
   {
      return "Only Jedi know how to wipe someone's memory with the Force.\n";
   }

   return 1;
}

void do_mwipe_liv_str(object living, string skill)
{
   object this_body = this_body();
   skill = get_internal_skill_name(skill);

   if (!living->query_skill(skill))
   {
      write(capitalize(living->short()) + " doesn't know anything about " + skill + ".\n");
      return;
   }
   else if (living->is_adversary())
   {
      if (living != this_body)
      {
         int alignment = this_body->query_jedi_alignment();

         this_body->adjust_jedi_alignment(alignment < 0 ? -5 : this_body->has_buff("/d/buffs/force_focus") ? -15 : -10);

         concentration(living, skill);

         return;
      }
      else
      {
         write("You wipe your own memory, and forget all about that time you wiped your own memory.\n");
         return;
      }
   }

   write("You can forget about wiping their memory.\n");
}

mixed can_mwipe_liv()
{
   object this_body = this_body();

   if (!this_body->query_guild_level("jedi"))
   {
      return "Only Jedi know how to wipe someone's memory with the Force.\n";
   }

   return 1;
}

void do_mwipe_liv(object living)
{
   if (living != this_body())
   {
      write("Wipe " + living->short() + "'s memory of what?\n");
   }
   else
   {
      write("You wipe your own memory, and forget all about that time you wiped your own memory.\n");
   }
}

mixed can_mwipe()
{
   object this_body = this_body();

   if (!this_body->query_guild_level("jedi"))
   {
      return "Only Jedi know how to wipe someone's memory with the Force.\n";
   }

   return 1;
}

void do_mwipe()
{
   write("Wipe who's memory?\n");
}

void wipe_target(object living, string skill)
{
   object this_body = this_body();
   int force = this_body->query_for();
   int level = this_body->query_guild_level("jedi");
   int target_level = living->query_guild_level("jedi");
   int rank = this_body->query_skill("memory wipe") / 100;
   int spec = this_body->query_guild_specialization_rank("jedi", "affliction");
   int rank_spec = (rank + spec) < 0 ? 0 : (rank + spec);
   int adjustment = (rank_spec * 30) + force + (level * 6);
   int delay = 420 - (rank_spec * 6) - (((level / 5) + (force / 5)) * 4);
   int duration = 60 + (rank_spec * 24) + (level * 2) + (force * 2);
   float resistance = 1.0 - ((target_level - (level + spec)) * 0.02);

   if (resistance < 1.0)
   {
      if (resistance < 0.1) { resistance = 0.1; }

      adjustment *= resistance;
   }

   if (!living->is_body())
   {
      duration = 3600;
   }

   load_object("/d/buffs/memory_wipe");
   living->add_buff(new("/d/buffs/memory_wipe", skill, adjustment, duration));

//   tell(this_body, "Reduced their " + skill + " by " + adjustment + " points (resisted " + resistance + ") for " + convert_time(duration) + ".\n");
   this_body->add_special_skill_delay("memory wipe", delay);
}

void concentration(object living, string skill)
{
   object this_body = this_body();
   int alignment = this_body->query_jedi_alignment();

   if (this_body->test_skill("memory wipe", alignment * (alignment < 0 ? -5 : -10)))
   {
      this_body->targetted_action("$N $vconcentrate on wiping $p1 memory.\n", living);

      wipe_target(living, skill);

      if (!living->is_body() && (random(living->query_per() + 1) > random(100)))
      {
         living->attacked_by(this_body, 1);
      }
   }
   else
   {
      this_body->targetted_action("$N $vattempt to wipe $p1 memory and $vfail.\n", living);
   }

   this_body->add_skill_delay(8);
}

string get_internal_skill_name(string skill)
{
   mixed data;
   skill = lower_case(skill);

   if (SKILL_D->query_skill(skill))
   {
      return skill;
   }

   foreach (string name in SKILL_D->query_skills())
   {
      data = SKILL_D->query_skill(name);

      if (data)
      {
         if (lower_case(data[0]) == skill)
         {
            return name;
         }
      }
   }

   return skill;
}

void create()
{
   add_rules( ({ "", "LIV", "LIV STR" }) );
}