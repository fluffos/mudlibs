/* Do not remove the headers from this file! see /USAGE for more info. */

/*
 * Written 2020-04-17 Tsath
 */

inherit VERB_OB;

void do_craft_str_on_obj(string str, object ob)
{
   if (ob->is_crafting_station())
   {
      return ob->simple_craft(this_body(), str);
   }

   write("Craft on what? Find a crafting station.\n");
}

void do_craft_str(string str)
{
   foreach (object ob in all_inventory(environment(this_body())))
   {
      if (ob->is_crafting_station())
      {
         return do_craft_str_on_obj(str, ob);
      }
   }
   write("To craft something you need to find a crafting station.\n");
}

void do_craft()
{
   // Look for a crafting station and revert to it's bad message for crafting nothing.
   // Just pick the first station we find. Normally, there are not two in the same place.
   foreach (object ob in all_inventory(environment(this_body())))
   {
      if (ob->is_crafting_station())
      {
         this_body()->do_game_command("look at station");
         return;
      }
   }
   write("To craft you need to find a crafting station.\n");
}

void create()
{
   add_rules(({"STR on OBJ", "STR", ""}), ({}));
}
