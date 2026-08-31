/* Do not remove the headers from this file! see /USAGE for more info. */

inherit LIVING;
inherit M_VENDOR;

void setup()
{
   set_name("Hugo");
   add_id("shopkeeper");
   set_gender(1);
   set_proper_name("Hugo the Weapon Dealer");
   set_in_room_desc("Hugo the Weapon Dealer");
   set_long("The ammo dealer looks to be a rugged and intimidating figure, dressed in a combination of"
            "futuristic armour and utilitarian clothing. Despite his rough exterior, the dealer is a shrewd"
            "businessman, always willing to negotiate prices and barter for valuable goods. He has a"
            "reputation for acquiring rare and powerful weapons from across the galaxy, and"
            "his clientele ranged from military commanders to bounty hunters to rebels fighting against oppressive regimes.\n");

   /* Determines what type of currency we'll use */
   set_currency_type("credits");

   /* Tells vendor we will sell things */
   set_for_sale(1);

   /* Tells vendor we will buy things */
   set_will_buy(1);

   /* itemization of what we sell initially
      filename : #
      if # is set to -1, it will sell an infinite # of that item
   */
   // set_sell(([__DIR__ "apple":-1, "^std/weapon/sword":3, __DIR__ "ale":-1, ]));

   /* We would set this so that the vendor stores weaps/armour in a storage
      room.  See help on set_unique_inventory.  storage.c in the rooms subdir has
      been set up to work.
       set_unique_inventory(__DIR__ "rooms/storage");
   */

   /* We would set this if we wanted EVERYTHING to be stored in a storage
      room.
       set_all_unique(1);
   */
}
