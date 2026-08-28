#include "../path.h"

inherit SHOP;

create_monster ()
{
  set_name (({ "friedrich", "barkeeper", "shopkeeper" }));

  set_short ("Friedrich the Greedy, barkeeper of Robber's Den is mixing a drink here");
  set_long (
    "Fridrich is a sly looking as a man can get. He has a short greasy "
  + "black hair and long thing mustaches. He is wearing a bloodstained "
  + "appron and leather clothes. He notices you and grins.");

  set_race ("thari");
  set_levels ((["fighter":20]));
  set_gender (1);
  set_alignx (-100 + random(500));
  set_aligny (-500 + random(500));

  set_talk (({ "Whatcha want now?" }));

  set_emote (({ "Friedrich eyes you suspiciously.",
                "Friedrich grins." }));

  add_money (random(300) + 1);
}

is_legal_item(object o) { return 0; }

create_shop ()
{
  set_sell_percent(1.5);
}
