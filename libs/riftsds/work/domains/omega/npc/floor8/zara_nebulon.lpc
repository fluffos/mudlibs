/* Do not remove the headers from this file! see /USAGE for more info. */

inherit LIVING;
inherit M_ACTIONS;
inherit M_VENDOR;

string query_hint(int level)
{
   if (level < 5)
      return "The VDU sold by Zara Nebulon is quite important to space travellers. Buy one when you can afford it.";
}

void add_inventory()
{
   add_sell("^common/item/vdu", -1);
   add_sell("^omega/armour/sneakers",5);
   add_sell("^std/consumable/pain_killers", -1);
}

void setup()
{
   set_gender(2);
   set_name("Zara Nebulon");
   add_id("zara", "zara nebulon", "employee");
   set_proper_name("Zara");
   set_in_room_desc("Zara Nebulon, a woman with neon-colored hair that seems to defy gravity.");
   set_long("Zara's attire, a mix of futuristic fashion and retro space-themed accessories, includes a pair of "
            "levitating sneakers that she insists are the latest trend in zero-gravity chic.");
   set_for_sale(1);
   set_will_buy(0);
   add_inventory();

   set_actions(
       120,
       ({"say Greetings, cosmic wanderer! Ready to upgrade your space swag with the latest and greatest in wearable "
         "wonders?",
         "say Step right up and behold the wonders of the universe! Our gadgets are so cool, even black holes envy "
         "them!",
         "say Looking for a device that can translate alien languages? You're in luck; our Universal Babble Blaster is "
         "on "
         "sale!",
         "say Space fashion tip: A well-equipped explorer is always a well-accessorized one. Trust me, I'm practically "
         "a "
         "space style guru!",
         "say Need a gadget for those moments when you accidentally float away? Try our GravityGrip Gloves – they're "
         "like "
         "velcro for space!",
         "say Our levitating sneakers aren't just for show. They're scientifically proven to reduce tripping by 99.9% "
         "in "
         "any gravitational field!",
         "say Why settle for a regular wristwatch when you can have a Time-Warp Chronometer? It not only tells time "
         "but "
         "predicts your next coffee break!",
         "say Attention, starry-eyed shoppers! Today's special: Hyperspace Hoods – because even your hoodie should be "
         "faster than light!",
         "say Don't let cosmic rays cramp your style! Our Galactic Shades not only protect your eyes but make you look "
         "cooler than a frozen comet.",
         "say Psst, rumor has it our Quantum Quirks are the latest trend in extraterrestrial dance parties. You didn't "
         "hear it from me!"}));
}
