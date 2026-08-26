// Ithorian racial skill
inherit VERB_OB;

void roar(object living);

void do_roar_liv(object living)
{
   object this_body = this_body();

   if (living == this_body)
   {
      write("You roar at yourself but it has no effect.\n");
   }
   else if (member_array(living, this_body->query_targets()) == -1)
   {
      write("You are not in combat with " + living->short() + ".\n");
   }
   else
   {
      this_body->add_skill_delay(8);

      if (this_body->test_skill("roar", this_body->query_primary_level() * 10))
      {
         roar(living);
      }
      else
      {
         this_body->targetted_action("$N $vtry to roar at $t and $vfail.\n", living);
      }
   }
}

void do_roar()
{
   object target = this_body()->get_target();

   if (target) { do_roar_liv(target); }
}

mixed can_roar_liv()
{
   object this_body = this_body();

   if (this_body->query_race() == "ithorian")
   {
      if (this_body->has_skill_delay())
      {
         return "You are too busy to concentrate on roaring.\n";
      }
      else if (this_body->query_stunned())
      {
         return "You are paralyzed and unable to roar at someone.\n";
      }
   }
   else
   {
      return "Only Ithorians can roar at someone.\n";
   }

   return 1;
}

mixed can_roar()
{
   object this_body = this_body();

   if (this_body->query_race() == "ithorian")
   {
      if (this_body->has_skill_delay())
      {
         return "You are too busy to concentrate on roaring.\n";
      }
      else if (!this_body->get_target())
      {
         return "You are not in combat with anyone.\n";
      }
      else if (this_body->query_stunned())
      {
         return "You are paralyzed and unable to roar at someone.\n";
      }
   }
   else
   {
      return "Only Ithorians can roar at someone.\n";
   }

   return 1;
}

void roar(object living)
{
   object this_body = this_body();
   int rank = this_body->query_skill("roar") / 100;
   int primary_level = this_body->query_primary_level();
   int damage = 0;

   // Chance to do damage
   if ((rank * 10) >= random(100))
   {
      damage = 1 + random(rank * living->query_body_size());
   }

   if (!present("ithorian_roar", this_body))
   {
      load_object("/d/obj/spec_damage");
      new("/d/obj/spec_damage", "roar", "ithorian_roar")->move(this_body);
      present("ithorian_roar", this_body)->set_combat_messages("combat-roar");
      present("ithorian_roar", this_body)->set_death_message("$N dies from shock as $N1 roars at $o1.");
   }

   this_body->add_event(living, present("ithorian_roar", this_body), "none", ([ "sonic" : damage ]), this_body);
   this_body->handle_events();

   // Stun for 1 round, and chance to stun for 2 rounds
   living->stun(2 + ((rank * 10) > random(100) ? 2 : 0));
}

void create()
{
   add_rules( ({ "", "LIV" }) );
}