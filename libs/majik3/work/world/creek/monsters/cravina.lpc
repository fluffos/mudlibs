#include "../path.h"

inherit SHOP;

create_monster ()
{
  set_name (({ "cravina", "witch", "candlemaker", "woman", "crone", 
    "cravina", "elyandra" }));

  set_short ("Cravina Elyandra, the old witch is selling her candles here");
  set_long (
    "Cravina is an old woman dressed in black clothes, althought she "
  + "is a witch she is not evil as one could think. She is more a nature "
  + "witch than those evil onse who summon demons and such. One could "
  + "call her a druidess. Her sparkling eyes watch you keenly as you "
  + "enter her shop.\n");

  set_race ("thari");
  set_levels ((["caster":50]));
  set_gender (2);
  set_alignx (0 + random(500));
  set_aligny (0 + random(500));

  set_talk (({ "Good candles, good candles...",
               "Buy some candles!",
               "Best candles in Silvercreek!",
               "All kind of candles, magical candles!",
               "Buy candles and give some light to the night!" }));

  set_emote (({ "Cravina counts her money greedily.",
                "Cravina smiles." }));

  add_money (random(300) + 1);
}

is_legal_item(object o) { return 0; } /* cravina won't buy anything */

create_shop ()
{
  int k;
  string *items;

  items = ({ ITEM_PATH + "red_candle",
             ITEM_PATH + "white_candle",
             ITEM_PATH + "lamp" });

  for (int i=0;i<sizeof(items);i++)
    {
      k = random(3);
      for (int j=0;j<k;j++)
        THOB->send_item_to_store (clone_object (items[i]));
    }
}
