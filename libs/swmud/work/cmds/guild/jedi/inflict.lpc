inherit VERB_OB;

int get_floor(object living);
int get_ceiling(object living);
int get_stun(object living);
void hurt_target(object living);
void concentration(object living);

void do_inflict_liv(object living)
{
   object this_body = this_body();

   if (this_body->query_guild_level("jedi"))
   {
      if (this_body->is_body() && !this_body->has_learned_skill("inflict pain"))
      {
         write("You have not learned how to inflict pain.\n");
      }
      else if (this_body->has_skill_delay())
      {
         write("You are too busy to concentrate on inflicting pain.\n");
      }
      else
      {
         if (living->is_adversary())
         {
            if (living != this_body)
            {
               int alignment = this_body->query_jedi_alignment();

               this_body->adjust_jedi_alignment(alignment < 0 ? -2 : this_body->has_buff("/d/buffs/force_focus") ? -8 : -5);

               concentration(living);
            }
            else
            {
               write("You're already in too much pain as it is.\n");
            }
         }
         else
         {
            write("You could find more important things to inflict pain upon.\n");
         }
      }
   }
   else
   {
      write("Only Jedi know how to inflict pain upon someone.\n");
   }
}

void do_inflict()
{
   object target = this_body()->get_target();

   if (!this_body()->is_body())
   {
      concentration(target);

      return;
   }

   if (target) { do_inflict_liv(target); }
   else { write("Inflict pain upon whom?\n"); }
}

void hurt_target(object living)
{
   object this_body = this_body();
   int floor = get_floor(living);
   int ceiling = get_ceiling(living);
   int amount = floor + random(ceiling - floor + 1);

//   this_body->simple_action("$N can inflict pain from " + floor + " to " + ceiling + ", and had a damage roll of " + amount + ".\n");
   this_body->targetted_action("$N $vinflict pain upon $t!\n", living);

   living->weaken_us(amount);

   living->stun(get_stun(living));

   this_body->initiate_combat(living);
   this_body->handle_events();
}

int get_floor(object living)
{
   object this_body = this_body();
   int force = this_body->query_for();
   int living_force = living->query_for();
   int level = this_body->query_guild_level("jedi");
   int rank = this_body->query_skill("inflict pain") / 100;
   int spec = this_body->query_guild_specialization_rank("jedi", "affliction");
   int amount = (level / (15 - rank)) + ((level / (20 - rank)) * 2) + (force / 10) + spec;

   if (force < (living_force - (spec * 3)))
   {
      amount -= ((living_force - (spec * 3)) - force);
   }

   return (amount > 0 ? amount : 1);
}

int get_ceiling(object living)
{
   object this_body = this_body();
   int force = this_body->query_for();
   int living_force = living->query_for();
   int level = this_body->query_guild_level("jedi");
   int rank = this_body->query_skill("inflict pain") / 100;
   int spec = this_body->query_guild_specialization_rank("jedi", "affliction");
   int amount = (level / (12 - rank)) + (level / (15 - rank)) + (level / (20 - rank)) + (force / 5) + random((spec * 2) + 1);

   if (force < (living_force - (spec * 3)))
   {
      amount -= ((living_force - (spec * 3)) - force);
   }

   return (amount > 0 ? amount : 1);
}

int get_stun(object living)
{
   object this_body = this_body();
   int force = this_body->query_for();
   int living_force = living->query_for();
   int level = this_body->query_guild_level("jedi");
   int rank = this_body->query_skill("inflict pain") / 100;
   int spec = this_body->query_guild_specialization_rank("jedi", "affliction");
   int rank_spec = (rank + spec) < 0 ? 0 : (rank + spec);
   int amount = (level + force + (rank_spec * 15));

   if (force < (living_force - (spec * 3)))
   {
      amount -= (((living_force - (spec * 3)) - force) * 2);
   }

   return amount > random(300 - (spec * 15)) ? 2 : 0;
}

void concentration(object living)
{
   object this_body = this_body();
   int alignment = this_body->query_jedi_alignment();

   if (this_body->test_skill("inflict pain", (alignment * -10)))
   {
      hurt_target(living);
   }
   else
   {
      this_body->targetted_action("$N $vattempt to inflict pain upon $t and $vfail.\n", living);
   }

   this_body->add_skill_delay(4);
}

void create()
{
   add_rules( ({ "", "LIV" }) );
}