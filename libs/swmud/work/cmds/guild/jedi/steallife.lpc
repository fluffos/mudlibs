inherit VERB_OB;

int get_floor(object living);
int get_ceiling(object living);
void drain_target(object living);
void concentration(object living);

void do_steallife_liv(object living)
{
   object this_body = this_body();

   if (this_body->query_guild_level("jedi"))
   {
      if (this_body->is_body() && !this_body->has_learned_skill("steal life"))
      {
         write("You have not learned how to drain someone's life through the force.\n");
      }
      else if (this_body->has_skill_delay())
      {
         write("You are too busy to concentrate on draining someone's life.\n");
      }
      else if (this_body->query_health() >= this_body->query_max_health())
      {
         write("You are already at full health.\n");
      }
      else
      {
         if (living->is_adversary())
         {
            if (living != this_body)
            {
               int alignment = this_body->query_jedi_alignment();

               this_body->adjust_jedi_alignment(alignment < 0 ? -5 : this_body->has_buff("/d/buffs/force_focus") ? -15 : -10);

               concentration(living);
            }
            else
            {
               write("Just being alive is enough of a drain on yourself.\n");
            }
         }
         else
         {
            write("You could find someone whose life is actually worth draining.\n");
         }
      }
   }
   else
   {
      write("Only Jedi know how to drain someone's life through the Force.\n");
   }
}

void do_steallife()
{
   object target = this_body()->get_target();

   if (!this_body()->is_body())
   {
      concentration(target);

      return;
   }

   if (target) { do_steallife_liv(target); }
   else { write("Drain whose life?\n"); }
}

void drain_target(object living)
{
   object this_body = this_body();
   int floor = get_floor(living);
   int ceiling = get_ceiling(living);
   int amount = floor + random(ceiling - floor + 1);

   this_body->simple_action("$N can steal life from " + floor + " to " + ceiling + ", and had a roll of " + amount + ".\n");
   this_body->targetted_action("$N $vdrain some of $p1 life energy, adding it to $p own.\n", living);

   amount = living->weaken_us(amount);

   if (amount > 0)
   {
      this_body->heal_us(amount);
   }
   else
   {
      tell(this_body, "You discover that " + living->short() + " is nearly lifeless.\n");
   }

   this_body->initiate_combat(living);
   this_body->handle_events();
}

int get_floor(object living)
{
   object this_body = this_body();
   int force = this_body->query_for();
   int living_force = living->query_for();
   int level = this_body->query_guild_level("jedi");
   int rank = this_body->query_skill("steal life") / 100;
   int spec = this_body->query_guild_specialization_rank("jedi", "affliction");
   int amount = to_int((rank * 0.2) * ((force / 5) + (level / 5) + spec));

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
   int rank = this_body->query_skill("steal life") / 100;
   int spec = this_body->query_guild_specialization_rank("jedi", "affliction");
   int amount = to_int((rank * 0.1) * (20 + ((force / 5) * 2) + (level * 2) + (spec * 4)));

   if (force < (living_force - (spec * 3)))
   {
      amount -= ((living_force - (spec * 3)) - force);
   }

   return (amount > 0 ? amount : force / 5);
}

void concentration(object living)
{
   object this_body = this_body();
   int alignment = this_body->query_jedi_alignment();

   if (this_body->test_skill("steal life", (alignment * -15)))
   {
      drain_target(living);
   }
   else
   {
      this_body->targetted_action("$N $vattempt to drain some of $p1 life energy, and $vfail.\n", living);
   }

   this_body->add_skill_delay(12);
}

void create()
{
   add_rules( ({ "", "LIV" }) );
}