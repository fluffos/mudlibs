inherit CMD;

void concentration();

void main(string arg)
{
   object this_body = this_body();

   if (strlen(arg) && (arg == "off"))
   {
      if (this_body->has_buff("/d/buffs/force_focus"))
      {
         this_body->cancel_buff("/d/buffs/force_focus");
      }
      else
      {
         write("You are not focusing on the Light side of the Force.\n");
      }
   }
   else if (this_body->query_guild_level("jedi"))
   {
      if ((this_body->query_jedi_alignment() < 0) || this_body->query_guild_level("assassin"))
      {
         write("You are too dedicated to the Dark side of the Force to focus on the Light side.\n");
      }
      else if (this_body->has_buff("/d/buffs/anger"))
      {
         out("You are too angry to focus on the Light side of the Force.\n");
      }
      else if (!this_body->has_learned_skill("force focus"))
      {
         out("You have not learned how to focus on the Light side of the Force.\n");
      }
      else if (this_body->has_blocked_skill("force focus"))
      {
         out("Your ability to use this command has been disabled.\n");
      }
      else if (this_body->has_buff("/d/buffs/force_focus"))
      {
         out("You are already focusing on the Light side of the Force.\n");
      }
      else if (this_body->has_special_skill_delay("force focus"))
      {
         out("You need to wait " + convert_time(this_body->has_special_skill_delay("force focus")) + " before you can focus on the Light side of the Force again.\n");
      }
      else
      {
         this_body->adjust_jedi_alignment(1);

         concentration();
      }
   }
   else
   {
      out("Only Jedi know how to focus on the Light side of the Force.\n");
   }
}

void concentration()
{
   object this_body = this_body();
   int alignment = this_body->query_jedi_alignment();
   int level = this_body->query_guild_level("jedi");
   float force = this_body->query_for();
   int rank = this_body->query_skill("force focus") / 100;
   int spec = this_body->query_guild_specialization_rank("jedi", "control");
   int rank_spec = (rank + spec) < 0 ? 0 : (rank + spec);
   int bonus = ((rank_spec * 20) + level) * force / 50;
   int duration = ((rank_spec * 12) + level + 10) * 2;
   int delay = 900 - (((rank_spec * 5) + level) * 2);

   this_body->test_skill("force focus", alignment * 5);

   load_object("/d/buffs/force_focus");
   this_body->add_buff(new("/d/buffs/force_focus", bonus, duration));

   this_body->add_special_skill_delay("force focus", delay);
}