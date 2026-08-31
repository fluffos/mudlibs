/* Do not remove the headers from this file! see /USAGE for more info. */

/* A basic piece of furniture.  This one happens to be a bed (go figure).
 * It also has an example of a use of add_method, as this really is a complex
 * exit. */
inherit FURNITURE;
inherit M_CRAFTING;

void mudlib_setup()
{
   ::mudlib_setup();
   set_id("crafting bench", "bench");
   set_in_room_desc("A crafting bench is positioned against the wall");
   add_relation("under", LARGE);
   set_default_relation("under");
   set_long("This is " + a_short() +
            " that allows you to create or break "
            "down materials. Materials are all in your "
            "component 'pouch', and can be gained by salvaging items you "
            "find (salvaging items do not require " +
            a_short() +
            "):\n\n"
            "%^YELLOW%^Upgrade components in your pouch by:%^RESET%^\n"
            "\tcraft 2 skin patch\n"
            "\tcraft metal fragment\n"
            "%^YELLOW%^Salvage components in your pouch by:%^RESET%^\n"
            "\tsalvage metal bar\n"
            "\tsalvage 4 metal splinters\n"
            "\tsalvage damaged dagger (does not require a bench)\n"
            "\tsalvage all (see 'help equip')\n"
            "\n");
   set_max_capacity(LARGE, "under");
   /* This probably isn't a very good capacity for under */
   add_method("crawl under", this_object(), ( : enter_check:), ({"$N $vcrawl under the crafting bench."}));
}
