inherit VERB_OB;

void perform_rage();

void do_frage()
{
   object this_body = this_body();
   int alignment = this_body->query_jedi_alignment();

   this_body->adjust_jedi_alignment(alignment < 0 ? -5 : this_body->has_buff("/d/buffs/force_focus") ? -5 : -10);

   this_body->add_skill_delay(8);

   if (this_body->test_skill("force rage", alignment * (alignment < 0 ? -8 : -10)))
   {
      write("You focus on your anger, letting the Force fuel your rage.\n");
      this_body->other_action("$N focuses on $p anger, letting the Force fuel $p rage.\n");

      perform_rage();
   }
   else
   {
      this_body->simple_action("$N $vfail to focus on $p anger.\n");
   }
}

mixed can_frage()
{
   object this_body = this_body();

   if (this_body->query_guild_level("jedi"))
   {
      if (!this_body->has_learned_skill("force rage"))
      {
         return "You have not learned how to fuel your rage through the Force.\n";
      }
      else if (this_body->has_skill_delay())
      {
         return "You are too busy to focus on fueling your rage through the Force.\n";
      }
      else if (this_body->has_special_skill_delay("force rage"))
      {
         return "You need to wait " + convert_time(this_body->has_special_skill_delay("force rage")) + " before you can fuel your rage through the Force again.\n";
      }
   }
   else
   {
      return "Only Jedi know how to use the Force to fuel their rage.\n";
   }

   return 1;
}

void perform_rage()
{
   object this_body = this_body();
   int force = this_body->query_for();
   int level = this_body->query_guild_level("jedi");
   int rank = this_body->query_skill("force rage") / 100;
   int spec = this_body->query_guild_specialization_rank("jedi", "control");
   int rank_spec = (rank + spec) < 0 ? 0 : (rank + spec);
   int rank_mod = (rank + spec) < 0 ? 0 : ((rank + spec) > 10 ? 10 : (rank + spec));
   int damage_bonus = ((((level / 5) + rank_spec) * 2) * force) / 100;
   int agility_bonus = ((level + (rank_spec * 5)) * force) / 400;
   int bonus_duration = 16 + (rank_spec * 2);
   int damage_penalty = (damage_bonus * (100 - (rank_mod * 10)) / 100) + (20 - (rank_mod * 2));
   int agility_penalty = (agility_bonus * (100 - (rank_mod * 10)) / 100) + (30 - (rank_mod * 3));
   int penalty_duration = 180 - ((((level + (rank_mod * 5)) * force) * 18) / 1000);
   int delay = 420 - (((level / 5) + (rank_spec)) * 6);

   if (damage_bonus < 1) { damage_bonus = 1; }
   if (agility_bonus < 1) { agility_bonus = 1; }

   load_object("/d/buffs/force_rage");
   this_body->add_buff(new("/d/buffs/force_rage", damage_bonus, agility_bonus, bonus_duration, damage_penalty, agility_penalty, penalty_duration));

   this_body->add_special_skill_delay("force rage", delay);
}

void create()
{
   add_rules( ({ "" }) );
}