inherit VERB_OB;

void compare(object thing1, object thing2);

void do_compare_obj_to_obj(object thing1, object thing2)
{
   object this_body = this_body();

   this_body->add_skill_delay(2);

   if (this_body->test_skill("compare", 200 + ((this_body->query_guild_level("smuggler") + this_body->query_guild_level("merchant")) * 10)))
   {
      compare(thing1, thing2);
   }
   else
   {
      this_body->simple_action("$N $vfail to compare $o to $o1.", thing1, thing2);
   }
}

void compare(object thing1, object thing2)
{
   object this_body = this_body();
   int level = this_body->query_guild_level("smuggler") + this_body->query_guild_level("merchant");
   int rank = this_body->query_skill("compare") / 100;
   int smuggler_spec = this_body->query_guild_specialization_rank("smuggler", "something");
   int merchant_spec = this_body->query_guild_specialization_rank("merchant", "something");
   int smuggler_rank_spec;
   int merchant_rank_spec;

   smuggler_rank_spec = (rank + smuggler_spec) < 0 ? 0 : (rank + smuggler_spec);
   merchant_rank_spec = (rank + merchant_spec) < 0 ? 0 : (rank + merchant_spec);

   if (this_body->query_guild_level("smuggler"))
   {
      if (thing1->is_weapon() && thing2->is_weapon())
      {
         switch ((thing1->query_weapon_class() - thing2->query_weapon_class()) * (level + smuggler_rank_spec) / 100)
         {
            case -1000..-5: write(capitalize(thing1->the_short()) + " appears to have much less damage potential than " + thing2->the_short() + ".\n"); break;
            case -4..-2: write(capitalize(thing1->the_short()) + " appears to have less damage potential than " + thing2->the_short() + ".\n"); break;
            case -1: write(capitalize(thing1->the_short()) + " appears to have slightly less damage potential than " + thing2->the_short() + ".\n"); break;
            case 0: write("Their damage potential appears to be equal.\n"); break;
            case 1: write(capitalize(thing1->the_short()) + " appears to have slightly greater damage potential than " + thing2->the_short() + ".\n"); break;
            case 2..4: write(capitalize(thing1->the_short()) + " appears to have greater damage potential than " + thing2->the_short() + ".\n"); break;
            case 5..1000: write(capitalize(thing1->the_short()) + " appears to have much greater damage potential than " + thing2->the_short() + ".\n"); break;
         }
      }

      if (thing1->is_armor() && thing2->is_armor())
      {
         switch ((thing1->query_armor_class() - thing2->query_armor_class()) * (level + smuggler_rank_spec) / 100)
         {
            case -1000..-5: write(capitalize(thing1->the_short()) + " appears to offer much less protection than " + thing2->the_short() + ".\n"); break;
            case -4..-2: write(capitalize(thing1->the_short()) + " appears to offer less protection than " + thing2->the_short() + ".\n"); break;
            case -1: write(capitalize(thing1->the_short()) + " appears to offer slightly less protection than " + thing2->the_short() + ".\n"); break;
            case 0: write("They appear to offer the same ammount of protection.\n"); break;
            case 1: write(capitalize(thing1->the_short()) + " appears to offer slightly greater protection than " + thing2->the_short() + ".\n"); break;
            case 2..4: write(capitalize(thing1->the_short()) + " appears to offer greater protection than " + thing2->the_short() + ".\n"); break;
            case 5..1000: write(capitalize(thing1->the_short()) + " appears to offer much greater protection than " + thing2->the_short() + ".\n"); break;
         }
      }

      if (thing1->query_max_durability() && thing2->query_max_durability())
      {
         switch ((thing1->query_max_durability() - thing2->query_max_durability()) * (level + smuggler_rank_spec) / 100)
         {
            case -1000..-5: write(capitalize(thing1->the_short()) + " appears to be much less durable than " + thing2->the_short() + ".\n"); break;
            case -4..-2: write(capitalize(thing1->the_short()) + " appears to be less durable than " + thing2->the_short() + ".\n"); break;
            case -1: write(capitalize(thing1->the_short()) + " appears to be slightly less durable than " + thing2->the_short() + ".\n"); break;
            case 0: write("Their durability appears to be equal.\n"); break;
            case 1: write(capitalize(thing1->the_short()) + " appears to be slightly more durable than " + thing2->the_short() + ".\n"); break;
            case 2..4: write(capitalize(thing1->the_short()) + " appears to be more durable than " + thing2->the_short() + ".\n"); break;
            case 5..1000: write(capitalize(thing1->the_short()) + " appears to be much more durable than " + thing2->the_short() + ".\n"); break;
         }
      }
   }

   if (this_body->query_guild_level("merchant"))
   {
      switch (to_int(((thing1->query_weight() * 100) - (thing2->query_weight() * 100)) * (level + merchant_rank_spec) / 100))
      {
         case -100000..-500: write(capitalize(thing1->the_short()) + " appears to weigh much less than " + thing2->the_short() + ".\n"); break;
         case -400..-200: write(capitalize(thing1->the_short()) + " appears to weigh less than " + thing2->the_short() + ".\n"); break;
         case -100..-1: write(capitalize(thing1->the_short()) + " appears to weigh slightly less than " + thing2->the_short() + ".\n"); break;
         case 0: write("They appear to have about the same weight.\n"); break;
         case 1..100: write(capitalize(thing1->the_short()) + " appears to weigh slightly more than " + thing2->the_short() + ".\n"); break;
         case 200..400: write(capitalize(thing1->the_short()) + " appears to weigh more than " + thing2->the_short() + ".\n"); break;
         case 500..100000: write(capitalize(thing1->the_short()) + " appears to weigh much more than " + thing2->the_short() + ".\n"); break;
      }

      switch ((thing1->query_value() - thing2->query_value()) * (level + merchant_rank_spec) / 100)
      {
         case -10000000..-500: write(capitalize(thing1->the_short()) + " appears to be much less valuable than " + thing2->the_short() + ".\n"); break;
         case -400..-200: write(capitalize(thing1->the_short()) + " appears to be less valuable than " + thing2->the_short() + ".\n"); break;
         case -100..-1: write(capitalize(thing1->the_short()) + " appears to be slightly less valuable than " + thing2->the_short() + ".\n"); break;
         case 0: write("They appear to have the same value.\n"); break;
         case 1..100: write(capitalize(thing1->the_short()) + " appears to be slightly more valuable than " + thing2->the_short() + ".\n"); break;
         case 200..400: write(capitalize(thing1->the_short()) + " appears to be more valuable than " + thing2->the_short() + ".\n"); break;
         case 500..10000000: write(capitalize(thing1->the_short()) + " appears to be much more valuable than " + thing2->the_short() + ".\n"); break;
      }

      if (thing1->is_container() && thing2->is_container() && !thing1->is_holster() && !thing2->is_holster())
      {
         switch ((thing1->query_capacity() - thing2->query_capacity()) * (level + merchant_rank_spec) / 100)
         {
            case -1000..-50: write(capitalize(thing1->the_short()) + " appears to have much less carry capacity than " + thing2->the_short() + ".\n"); break;
            case -49..-25: write(capitalize(thing1->the_short()) + " appears to have less carry capacity than " + thing2->the_short() + ".\n"); break;
            case -24..-1: write(capitalize(thing1->the_short()) + " appears to have slightly less carry capacity than " + thing2->the_short() + ".\n"); break;
            case 0: write("They appear to have the same carry capacity.\n"); break;
            case 1..24: write(capitalize(thing1->the_short()) + " appears to have slightly more carry capacity than " + thing2->the_short() + ".\n"); break;
            case 25..49: write(capitalize(thing1->the_short()) + " appears to have more carry capacity than " + thing2->the_short() + ".\n"); break;
            case 50..1000: write(capitalize(thing1->the_short()) + " appears to have much more carry capacity than " + thing2->the_short() + ".\n"); break;
         }
      }
   }

   this_body->other_action("$N $vcompare $o to $o1.", thing1, thing2);
}

void do_compare()
{
   write("Compare what to what?\n");
}

mixed can_compare_obj_to_obj()
{
   object this_body = this_body();

   if (this_body->query_guild_level("smuggler") || this_body->query_guild_level("merchant"))
   {
      if (!this_body->has_learned_skill("comparing"))
      {
         return "You have not learned how to compare things.\n";
      }
      else if (this_body->get_target())
      {
         return "You are unable to compare things while in combat.\n";
      }
      else if (this_body->has_skill_delay())
      {
         return "You are too busy to concentrate on comparing things.\n";
      }
   }
   else
   {
      return "Only smugglers and merchants know how to compare things.\n";
   }

   return 1;
}

void create()
{
   add_rules( ({ "", "OBJ to OBJ" }) );
}