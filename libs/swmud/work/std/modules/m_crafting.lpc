/* Do not remove the headers from this file! see /USAGE for more info. */

inherit M_INPUT; // We use modal_simple() from here.

//: MODULE
// This module handles most of the crafting functionality.

#define CRAFT_COST 5
#define MAT_SALVAGE_COST 5
#define MAT_CRAFT_COST 1
#define CAN_UPGRADE_DOWNGRADE

// Words we shouldn't strip "es" from from the CRAFTING_D material names.
#define ESSE_EXCEPTIONS ({"squares"})

int craft_item(object body, string what);

private
string recipe_list;
private
mixed craft_currency_type = DOMAIN_D->query_currency();
private
mapping special_mats;
private
string station_filter;

string get_extra_long()
{
   return recipe_list ? recipe_list : "This station has no extra features.";
}

int is_crafting_station()
{
   return 1;
}

int simple_craft(object body, string what)
{
   string *parts = explode(what, " ");
   string category;
   string material;
   mapping money;
   object employee = present("employee", environment(body));
   int exchange_rate = MONEY_D->query_exchange_rate(craft_currency_type);
   int number = 1;
   int challenge_rating = 10;

   if (CRAFTING_D->valid_crafting_recipe(what))
   {
      if (member_array(what, keys(CRAFTING_D->query_crafting_recipes(station_filter))) == -1)
      {
         tell(body, "You cannot craft '" + what + "' at this station, sorry.\n");
         return;
      }

      return craft_item(body, what);
   }

#ifndef CAN_UPGRADE_DOWNGRADE
   tell(body, "Craft what? Better look at the station again.\n");
   return;
#endif

   // bad arguments
   if (sizeof(parts) < 2)
   {
      tell(body, "Craft what? Better look at the station again.\n");
      return;
   }

   // Do some number parsing
   if (sizeof(parts) == 3)
   {
      if (parts[0] == "a" || parts[0] == "an" || parts[0] == "one")
         parts[0] = "1";
      number = to_int(parts[0]);
      if (!number)
      {
         tell(body, "Craft how many? Better look at the station again.\n");
         return;
      }
      parts = parts[1..2];
   }

   if (parts[1][ < 1] == 's')
      parts[1] = parts[1][0.. < 2];

   if (!CRAFTING_D->valid_material(parts[0] + " " + parts[1]))
   {
      tell(body, "Craft " + parts[0] + " " + parts[1] + "? You don't know how to do that.\n");
      return;
   }

   material = parts[0] + " " + parts[1];
   category = CRAFTING_D->material_category(material);

   // We have a valid number, category and material, hooray! \o/
   if (!CRAFTING_D->material_below(category, material))
   {
      tell(body, sprintf("They are too small to craft, but perhaps you can get some by salvaging %s?\n",
                         CRAFTING_D->material_above(category, material)));
      return;
   }

   if (MAT_CRAFT_COST > this_body()->query_amt_currency(craft_currency_type))
   {
      printf("Sorry, that costs %s, which you don't have!\n",
             MONEY_D->currency_to_string(MAT_CRAFT_COST, craft_currency_type));
      return;
   }

   if (!body->remove_material(CRAFTING_D->material_below(category, material), (number * 10)))
   {
      tell(body, sprintf("Crafting that, requires %d %s which you do not have.\n", number * 10,
                         pluralize(CRAFTING_D->material_below(category, material))));
      return;
   }

   // We have the materials and the money now! Hooray again! \o/

   money = MONEY_D->handle_subtract_money(this_body(), MAT_CRAFT_COST, craft_currency_type);
   body->add_material(material, number);
   body->my_action("$N $vpay to craft a $o for " + MONEY_D->currency_to_string(MAT_CRAFT_COST, craft_currency_type) +
                       ". You give " + MONEY_D->currency_to_string(money[0], craft_currency_type) + 
                       (sizeof(money[1])
                            ? " and get " + MONEY_D->currency_to_string(money[1], craft_currency_type) + " as change"
                            : "") +
                       ".\n",
                   "" + number + " " + material, this_object());

   challenge_rating += challenge_rating + (number * (member_array(material, CRAFTING_D->query_materials(category))));

   if (body->test_skill("misc/crafting/" + station_filter, challenge_rating))
   {
      tell(body, "You get a few materials back because you did well crafting.\n");
      body->add_material(CRAFTING_D->material_below(category, material), random((number * 5)) + number);
   }
}

int simple_salvage(object body, string what)
{
   string *parts = explode(what, " ");
   string category;
   string material;
   mapping money;
   object employee = present("employee", environment(body));
   int number = 1;
   int challenge_rating = 10;

   TBUG(what);

   // bad arguments
   if (sizeof(parts) < 2)
   {
      tell(body, "Salvage what? Better look at the station again.\n");
      return 0;
   }

#ifndef CAN_UPGRADE_DOWNGRADE
   tell(body, "Salvage what? Better look at the station again.\n");
   return 0;
#endif

#ifdef 0
   // No crafting without a employee
   if (!employee || (employee && !employee->is_employee()))
   {
      tell(body, "Better not use the station without an employee present?\n");
      return;
   }
#endif

   // Do some number parsing
   if (sizeof(parts) == 3)
   {
      if (parts[0] == "a" || parts[0] == "an" || parts[0] == "one")
         parts[0] = "1";
      number = to_int(parts[0]);
      if (!number)
      {
         tell(body, "Salvage how many? Better look at the station again.");
         return;
      }
      parts = parts[1..2];
   }

   if (parts[1][ < 2..] == "es" && member_array(parts[1], ESSE_EXCEPTIONS) == -1)
      parts[1] = parts[1][0.. < 3];
   if (parts[1][ < 1] == 's')
      parts[1] = parts[1][0.. < 2];

   if (!CRAFTING_D->valid_material(parts[0] + " " + parts[1]))
   {
      tell(body, "Salvage " + parts[0] + " " + parts[1] + "? You don't know how to do that.\n");
      return;
   }

   material = parts[0] + " " + parts[1];
   category = CRAFTING_D->material_category(material);

   if (!CRAFTING_D->material_below(category, material))
   {
      tell(body, "The " + material + " cannot be salvaged further.\n");
      return;
   }

   // We have a valid number, category and material, hooray! \o/

   if (MAT_SALVAGE_COST > this_body()->query_amt_currency(craft_currency_type))
   {
      printf("Sorry, that costs %s to salvage, which you don't have!\n",
             MONEY_D->currency_to_string(MAT_SALVAGE_COST, craft_currency_type));
      return;
   }

   if (!body->remove_material(material, number))
   {
      tell(body, sprintf("Crafting that, requires %d %s which you do not have.\n", number,
                         pluralize(category + " " + material)));
      return;
   }

   // We have the materials and the money now! Hooray again! \o/

   money = MONEY_D->handle_subtract_money(this_body(), MAT_SALVAGE_COST, craft_currency_type);
   body->add_material(CRAFTING_D->material_below(category, material), number * 10);
   body->my_action(
       "$N $vpay to salvage a $o for " + MONEY_D->currency_to_string(MAT_SALVAGE_COST, craft_currency_type) +
           ". You give " + MONEY_D->currency_to_string(money[0], craft_currency_type) +
           (sizeof(money[1]) ? " and get " + MONEY_D->currency_to_string(money[1], craft_currency_type) + " as change"
                             : "") +
           ".\n",
       "" + number + " " + category + " " + material, this_object(), employee);

   challenge_rating += challenge_rating + (number * (member_array(material, CRAFTING_D->query_materials(category))));

   if (body->test_skill("misc/crafting/" + station_filter, challenge_rating))
   {
      tell(body, "You get a few materials extra because you did well crafting.\n");
      body->add_material(CRAFTING_D->material_below(category, material), random((number * 5)) + number);
   }
}

int simple_salvage2(object body, string what)
{
   string *parts = explode(what, " ");
   string category;
   string material;
   mapping money;
   object smith = present("smith", environment(body));
   int number = 1;
   int challenge_rating = 10;

   // bad arguments
   if (sizeof(parts) < 2)
   {
      tell(body, "Salvage what? Better look at the bench again.\n");
      return;
   }

   // No crafting without a smith
   if (!smith || (smith && !smith->is_smith()))
   {
      tell(body, "Better not use the bench without the smith present?\n");
      return;
   }

   // Do some number parsing
   if (sizeof(parts) == 3)
   {
      if (parts[0] == "a" || parts[0] == "an" || parts[0] == "one")
         parts[0] = "1";
      number = to_int(parts[0]);
      if (!number)
      {
         tell(body, "Salvage how many? Better look at the bench again.");
         return;
      }
      parts = parts[1..2];
   }

   if (!CRAFTING_D->valid_category(parts[0]))
   {
      tell(body, "Salvage " + parts[0] + "? You don't know how to do that.\n");
      return;
   }
   else
      category = parts[0];

   if (parts[1][ < 2..] == "es" && member_array(parts[1], ESSE_EXCEPTIONS) == -1)
      parts[1] = parts[1][0.. < 3];
   if (parts[1][ < 1] == 's')
      parts[1] = parts[1][0.. < 2];

   if (!CRAFTING_D->valid_material(parts[0] + " " + parts[1]))
   {
      tell(body, "Salvage " + parts[0] + " " + parts[1] + "? You don't know how to do that.\n");
      return;
   }
   else
      material = parts[1];

   if (!CRAFTING_D->material_below(category, material))
   {
      tell(body, "The " + category + " " + material + " cannot be salvaged further.\n");
      return;
   }

   // We have a valid number, category and material, hooray! \o/

   if (MAT_SALVAGE_COST > this_body()->query_amt_currency(craft_currency_type))
   {
      printf("Sorry, that costs %s to salvage, which you don't have!\n",
             MONEY_D->currency_to_string(MAT_SALVAGE_COST, craft_currency_type));
      return;
   }

   if (!body->remove_material(category + " " + material, number))
   {
      tell(body, sprintf("Crafting that, requires %d %s which you do not have.\n", number,
                         pluralize(category + " " + material)));
      return;
   }

   // We have the materials and the money now! Hooray again! \o/

   money = MONEY_D->handle_subtract_money(this_body(), MAT_SALVAGE_COST, craft_currency_type);
   body->add_material(CRAFTING_D->material_below(category, material), number * 10);
   body->my_action(
       "$N $vpay to salvage a $o for " + MONEY_D->currency_to_string(MAT_SALVAGE_COST, craft_currency_type) +
           ". You give " + MONEY_D->currency_to_string(money[0], craft_currency_type) + " to $o2" +
           (sizeof(money[1]) ? " and get " + MONEY_D->currency_to_string(money[1], craft_currency_type) + " as change"
                             : "") +
           ".\n",
       "" + number + " " + category + " " + material, this_object(), smith);

   challenge_rating += challenge_rating + (number * (member_array(material, CRAFTING_D->query_materials(category))));

   if (body->test_skill("misc/crafting", challenge_rating))
   {
      tell(body, "You get a few materials extra because you did well crafting.\n");
      body->add_material(CRAFTING_D->material_below(category, material), random((number * 5)) + number);
   }
}

void craft_item_confirmed(object body, string what, string reply)
{
   mapping recipe;
   int missing = 0;
   mapping money;
   object employee = present("employee", environment(body));

   object craft;

   if (!CRAFTING_D->valid_crafting_recipe(what))
   {
      write("Error while crafting, contact a wizard.\n");
      return;
   }

   if (reply != "y" && reply != "Y")
   {
      write("Craft aborted.\n");
      return;
   }

   if (CRAFT_COST > this_body()->query_amt_currency(craft_currency_type))
   {
      printf("Sorry, that costs %s, which you don't have!\n",
             MONEY_D->currency_to_string(CRAFT_COST, craft_currency_type));
      return;
   }

   // We have the money now! Hooray again! \o/

   money = MONEY_D->handle_subtract_money(this_body(), CRAFT_COST, craft_currency_type);
   this_body()->my_action(
       "$N $vpay to craft a $o for " + MONEY_D->currency_to_string(CRAFT_COST, craft_currency_type) + ". You give " +
           MONEY_D->currency_to_string(money[0], craft_currency_type) + " to $o2" +
           (sizeof(money[1]) ? " and get " + MONEY_D->currency_to_string(money[1], craft_currency_type) + " as change"
                             : "") +
           ".\n",
       what, this_object(), employee);

   recipe = CRAFTING_D->query_crafting_recipe(what);
   foreach (string mat, int amount in recipe)
   {
      if (!body->remove_material(mat, amount))
      {
         TBUG("Failed to remove " + amount + " " + mat);
         missing++;
      }
   }

   if (missing)
      TBUG("Body: " + body + " crafting with missing materials? Count: " + missing);

   craft = CRAFTING_D->create_material(what);

   if (body->test_skill("misc/crafting/" + station_filter, craft->crafting_xp() * 10))
   {
      // Skill check succeeded
   }
   else
   {
      // Skill check failed
   }

   craft->move(body);
   if (craft->crafting_xp())
      body->add_experience(craft->crafting_xp());
   body->simple_action("$N $vcraft $o at the $o1.", add_article(what), this_object());
}

int craft_item(object body, string what)
{
   mapping recipe;
   int missing = 0;
   string missing_mats = "";
   if (!CRAFTING_D->valid_crafting_recipe(what))
   {
      return 0;
   }

   recipe = CRAFTING_D->query_crafting_recipe(what);

   foreach (string mat, int amount in recipe)
   {
      if (amount)
      {
         if (!body->has_material(mat, amount))
         {
            missing_mats += " %^RED%^-%^RESET%^ " + amount + " x " + mat + " (missing)\n";
            missing++;
         }
         else
            missing_mats += " %^GREEN%^+%^RESET%^ " + amount + " x " + mat + " (got it)\n";
      }
   }

   if (missing)
   {
      write("To craft " + what + ", you are missing " + missing + " types of materials:\n");
      write(missing_mats);
      return 0;
   }

   write("You have all materials needed! This craft will consume:\n");
   write(missing_mats);
   write("Craft item - costs " + CRAFT_COST + " " + craft_currency_type + "? (y/N) ");
   modal_simple(( : craft_item_confirmed, body, what:));
}

void setup_recipes(string filter)
{
   string r = "%^YELLOW%^" + capitalize(filter) + " recipes:%^RESET%^\n";
   string *mats;
   mapping recs = CRAFTING_D->query_crafting_recipes(filter);
   special_mats = ([]);
   station_filter = filter;

   foreach (string cat in CRAFTING_D->query_salvage_categories())
   {
      mats = CRAFTING_D->query_materials(cat);
      special_mats[cat] = mats;
   }

   foreach (string name, mapping recipe in recs)
   {
      r += "\tcraft " + name + "\n";
   }
   recipe_list = r;
}
