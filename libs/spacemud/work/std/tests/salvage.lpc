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
   return 1;
}

int check_unwield(string w)
{
   return inv_do(troll, "unwield", w, "query_wielding", 1);
}

int check_salvage(string w)
{
   return inv_do(troll, "salvage", w, "gone", 0);
}

int clean_up()
{
   destruct(troll);
   return 1;
}

void init_tests()
{
   add_test_true("Clone actor to lab", ( : clone_actors:));
   add_test_fail("Fail to salvage sword while wielded", ( : check_salvage, "sword" :));
   add_test_true("Unwield sword", ( : check_unwield, "sword" :));
   add_test_true("Salvage sword", ( : check_salvage, "sword" :));
   add_test_true("Clean up", ( : clean_up:));
}