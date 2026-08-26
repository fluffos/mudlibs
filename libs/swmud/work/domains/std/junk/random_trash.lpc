/* Do not remove the headers from this file! see /USAGE for more info. */

inherit MATERIAL_SPAWNER;

object *receivers = ({});

string *search_list = ({
    "^std/junk/aluminum_can",
    "^std/junk/anti_freeze_bottle",
    "^std/junk/baseball",
    "^std/junk/battered_clipboard",
    "^std/junk/cinder_block",
    "^std/junk/light_bulb",
    "^std/junk/screwdriver",
    "^std/junk/mop",
    "^std/junk/turpentine_can",
    "^std/junk/wood_bucket",
});

void setup()
{
   string my_junk = choice(search_list);
   ::mudlib_setup();
   set_attached(0);
   set_in_room_desc("A large pile of trash.");
   set_id("trash", "sludge", "slime");
   set_adj("a pile");
   set_long("The trash seems to be various broken items. Perhaps you can find something useful if you search it?");
   set_material_files(search_list);
   set_success_action("$N $vsearch through the trash and sludge. $N $vfind <item>.");
   set_fail_action("$N $vfail to find any more usuable items right now.");
   set_search_string("searching through the sludge and trash.");
}

int yield()
{
   return 1;
}