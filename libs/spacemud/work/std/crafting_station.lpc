/* Do not remove the headers from this file! see /USAGE for more info. */

/* A basic piece of furniture.  This one happens to be a bed (go figure).
 * It also has an example of a use of add_method, as this really is a complex
 * exit. */
inherit FURNITURE;
inherit M_CRAFTING;

#undef CAN_UPGRADE_DOWNGRADE

void mudlib_setup()
{
   ::mudlib_setup();
   set_id("crafting station", "station");
   set_in_room_desc("A crafting station is positioned against the wall");
   add_relation("under", LARGE);
   set_default_relation("under");
   set_long((this_object()->get_station_description() + "\n\n" || "") + "This is " + a_short() +
            " that allows you to craft items from materials you find. Materials are all in your "
            "components ('materials'), and can be gained by salvaging items you "
            "find (salvaging items do not require " +
            a_short() +
#ifndef CAN_UPGRADE_DOWNGRADE
            ").\n\n");
#endif
#ifdef CAN_UPGRADE_DOWNGRADE
           ").\n\n"
           "%^YELLOW%^Upgrade components in your pouch by:%^RESET%^\n"
           "\tcraft 2 nylon scrap\n"
           "\tcraft metal fragment\n"
           "%^YELLOW%^Salvage components in your pouch by:%^RESET%^\n"
           "\tsalvage waste acid\n"
           "\tsalvage 4 nylon scrap\n"
           "\tsalvage crowbar (does not require a bench)\n"
           "\tsalvage all (see 'help equip')\n"
           "\n");
#endif
           set_max_capacity(LARGE, "under");
           /* This probably isn't a very good capacity for under */
           add_method("crawl under", this_object(), ( : enter_check:), ({"$N $vcrawl under the crafting station."}));
}
