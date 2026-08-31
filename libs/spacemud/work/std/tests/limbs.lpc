/* Do not remove the headers from this file! see /USAGE for more info. */

inherit M_TEST_SUITE;
object troll;

int clone_actors()
{
   troll = lab_clone("/domains/std/monster/troll");
   if (!troll)
   {
      debug("Failed to clone troll");
      return 0;
   }
   destruct(present("sword", troll));
   return 1;
}

int clone_items()
{
   return std_clone_move(troll, ({"weapon/greataxe", "weapon/longsword", "armour/gloves", "armour/leather_jacket",
                                  "armour/kevlar_vest"}));
}

int check_wield(string w)
{
   return inv_do(troll, "wield", w, "query_wielding", 0);
}

int check_wear(string w)
{
   return inv_do(troll, "wear", w, "ob_state", 0);
}

int check_remove(string w)
{
   return inv_do(troll, "remove", w, "ob_state", 1);
}

int check_unwield(string w)
{
   return inv_do(troll, "unwield", w, "query_wielding", 1);
}

int check_dualwield(string w)
{
   object ob;
   cmd(troll, "dualwield " + w);
   ob = present(w, troll);
   if (!ob || sizeof(ob->query_wielding()) != 2)
   {
      debug("Failed to wield " + w);
      return 0;
   }
   return 1;
}

int check_remove_all()
{
   object *obs = all_inventory(troll);
   cmd(troll, "remove all");
   foreach (object ob in obs)
   {
      // Something is worn
      if (ob && ob->is_armour() && ob->ob_state())
         return 0;
   }
   return 1;
}

int check_unwield_all()
{
   object *obs = all_inventory(troll);
   cmd(troll, "unwield all");
   foreach (object ob in obs)
   {
      // Something is wielded
      if (ob && ob->is_weapon() && ob->query_wielding())
         return 0;
   }
   return 1;
}

int clean_up()
{
   destruct(troll);
   return 1;
}

void init_tests()
{
   add_test_true("Clone actor to lab", ( : clone_actors:));
   add_test_true("Clone 5 pieces of equipment", ( : clone_items:));
   add_test_true("Wield longsword", ( : check_wield, "longsword" :));
   add_test_fail("Wield greataxe", ( : check_wield, "axe" :));
   add_test_true("Unwield longsword", ( : check_unwield, "sword" :));
   add_test_true("Dualwield longsword", ( : check_dualwield, "longsword" :));
   add_test_true("Unwield longsword", ( : check_unwield, "sword" :));
   add_test_true("Dualwield greataxe", ( : check_dualwield, "axe" :));
   add_test_fail("Wield longsword", ( : check_wield, "longsword" :));
   add_test_true("Dualwield greataxe", ( : check_dualwield, "axe" :));
   add_test_true("Unwield all", ( : check_unwield_all:));
   add_test_true("Wear gloves", ( : check_wear, "gloves" :));
   add_test_true("Wear jacket", ( : check_wear, "jacket" :));
   add_test_true("Wear vest", ( : check_wear, "vest" :));
   add_test_true("Remove all", ( : check_remove_all:));
   add_test_true("Clean up", ( : clean_up:));
}