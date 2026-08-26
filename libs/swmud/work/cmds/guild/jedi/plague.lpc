inherit VERB_OB;

void perform_plague(object living);
void concentrate(object living);

void do_plague_liv(object living)
{
   object this_body = this_body();
   int alignment = this_body->query_jedi_alignment();

   if (living->has_buff("/d/buffs/force_plague"))
   {
      write(living->short() + " has already had a plague inflicted upon them.\n");
      return;
   }
   else if (living == this_body)
   {
      write("Your existance is enough of a plague on yourself.\n");
      return;
   }

   this_body->targetted_action("$N $vconcentrate $p hatred $vtoward $t...", living);

   this_body->adjust_jedi_alignment(alignment < 0 ? -10 : this_body->has_buff("/d/buffs/force_focus") ? -20 : -15);

   this_body->add_skill_delay(8);

   concentrate(living);
}

void do_plague()
{
   object target = this_body()->get_target();

   if (!this_body()->is_body())
   {
      this_body()->targetted_action("$N $vconcentrate $p hatred $vtoward $t...", target);

      this_body()->add_skill_delay(8);

      concentrate(target);

      return;
   }

   if (target) { do_plague_liv(target); }
   else { write("Inflict plague on whom?\n"); }
}

mixed can_plague_liv()
{
   object this_body = this_body();

   if (this_body->query_guild_level("jedi"))
   {
      if (!this_body->has_learned_skill("force plague"))
      {
         return "You have not learned how to inflict plague upon others.\n";
      }
      else if (this_body->has_skill_delay())
      {
         return "You are too busy to concentrate on inflicting plague upon someone.\n";
      }
      else if (this_body->has_special_skill_delay("force plague"))
      {
         return "You need to wait " + convert_time(this_body->has_special_skill_delay("force plague")) + " before you can inflict plague upon someone again.\n";
      }
   }
   else
   {
      return "Only Jedi know how to use the Force to inflict plague upon someone.\n";
   }

   return 1;
}

mixed can_plague()
{
   object this_body = this_body();

   if (this_body->query_guild_level("jedi"))
   {
      if (!this_body->has_learned_skill("force plague"))
      {
         return "You have not learned how to inflict plague upon others.\n";
      }
      else if (this_body->has_skill_delay())
      {
         return "You are too busy to concentrate on inflicting plague upon someone.\n";
      }
      else if (this_body->has_special_skill_delay("force plague"))
      {
         return "You need to wait " + convert_time(this_body->has_special_skill_delay("force plague")) + " before you can inflict plague upon someone again.\n";
      }
   }
   else
   {
      return "Only Jedi know how to use the Force to inflict plague upon someone.\n";
   }

   return 1;
}

void perform_plague(object living)
{
   object this_body = this_body();
   float force = this_body->query_for();
   float level = this_body->query_guild_level("jedi");
   int rank = this_body->query_skill("force plague") / 100;
   int spec = this_body->query_guild_specialization_rank("jedi", "affliction");
   int rank_spec = (rank + spec) < 0 ? 0 : (rank + spec);
   int amount = (level * force * (rank_spec * 3)) / 5000;
   int delay = 300 - ((level * (20 + (rank_spec * 2)) / 50) * 2);
   int duration = 8 + ((rank_spec) * 4) + ((level * force * (6 + (rank_spec * 2)) / 5000) * 2);

   if (amount < 1) { amount = 1; }

   load_object("/d/buffs/force_plague");
   living->add_buff(new("/d/buffs/force_plague", amount, duration));

   load_object("/std/effect/plague");
   new("/std/effect/plague", rank + spec, level)->move(living);

   this_body->add_special_skill_delay("force plague", delay);
}

void concentrate(object living)
{
   object this_body = this_body();

   if (!this_body) { return; }

   if (this_body->test_skill("force plague", this_body->query_jedi_alignment() * -10))
   {
      perform_plague(living);

      if (!living->is_body() && (random(living->query_per() + 1) > random(100)))
      {
         living->attacked_by(this_body, 1);
      }
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