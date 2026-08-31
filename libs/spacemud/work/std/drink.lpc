
inherit OBJ;
inherit M_GETTABLE;
inherit M_DRINK_CONTAINER;
inherit M_DRINKABLE;
inherit M_HEALING;

#define XP_PER_RARITY_PT 10

int alchohol_level;

//: FUINCTION set_alchohol_level
// Set the alchohol level in the drink. A number between
// 0 to 100% alchohol. The higher the % the more intoxicated
// the drinker will be.
void set_alchohol_level(int al)
{
   alchohol_level = clamp(al, 0, 100);
}

//: FUNCTION query_alchohol_level
// Return the alchohol level of the beverage between 0 and 100.
int query_alchohol_level()
{
   return alchohol_level;
}

void set_heal_value(int v)
{
   set_alchohol_level(v);
   ::set_heal_value(v);
}

mixed direct_drink_obj(object ob)
{
   return m_drinkable::direct_drink_obj(ob);
}

int query_value()
{
   // Alcholic drinks are cheaper than water, and heal more, yeah sad sad world.
   int heal_mod = query_alchohol_level() ? 0.5 : 1;
   if (this_object()->decays())
      return 0;
   return to_int((float)query_num_drinks() * query_heal_value() * heal_mod);
}

int is_drink()
{
   return 1;
}

string get_extra_long()
{
   int drink_level = to_int(100 * (1.0 * query_num_drinks() + query_drinks_current_unit()) / query_num_drinks());

   switch (drink_level)
   {
   case 0..20:
      return "It is almost finished.";
   case 21..40:
      return "Most of it has been finished.";
   case 41..60:
      return "It is about half consumed.";
   case 61..70:
      return "It has been partially consumed.";
   case 71..90:
      return "A little of it has been consumed.";
   case 91..99:
      return "It has hardly been touched.";
   case 100:
      return "It is untouched.";
   }
}

void alchohol_drink_action()
{
   if (query_alchohol_level())
      this_body()->drink_alchohol(1 + random(alchohol_level));
}

int crafting_xp()
{
   mapping recipe = this_object()->query_recipe();
   int xp = 0;

   if (!recipe)
      return 0;

   foreach (string mat, int c in recipe)
   {
      xp += CRAFTING_D->query_rarity(mat) * XP_PER_RARITY_PT * c;
   }
   return xp;
}

void mudlib_setup()
{
   object::mudlib_setup();
   set_id("bottle");
   set_num_drinks(5);
   set_heal_value(2);
   set_weight(1);
   set_taste_action(( : alchohol_drink_action:));
   set_needs_contents(0);
   set_drink_action("$N $vtake a swig from the bottle.");
   set_last_drink_action("$N $vtake a drink, finishing the bottle off.");
}
