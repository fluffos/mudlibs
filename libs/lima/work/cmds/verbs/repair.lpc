/* Do not remove the headers from this file! see /USAGE for more info. */

inherit VERB_OB;
inherit M_INPUT;

void do_repair()
{
   write("Repair what with what?\n");
}

private
nomask void repair_with_what(mixed what, string r)
{
   string result;
   object bench = filter_array(all_inventory(environment(this_body())), ( : $1->is_crafting_bench() :));

   r = lower_case(r);

   if (r == "m")
   {
      printf("Repairing using money.\n");
      if (CRAFTING_D->pay_for_repair_with_money(this_body(), what))
         printf("All repaired.\n");
      else
      {
         printf("You didn't have the money?\n");
      }
   }
   else if (r == "r")
   {
      printf("Using materials for repairs.\n");
      if (CRAFTING_D->pay_for_repair(this_body(), what))
         printf("All repaired.\n");
      else
      {
         printf("You were missing parts?\n");
      }
   }
   else
   {
      printf("Aborting.\n");
   }
}

void do_repair_obj_with_obj(object ob, object with)
{
}

void do_repair_obj_str_obj(object ob, string s, object with)
{
   if (s != "using" && s != "with")
   {
      write("Repair what how, sorry?");
      return;
   }
   if (ob->is_living())
   {
      write(capitalize(ob->query_name()) + " seems beyond repair, sorry.\n");
      return;
   }

   if (ob)
      ob->do_repair(with);
}

void do_repair_obj(object ob)
{
   object *tools = ({});
   object tool;

   if (ob->missing_durability())
   {
      mixed *estimate = CRAFTING_D->estimate_with_mats(this_body(), ob);
      write(estimate[1]);
      if (estimate[0])
      {
         write("\t%^MENU_CHOICE%^r%^RESET%^: Use materials to Repair " + ob->short() + "?\n" +
                   "\t%^MENU_CHOICE%^m%^RESET%^: Use only money, " + CRAFTING_D->repair_cost_string(ob) +
                   ", instead?\n" + "\t%^MENU_CHOICE%^Q%^RESET%^: Quit (default)");
         modal_simple(( : repair_with_what, ob:));
      }
      else
      {
         printf("You do not have the funds to repair %s.\n", ob->the_short());
      }
      CRAFTING_D->repair_obj(ob);
      return;
   }

   if (all_inventory(this_body()))
      tools = filter_array(all_inventory(this_body()), ( : $1->is_tool() :));

   if (sizeof(tools))
   {
      tool = choice(tools);
      write("(Using " + tool->the_short() + ")\n");
      do_repair_obj_str_obj(ob, "with", tool);
   }
   else
   {
      if (ob)
         ob->do_repair();
   }
}

void do_repair_obs(object *obs)
{
   object *filtered_obs = ({});
   mixed *estimate;
   float only_money = 0.0;

   foreach (object ob in obs)
   {
      if ((environment(ob) == this_body() && ob->missing_durability()))
      {
         filtered_obs += ({ob});
         only_money += CRAFTING_D->money_to_repair(ob);
      }
   }
   if (!sizeof(filtered_obs))
   {
      write("You find nothing in need of repair.\n");
      return;
   }
   estimate = CRAFTING_D->estimate_with_mats(this_body(), filtered_obs);
   printf(estimate[1]);
   if (estimate[0])
   {
      write("\t%^MENU_CHOICE%^r%^RESET%^: Use materials to Repair?\n"
             "\t%^MENU_CHOICE%^m%^RESET%^: Use only Money, " +
             to_int(only_money) +
             ", instead?\n"
             "\t%^MENU_CHOICE%^Q%^RESET%^: Quit (default)");
      modal_simple(( : repair_with_what, filtered_obs:));
   }
   else
   {
      printf("You do not have the funds to repair the items.\n");
   }
}

void create()
{
   add_rules(({"", "OBJ", "OBS", "OBJ STR OBJ"}), ({"fix", "patch"}));
}
