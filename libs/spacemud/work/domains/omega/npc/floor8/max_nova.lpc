/* Do not remove the headers from this file! see /USAGE for more info. */

inherit LIVING;
inherit M_VENDOR;
inherit M_CONVERSATION;

mixed check_buy(object ob)
{
   return ob->is_terminal_module() || "Max Nova says, \"I only buy terminal modules, sorry\".";
}

private
void add_inventory()
{
   string *items = ({"scanner range", "hyperdrive stabilizer", "shield", "navigation AI", "engine overclock",
                     "energy weapon refit"});
   int i = 5;
   foreach (string it in items)
   {
      while (i > 0)
      {
         add_sell(ITEM_TERM_MOD, ((6 - i == 5) ? -1 : (6 - i)), ({it, i}));
         i--;
      }
      i = 5;
   }
}

string query_hint(int level)
{
   switch (level)
   {
   case 0..4:
      return "This shop is for buying upgrades for your ship. You can get your first ship at level 5. ";
   case 5..10:
      return "Buy ship upgrades here, that will be provisioned when your ship is docked at the station.\n"
             "Use 'list', 'list shield' and 'talk to max' to see what's for sale and get more information about the "
             "equipment.";
   }
}

void setup()
{
   set_gender(1);
   set_name("Max Nova");
   add_id("employee", "technician", "max");
   set_proper_name("Max");
   set_in_room_desc("Max Nova, a friendly and knowledgeable technician");
   set_long("Max is a seasoned expert in ship modifications and a familiar "
            "face among the station's spacefaring community.");

   set_currency_type("credit");

   set_for_sale(1);
   set_will_buy(( : check_buy:));

   add_inventory();
   set_clear_numbers(1);
   set_options((["hello":"So what are you selling here?",
                "handle":"What do you mean handle?", "upgrade":"Can I upgrade anywhere? Even in space?",
               "details":"Tell me about the upgrades you sell.", "scanner":"Tell me about the scanner range module.",
            "hyperdrive":"Tell me about the hyperdrive stabilizer.", "shield":"Tell me about Shield modules.",
            "navigation":"Tell me about Navigation AI modules.", "engine":"Tell me about Engine Overclick Modules",
                "energy":"Tell me about Energy Weapon Refit modules."]));

   set_responses(
       (["hello":"I sell ship upgrade modules you can insert into your ships onboard terminal, which will "
                 "initiate an upgrade process for your ship. Make sure to not buy higher level module than "
                 "what your ship can handle.@@handle,upgrade",
               "handle":"If you check your on-board ship computer you can see current upgrade levels and max "
                        "upgrade levels for your ship. Don't buy higher upgrades than your ship can handle.",
              "upgrade":"No, you need to be docked at a major starport or terminal for upgrades. Not all upgrades "
                        "may be available everywhere, but all the ones I sell are available at Omega Station.",
              "details":"Which one do you want to hear about?@@scanner,hyperdrive,shield,navigation,engine,energy@@hello",
              "scanner":"Umm.. scanners, yes.", "hyperdrive":"Umm.. hyperdrive, yes.", "shield":"Umm.. shields, yes.",
           "navigation":"Umm.. navigation AI, yes.", "engine":"Umm.. engine, yes.", "energy":"Umm.. energy, yes.",

   ]));

   set_start(({"hello", "details"}));
}
