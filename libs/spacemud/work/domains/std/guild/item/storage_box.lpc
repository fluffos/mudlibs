/* Do not remove the headers from this file! see /USAGE for more info. */

inherit OBJ;
inherit M_WIDGETS;

string guild;
mapping contrib;

void setup(string g)
{
   set_id("storage box", "storage", "box");
   add_adj("large", "black");
   set_in_room_desc("A large black storage box.");
   guild = g;
}

void add_money(string m, int number)
{
   TBUG("Adding " + number + " " + m);
   GUILD_D->add_material(guild, "dollars", number);
}

void add_materials(string m, int number)
{
   TBUG("Adding " + number + " " + m);
   GUILD_D->add_material(guild, m, number);
   GUILD_D->add_favour(this_body(), guild, number);
}

int can_hold_money()
{
   return 1;
}

int can_hold_materials()
{
   return 1;
}

string long()
{
   string long_desc = "The " + capitalize(guild) + " storage box contains:\n";
   mapping p_materials = GUILD_D->query_materials(guild);
   string *mat_cats = CRAFTING_D->query_material_categories();
   int width = this_user()->query_screen_width() - 7;
   int per_row = width / 20;
   int total = 0;
   int total_types = 0;
   int total_cats = 0;
   int content = 0;
   string divider = simple_divider();

   if (!sizeof(mat_cats))
   {
      return "No materials defined, yet.\n";
   }
   if (!p_materials)
      return "The box is sadly empty right now.\n";

   foreach (string cat in mat_cats)
   {
      total_types += sizeof(CRAFTING_D->query_materials(cat));
   }

   foreach (int c in values(p_materials))
   {
      total += c;
      if (c > 0)
         total_cats++;
   }
   total -= p_materials["dollars"];

   long_desc += divider;
   long_desc += sprintf("%%^CYAN%%^%s%%^RESET%%^ - %d materials in %d out of %d types\n",
                        upper_case(guild) + " STORAGE", total, total_cats, total_types);
   long_desc += divider;
   foreach (string category in mat_cats)
   {
      mapping mats = CRAFTING_D->query_materials(category);
      int line = 0;
      int count = 0;
      string mat_line = "";
      foreach (string mat in mats)
      {
         if (member_array(mat, keys(p_materials)) != -1)
            count++;
         if (p_materials[mat] > 0)
         {
            mat_line += sprintf("%15s: %-4d ", capitalize(mat), p_materials[mat]);
            line++;
         }

         if (line == per_row)
         {
            mat_line += "\n";
            line = 0;
         }
      }
      if (line != 0)
         mat_line += "\n";
      if (count)
      {
         // printf("%%^CYAN%%^%-7s%%^RESET%%^ [%d/%d]\n", capitalize(category), count, sizeof(mats));
         long_desc += sprintf("%%^CYAN%%^%s%%^RESET%%^\n", capitalize(pluralize(category)));
         long_desc += sprintf(mat_line + "\n");
         content = 1;
      }
   }
   long_desc += divider;
   long_desc += "Money in storage: $" + p_materials["dollars"] + "\n\n";

   return long_desc;
}

mixed direct_put_wrd_str_in_obj(string wrd, string str, object ob)
{
   return 1;
}

mixed direct_put_wrd_str_into_obj(string wrd, string str, object ob)
{
   return 1;
}