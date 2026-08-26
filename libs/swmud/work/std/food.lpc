/* Do not remove the headers from this file! see /USAGE for more info. */

inherit OBJ;
inherit M_EDIBLE;
inherit M_GETTABLE;
inherit M_HEALING;

#define XP_PER_RARITY_PT 10

void mudlib_setup()
{
   object::mudlib_setup();
   m_edible::mudlib_setup();
}

int query_value()
{
   float heal_mod = 1;
   if (this_object()->get_original_eats() != this_object()->query_num_eats())
      return 0;
   if (this_object()->decay_begun())
      return 0;

   // 35% discount on decayable items.
   if (this_object()->decays())
      heal_mod = 0.65;

   return to_int((float)query_num_eats() * query_heal_value() * heal_mod);
}

mixed direct_eat_obj(object ob)
{
   return m_edible::direct_eat_obj(ob);
}

int is_food()
{
   return 1;
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

string get_extra_long()
{
   switch ((100 * get_num_eats()) / get_original_eats())
   {
   case 1..20:
      return "It is almost finished.";
   case 21..40:
      return "Most of it has been eaten.";
   case 41..60:
      return "It is about half eaten.";
   case 61..70:
      return "It has been partially eaten.";
   case 71..90:
      return "A little of it has been eaten.";
   case 91..99:
      return "It has hardly been touched.";
   case 100:
      return "It is untouched.";
   }
}
