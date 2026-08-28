#include "../path.h"

inherit SHOP;

create_monster ()
{
  set_name (({ "khirz", "dwarf", "armourer", "shopkeeper" }));

  set_short ("Khirz the dwarven armourer is selling his armours here");
  set_long (
    "Now this dwarf has a huge black beard and long black tangled hair. "
  + "He is wearing full armour and a helmet. Obviously he never takes "
  + "his armours off. At least he smells that bad...");

  set_race ("dwarf");
  set_levels ((["fighter":30]));
  set_gender (1);
  set_alignx (250 + random(500));
  set_aligny (250 + random(500));

  set_talk (({ "Buy quality armours here now, the sale won't last long!",
               "In need of armours?",
               "What I can get to you?" }));

  set_emote (({ "Khirz mumbles something.",
                "Khirz looks at you.",
                "Khirz grins.",
                "Khirz twiddles his thumbs." }));

  add_money (random(300) + 1);
}

is_legal_item(object o) { return o->is_armour(); }

create_shop ()
{
  set_sell_percent(1.5);
  set_buy_percent(0.5);
}
