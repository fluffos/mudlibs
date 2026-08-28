#include "../path.h"

inherit SHOP;

create_monster ()
{
  set_name (({ "rolf", "smith", "shopkeeper" }));

  set_short ("Rolf the smith is pounding his hammer down on the anvil");
  set_long (
    "Rolf is a muscular middle aged man. He has dark hair and a tangled "
  + "beard. He looks at you nervously under his thick brows. Obviously "
  + "he doesn't trust anyone at first.");

  set_race ("thari");
  set_levels ((["fighter":40]));
  set_gender (1);
  set_alignx (random(500));
  set_aligny (random(500));

  set_talk (({ "Daggers, maces, longswords, I have the best quality!",
               "Ye won't find better or cheaper armours!",
               "So, whatcha ya want?" }));

  set_emote (({ "Rolf polishes his wares.",
                "Rolf eyes you suspiciously.",
                "Rolf grins.",
                "Rolf twiddles his thumbs." }));

  add_money (random(300) + 1);
}

is_legal_item(object o) { return o->is_weapon(); }

create_shop ()
{
  set_sell_percent(1.5);
  set_buy_percent(0.5);
}
