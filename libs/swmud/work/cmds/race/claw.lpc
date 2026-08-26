// Defel racial skill
inherit VERB_OB;

void claw(object living);

void do_claw_liv(object living)
{
   object this_body = this_body();

   if (living == this_body)
   {
      write("You claw yourself and reel from the pain.\n");
   }
   else
   {
      this_body->add_skill_delay(8);

      if (this_body->test_skill("claw", this_body->query_primary_level() * 10))
      {
         claw(living);
      }
      else
      {
         this_body->targetted_action("$N $vtry to claw at $t and $vfail.\n", living);
      }
   }
}

void do_claw()
{
   object target = this_body()->get_target();

   if (target) { do_claw_liv(target); }
}

mixed can_claw_liv()
{
   object this_body = this_body();

   if (this_body->query_race() == "defel")
   {
      if (this_body->has_skill_delay())
      {
         return "You are too busy to use your claws.\n";
      }
      else if (this_body->query_stunned())
      {
         return "You are paralyzed and unable to use your claws.\n";
      }
   }
   else
   {
      return "Only Defel can claw someone.\n";
   }

   return 1;
}

mixed can_claw()
{
   object this_body = this_body();

   if (this_body->query_race() == "defel")
   {
      if (this_body->has_skill_delay())
      {
         return "You are too busy to use your claws.\n";
      }
      else if (!this_body->get_target())
      {
         return "You are not in combat with anyone.\n";
      }
      else if (this_body->query_stunned())
      {
         return "You are paralyzed and unable to use your claws.\n";
      }
   }
   else
   {
      return "Only Defel can claw someone.\n";
   }

   return 1;
}

void claw(object living)
{
   object this_body = this_body();
   int rank = this_body->query_skill("claw") / 100;
   int primary_level = this_body->query_primary_level();
   int damage = 10 + (rank * 2) + random(primary_level);

   if (!present("defel_claw", this_body))
   {
      load_object("/d/obj/spec_damage");
      new("/d/obj/spec_damage", "claws", "defel_claw")->move(this_body);
      present("defel_claw", this_body)->set_combat_messages("combat-claw");
      present("defel_claw", this_body)->set_death_message("$N dies from $N1 claws at $o1.");
   }

   this_body->add_event(living, present("defel_claw", this_body), "none", ([ "slashing" : damage ]), this_body);
   this_body->handle_events();
}

void create()
{
   add_rules( ({ "", "LIV" }) );
}