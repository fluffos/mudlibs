inherit VERB_OB;

void choke_target(object living);
void concentration(object living);

void do_choke_liv(object living)
{
   object this_body = this_body();

   if (this_body->query_guild_level("jedi"))
   {
      if (this_body->is_body() && !this_body->has_learned_skill("force choke"))
      {
         write("You have not learned how to choke someone with the Force.\n");
      }
      else if (this_body->has_skill_delay())
      {
         write("You are too busy to concentrate on choking someone with the Force.\n");
      }
      else
      {
         if (living->is_adversary())
         {
            if (living != this_body)
            {
               int alignment = this_body->query_jedi_alignment();

               this_body->adjust_jedi_alignment(alignment < 0 ? -5 : this_body->has_buff("/d/buffs/force_focus") ? -13 : -9);

               concentration(living);
            }
            else
            {
               write("You find your lack of faith disturbing, and choke yourself to prove that you've still got what it takes.\n");
            }
         }
         else
         {
            write("You could find more important things to choke.\n");
         }
      }
   }
   else
   {
      write("Only Jedi know how to choke someone with the Force.\n");
   }
}

void do_choke()
{
   object target = this_body()->get_target();

   if (!this_body()->is_body())
   {
      concentration(target);

      return;
   }

   if (target) { do_choke_liv(target); }
   else { write("Choke whom?\n"); }
}

void choke_target(object living)
{
   object this_body = this_body();
   int level = this_body->query_guild_level("jedi");
   int force = this_body->query_for();
   int rank = this_body->query_skill("force choke") / 100;
   int spec = this_body->query_guild_specialization_rank("jedi", "telekinesis");
   int rank_spec = (rank + spec) < 0 ? 0 : (rank + spec);
   int floor = rank_spec * 3 * level * force / 5000;
   int ceiling = (force / 10) + (rank_spec * 9 * level * force / 6000);
   int stun = ((force + level) > random(150) ? 2 : 0) + (rank_spec > random(10) ? 2 : 0);
   int damage;

   if (floor < 1) { floor = 1; }

   if (ceiling < floor) { ceiling = floor; }

   damage = floor + random(ceiling - floor + 1);

//   this_body->simple_action("$N can choke from " + floor + " to " + ceiling + ", and had a damage roll of " + damage + ".\n");
//   this_body->targetted_action("$N $vchoke $t!\n", living);
   if (!present("force_choke", this_body))
   {
      load_object("/d/obj/spec_damage");
      new("/d/obj/spec_damage", "Force choke", "force_choke")->move(this_body);
      present("force_choke", this_body)->set_combat_messages("combat-choke");
      present("force_choke", this_body)->set_death_message("$N was choked to death through the Force by $N1 at $o1.");
   }

   this_body->add_event(living, present("force_choke", this_body), choice(({ "head", "torso" })), ([ "unstoppable" : damage ]), this_body);

   if (stun > 0) { living->stun(stun); }

   this_body->start_fight(living);
   this_body->handle_events();
}

void concentration(object living)
{
   object this_body = this_body();
   int alignment = this_body->query_jedi_alignment();

   if (this_body->test_skill("force choke", (alignment * -8) + (this_body->query_guild_level("jedi") * 10) + (this_body->query_skill("telekinesis") / 100 * 30) - 300 - (living->query_guild_level("jedi") * 20)))
   {
      this_body->test_skill("telekinesis", this_body->query_guild_level("jedi") * 5);

      choke_target(living);
   }
   else
   {
      this_body->targetted_action("$N $vattempt to choke $t and $vfail.\n", living);
   }

   this_body->add_skill_delay(8);
}

void create()
{
   add_rules( ({ "", "LIV" }) );
}