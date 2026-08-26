inherit CMD;

void perform_healing();
void concentration();

void main()
{
   object this_body = this_body();

   if (!this_body->is_body())
   {
      this_body->add_skill_delay(4);

      concentration();

      return;
   }

   if (this_body->query_guild_level("jedi"))
   {
      if (!this_body->has_learned_skill("anger"))
      {
         write("You have not learned how to focus your anger.\n");
      }
      else if (this_body->query_health() >= this_body->query_max_health())
      {
         write("You are already at full health.\n");
      }
      else if (this_body->has_skill_delay())
      {
         write("You are too busy to focus your anger.\n");
      }
      else
      {
         int alignment = this_body->query_jedi_alignment();

         this_body->adjust_jedi_alignment(alignment < 0 ? -4 : this_body->has_buff("/d/buffs/force_focus") ? -12 : -8);

         this_body->add_skill_delay(4);

         concentration();
      }
   }
   else
   {
      write("Only Jedi know how to focus their anger.\n");
   }
}

void perform_healing()
{
   object this_body = this_body();
   int force = this_body->query_for();
   int level = this_body->query_guild_level("jedi");
   int rank = this_body->query_skill("anger") / 100;
   int spec = this_body->query_guild_specialization_rank("jedi", "control");
   int rank_spec = (rank + spec) < 0 ? 0 : (rank + spec);
   int floor = rank_spec * 0.1 * ((force / 5) + (level / 5));
   int ceiling = rank_spec * 0.1 * (10 + (force / 5) + level);
   int amount;

   if (floor < 1) { floor = 1; }

   if (ceiling < 10) { ceiling = 10; }

   amount = floor + random(ceiling - floor + 1);

   if (amount > (this_body->query_max_health() - this_body->query_health()))
   {
      amount = this_body->query_max_health() - this_body->query_health();
   }

   tell(this_body, "The pain of your injuries seems to vanish as you focus your anger.\n");
   this_body->other_action("$N focuses on $p anger to ignore the pain of $p injuries.");

   load_object("/d/buffs/anger");
   this_body->add_buff(new("/d/buffs/anger", amount, 120));
}

/*
int get_duration()
{
   object this_body = this_body();
   int rank = this_body->query_skill("anger") / 100;

   return 60 + (rank * 6);
}
*/

void concentration()
{
   object this_body = this_body();
   int alignment = this_body->query_jedi_alignment();

   if (this_body->test_skill("anger", alignment * (alignment < 0 ? -8 : -10)))
   {
      perform_healing();
   }
   else
   {
      this_body->my_action("$N $vfail to focus on $p anger.\n");
      this_body->do_game_command("wince");
   }
}