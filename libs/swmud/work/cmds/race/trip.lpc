// Twi'lek racial skill
inherit VERB_OB;

void trip(object body);

void do_trip_liv(object living)
{
   object this_body = this_body();

   if (living == this_body)
   {
      write("You trip yourself and fall flat on your face.\n");
   }
   else
   {
      this_body->add_skill_delay(8);

      if (this_body->test_skill("trip", (this_body->query_primary_level() * 10) - (living->query_primary_level() * 6)))
      {
         trip(living);
      }
      else
      {
         this_body->targetted_action("$N $vtry to trip $t and $vfail.\n", living);

         // Perception check, if not in combat with an NPC
         // Did they notice you just tried to trip them?
         if ((living != this_body->query_target()) && !living->is_body() && (living->query_per() > random(100)))
         {
            living->targetted_action("$N noticed that $t tried to trip $n!\n", this_body);
            living->attacked_by(this_body, 1);
         }
      }
   }
}

void do_trip()
{
   object target = this_body()->get_target();

   if (target) { do_trip_liv(target); }
   else { write("Trip who?\n"); }
}

mixed can_trip_liv()
{
   object this_body = this_body();

   if (this_body->query_race() == "twi'lek")
   {
      if (this_body->has_skill_delay())
      {
         return "You are too busy to concentrate on tripping someone.\n";
      }
      else if (this_body->query_stunned())
      {
         return "You are paralyzed and unable trip someone.\n";
      }
   }
   else
   {
      return "Only Twi'leks can trip someone.\n";
   }

   return 1;
}

void trip(object body)
{
   object this_body = this_body();
   int rank = this_body->query_skill("trip") / 100;
   int primary_level = this_body->query_primary_level();

   // Chance to do damage
   if ((rank * 10) > random(100))
   {
      int damage = rank + random(((rank * 4) - rank) + 1);

      if (!present("twilek_trip", this_body))
      {
         load_object("/d/obj/spec_damage");
         new("/d/obj/spec_damage", "maneuver", "twilek_trip")->move(this_body);
         present("twilek_trip", this_body)->set_combat_messages("combat-trip");
         present("twilek_trip", this_body)->set_death_message("$N was tripped by $N1 at $o1 and dies from the impact of the fall.");
      }

      this_body->add_event(body, present("twilek_trip", this_body), "none", ([ "striking" : damage ]), this_body);
      this_body->handle_events();
   }
   else
   {
      this_body->targetted_action("$N $vtrip $t with a clever maneuver.", body);
   }

   // Stun for 1 round, and chance to stun for 2 rounds
   body->stun(2 + ((rank * 10) > random(100) ? 2 : 0));

   if (member_array(body, this_body->query_targets()) == -1)
   {
      this_body->start_fight(body);
      this_body->adjust_jedi_alignment(-1);
   }
}

void create()
{
   add_rules( ({ "", "LIV" }) );
}