#include "../path.h"

inherit SHOP;

create_monster ()
{
  set_name (({ "akeem", "salesman", "shopkeeper" }));

  set_short ("Akeem the salesman is standing here, petting a small faerie dragon");
  set_long (
    "Akeem the animal they call him. He is outlandish, darkish "
  + "complexion and black short hair. He has found a business selling "
  + "pet animals and that's good, you don't want guys like him on the "
  + "streets.");

  set_race ("shaolu");
  set_levels ((["fighter":25]));
  set_gender (1);
  set_alignx (-100 + random(500));
  set_aligny (-100 + random(500));

  set_talk (({ "Ye won't live without at least one quality pet!",
               "Buy a pet today, they're cheap now, only for you!" }));

  set_emote (({ "Akeem mumbles something to his faerie dragon.",
                "Akeem pets his faerie dragon lovingly.",
                "Akeem twiddles his thumbs.",
                "Akeem look at the street, looking for new customers." }));

  add_money (random(300) + 1);
}

is_legal_item(object o) { return o->is_pet(); }

create_shop ()
{
  set_sell_percent(1.5);
  set_buy_percent(0.5);
}
