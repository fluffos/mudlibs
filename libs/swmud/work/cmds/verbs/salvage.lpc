/* Do not remove the headers from this file! see /USAGE for more info. */

inherit VERB_OB;

mixed direct_salvage_obj(object ob)
{
   return 1;
}

string some(int n)
{
   switch (n)
   {
   case 0:
      return "no items";
   case 1:
      return "an item";
   case 2:
      return "two items";
   case 3..5:
      return "a few items";
   default:
      return "a lot of items";
   }
}

void do_salvage_obj(object ob)
{
   if (!ob->is_salvageable())
   {
      printf("The %s is not salvageable.\n", ob->short());
      return;
   }

   CRAFTING_D->salvage_obj(ob);
   this_body()->other_action("$N $vsalvage materials from something.");
}

void do_salvage_obs(object *obs)
{
   int count = 0;

   foreach (object ob in obs)
   {
      if (environment(ob) != this_body())
         continue;
      if (ob->is_armour() && ob->ob_state())
         continue;
      if (ob->is_weapon() && ob->query_wielded_by() == this_body())
         continue;
      if (ob->is_salvageable() && (ob->is_damaged() || ob->is_pelt() || ob->is_junk()))
      {
         do_salvage_obj(ob);
         count++;
      }
   }
   if (!count)
      write("You find nothing to salvage.\n");
   else
      this_body()->simple_action("$N $vsalvage " + some(count) + " into $p material pouch.");
}

void do_salvage_str_on_obj(string str, object ob)
{
   if (ob->is_crafting_station())
   {
      return ob->simple_salvage(this_body(), str);
   }

   write("Salvage on what? Find a crafting bench.\n");
}

void do_salvage_str(string str)
{
   foreach (object ob in all_inventory(environment(this_body())))
   {
      if (ob->is_crafting_station())
      {
         return do_salvage_str_on_obj(str, ob);
      }
   }
   write("That cannot be salvaged.\n");
}

void do_salvage()
{
   write("Salvage what?\n");
}

void create()
{
   add_rules(({"", "OBJ", "OBS", "STR on OBJ", "STR"}), ({"scrap"}));
}
