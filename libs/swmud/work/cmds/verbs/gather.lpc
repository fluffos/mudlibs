inherit VERB_OB;

void do_gather_wrd_wrd(string type, string word)
{
   if (word == "seed")
   {
      if (this_body()->query_race() == "ithorian")
      {
         if (environment(this_body())->gather_seed(type))
         {
            int rank = this_body()->query_skill("horticulture") / 100;
            int potency = 20 + (rank * 8);

            if (this_body()->test_skill("horticulture"))
            {
               potency += random(10);
            }
            else
            {
               potency -= random(10);
            }

            if (potency < 10)
            {
               potency = 10;
            }
            else if (potency > 100)
            {
               potency = 100;
            }

            write("You gather " + add_article(type) + " seed, with " + potency + "% potency.\n");
            this_body()->other_action("$N $vgather " + add_article(type) + " seed.");

            load_object("/d/obj/horticulture_seed");
            new("/d/obj/horticulture_seed", type, potency)->move(this_body());

            this_body()->add_experience((this_body()->query_primary_level() > 0) ? (10 * array_sum(this_body()->query_guild_levels())) : 10);

//            environment(this_body())->add_seed(type);
         }
         else
         {
            write("There are no " + type + " seeds here for you to gather.\n");
         }
      }
      else
      {
         write("Only Ithorians know how to gather seeds.\n");
      }
   }
   else
   {
      write("Gather what?\n");
   }
}

void do_gather_wrd(string word)
{
   if (word == "seed")
   {
      if (this_body()->query_race() == "ithorian")
      {
         string type = environment(this_body())->gather_random_seed();

         if (strlen(type) && (type != "none"))
         {
            int rank = this_body()->query_skill("horticulture") / 100;
            int potency = 20 + (rank * 8);

            if (this_body()->test_skill("horticulture"))
            {
               potency += random(10);
            }
            else
            {
               potency -= random(10);
            }

            if (potency < 10)
            {
               potency = 10;
            }
            else if (potency > 100)
            {
               potency = 100;
            }

            write("You gather " + add_article(type) + " seed, with " + potency + "% potency.\n");
            this_body()->other_action("$N $vgather " + add_article(type) + " seed.");

            load_object("/d/obj/horticulture_seed");
            new("/d/obj/horticulture_seed", type, potency)->move(this_body());

            this_body()->add_experience((this_body()->query_primary_level() > 0) ? (10 * this_body()->query_primary_level()) : 10);

//            environment(this_body())->add_seed(type);
         }
         else
         {
            write("There are no seeds here for you to gather.\n");
         }
      }
      else
      {
         write("Only Ithorians know how to gather seeds.\n");
      }
   }
   else
   {
      write("Gather what?\n");
   }
}

mixed can_gather_wrd_wrd()
{
   if (!environment(this_body())->is_garden_here())
   {
      return "There is no garden here.\n";
   }

   return 1;
}

mixed can_gather_wrd()
{
   if (!environment(this_body())->is_garden_here())
   {
      return "There is no garden here.\n";
   }

   return 1;
}

void do_gather()
{
   write("Gather what?\n");
}

void create()
{
   add_rules( ({ "", "WRD", "WRD WRD" }) );
}