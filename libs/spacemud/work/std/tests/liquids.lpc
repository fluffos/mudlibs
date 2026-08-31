/* Do not remove the headers from this file! see /USAGE for more info. */

inherit M_TEST_SUITE;
object troll, keg;

int clone_actors()
{
   troll = lab_clone("/domains/std/monster/troll");
   keg = lab_clone("/domains/std/keg");
   if (!troll)
   {
      debug("Failed to clone troll and keg");
      return 0;
   }
   return 1;
}

int clone_items()
{
   return std_clone_move(troll, ({"bottle"}));
}

int check_bottle_empty()
{
   return sizeof(all_inventory(present("bottle", troll))) == 0;
}

int check_fill_bottle()
{
   cmd(troll, "fill bottle from keg");
   return 1;
}

int check_bottle_full()
{
   return present("ale", present("bottle", troll))->query_num_drinks() == 10;
}

int check_drink_fluid()
{
   for (int i = 1; i < 11; i++)
   {
      cmd(troll, "drink from bottle");
      if (i < 10 && present("ale", present("bottle", troll))->query_num_drinks() + i != 10)
         return 0;
   }
   return check_bottle_empty();
}

int clean_up()
{
   destruct(troll);
   destruct(keg);
   return 1;
}

void init_tests()
{
   add_test_true("Clone actor to lab", ( : clone_actors:));
   add_test_true("Clone liquid personal items", ( : clone_items:));
   add_test_true("Check bottle is empty", ( : check_bottle_empty:));
   add_test_true("Check fill bottle", ( : check_fill_bottle:));
   add_test_true("Check bottle has 10 drinks", ( : check_bottle_full:));
   add_test_true("Drink 10 drinks", ( : check_drink_fluid:));
   add_test_true("Clean up", ( : clean_up:));
}