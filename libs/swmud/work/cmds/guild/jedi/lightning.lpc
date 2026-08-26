inherit VERB_OB;

void zap_target(object thing);
void concentration(object thing);

void do_lightning_obj(object thing)
{
   object this_body = this_body();

   if (this_body->query_guild_level("jedi"))
   {
      if (this_body->is_body() && !this_body->has_learned_skill("force lightning"))
      {
         write("You have not learned how to channel Force lightning.\n");
      }
      else if (this_body->has_skill_delay())
      {
         write("You are too busy to concentrate on manipulating the Force.\n");
      }
      else if (!this_body->query_limb_health("left hand") && !this_body->query_limb_health("right hand"))
      {
         write("You are unable to channel Force lightning through your hands in their current condition.\n");
      }
      else
      {
         if (thing->is_adversary())
         {
            if (thing != this_body)
            {
               int alignment = this_body->query_jedi_alignment();
               int max_alignment = this_body->query_max_jedi_alignment();

               this_body->adjust_jedi_alignment(alignment < 0 ? -5 : (max_alignment - 1) * -1);

               concentration(thing);
            }
            else
            {
               write("That would be incredibly painful, and although maximum pain is the right idea, it would be much better to inflict that pain on something else.\n");
            }
         }
         else
         {
            write("That would be a waste of energy.\n");
         }
      }
   }
   else
   {
      write("Only Jedi know how to manipulate the Force.\n");
   }
}

void do_lightning()
{
   object target = this_body()->get_target();

   if (!this_body()->is_body())
   {
      concentration(target);

      return;
   }

   if (target) { do_lightning_obj(target); }
   else { write("Lightning what?\n"); }
}

void zap_target(object thing)
{
   object this_body = this_body();
   int force = this_body->query_for();
   int level = this_body->query_guild_level("jedi");
   int rank = this_body->query_skill("lightning") / 100;
   int spec = this_body->query_guild_specialization_rank("jedi", "destruction");
   int rank_spec = (rank + spec) < 0 ? 0 : (rank + spec);
   int floor = level * force * rank_spec / 1000;
   int ceiling = (level + rank_spec) * rank_spec * force * force / 40000;
   int amount = (floor < ceiling ? floor + random(ceiling - floor + 1) : floor);

   if (!this_body->query_limb_health("left hand") || !this_body->query_limb_health("right hand"))
   {
      amount /= 2;
   }

   if (amount < (level / 2)) { amount = level / 2; }

//   this_body->simple_action("$N can do lightning from " + floor + " to " + ceiling + ", and had a damage roll of " + amount + ".\n");
//   this_body->targetted_action("$N $vsend bolts of lightning from $p hands to $t!\n", thing);
   if (!present("force_lightning", this_body))
   {
      load_object("/d/obj/spec_damage");
      new("/d/obj/spec_damage", "Force lightning", "force_lightning")->move(this_body);
      present("force_lightning", this_body)->set_combat_messages("combat-lightning");
      present("force_lightning", this_body)->set_death_message("$N was killed by bolts of lightning from $P1 hands at $o1.");
   }

   this_body->add_event(thing, present("force_lightning", this_body), thing->query_random_limb(), ([ "electrical" : amount ]), this_body);

   this_body->start_fight(thing);
   this_body->handle_events();
}

void concentration(object thing)
{
   object this_body = this_body();
   int alignment = this_body->query_jedi_alignment();

   if (this_body->test_skill("lightning", this_body->query_jedi_alignment() * (alignment < 0 ? -10 : -20)))
   {
      zap_target(thing);
   }
   else
   {
      this_body->simple_action("$N $vattempt to channel Force energy through $p arms and $vlose focus.\n");
   }

   this_body->add_skill_delay(12);
}

void create()
{
   add_rules( ({ "", "OBJ" }) );
}