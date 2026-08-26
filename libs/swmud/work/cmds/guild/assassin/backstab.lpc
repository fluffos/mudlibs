inherit VERB_OB;

void backstab(object body);

void do_backstab_liv(object living)
{
   object this_body = this_body();

   if (living == this_body)
   {
      write("You stab yourself in the back and will never forgive yourself.\n");
   }
   else if (living->has_been_backstabbed_by(this_body))
   {
      write(capitalize(living->short()) + " is too suspicous of you now for you to successfully backstab " + living->query_objective() + " again.\n");
   }
   else
   {
      this_body->add_skill_delay(4);

      if (this_body->test_skill("backstab", (this_body->query_guild_level("assassin") * 6)))
      {
         backstab(living);
      }
      else
      {
         this_body->refresh_stats();

         if (random(150) > (this_body->query_guild_level("assassin") + (this_body->query_skill("backstab") / 20) + ((this_body->query_agi() + this_body->query_dex()) / 5)))
         {
            this_body->targetted_action("$N $vtry to stab $t in the back and $vfail terribly, injuring $r in the process!\n", living);

            this_body->weaken_us(random(this_body->query_weapon()->query_weapon_class()) + 1);
         }
         else
         {
            this_body->targetted_action("$N $vtry to stab $t in the back, and $vfail.\n", living);
         }

         if (!living->is_body() && (random(living->query_per() + 1) > random(100)))
         {
            living->attacked_by(this_body, 1);
         }
      }
   }
}

mixed can_backstab_liv()
{
   object this_body = this_body();

   if (this_body->query_guild_level("assassin"))
   {
      if (!this_body->has_learned_skill("backstab"))
      {
         return "You have not learned how to backstab someone.\n";
      }
      else if (this_body->get_target())
      {
         return "You are unable to backstab when you're already in combat.\n";
      }
      else if (this_body->has_skill_delay())
      {
         return "You are too busy to concentrate on backstabbing someone.\n";
      }
   }
   else
   {
      return "Only assassins know how to backstab someone.\n";
   }

   return 1;
}

void do_backstab()
{
   write("Backstab who?\n");
}

void backstab(object body)
{
   object this_body = this_body();
   int level = this_body->query_guild_level("assassin");
   int rank = this_body->query_skill("backstab") / 100;

   foreach (object weapon in this_body->query_weapons())
   {
      int extra_damage = (random(6) + 1) * ((rank * 5) + level) * weapon->query_weapon_class() / 600;

      if (extra_damage > (level * 3))
      {
         extra_damage = level * 3;
      }
      else if (extra_damage < (rank * 3))
      {
         extra_damage = rank * 3;
      }

      this_body->targetted_action(weapon->query_backstab_message() + " (" + extra_damage + ")", body, weapon);

      this_body->add_event(body, weapon, "torso", ([ "unstoppable" : weapon->query_weapon_class() + extra_damage ]), this_body);
   }

   this_body->start_fight(body);

   if (!body->is_body())
   {
      body->backstabbed_by(this_body);
   }
}

void create()
{
   add_rules( ({ "", "LIV" }) );
}