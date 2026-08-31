/* Do not remove the headers from this file! see /USAGE for more info. */

inherit MATERIAL_SPAWNER;

void mudlib_setup(string loot)
{
   set_id("dirt", "dirt pile", "pile of dirt", "pile");
   add_adj("large");
   set_long("There is enough dirt to hide something in it.");
   set_material_file(loot ? loot : "/domains/std/junk/barox_cleaner");
   set_success_action("$N $vsearch all the trash and sludge. $N $vfind <item>.");
   set_fail_action("$N $vfail to find anything else of use.");
   set_search_string("searching the dirt pile");
   set_attached(1);
}

// Do not
int state_update()
{
   return 0;
}