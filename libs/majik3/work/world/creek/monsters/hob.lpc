#include "../path.h"

inherit SHOP;

create_monster ()
{
  set_name (({ "hob", "baker", "halfling" }));

  set_short ("Hob the halfling baker is selling his breads here");
  set_long (
    "Hob is an old apple cheeked halfling. He is covered in flours "
  + "and is sneezing all the time trying to get the flour out from his "
  + "nostrils. He notices you and blushes. 'What can I get you?' he asks "
  + "and bows deeply before you.\n");

  set_race ("halfling");
  set_levels ((["fighter":5]));
  set_gender (1);
  set_alignx (250 + random(500));
  set_aligny (250 + random(500));

  set_talk (({ "What can I get you?",
               "Buy some bread!" }));

  set_emote (({ "Hob counts her money greedily.",
                "Hob smiles.",
                "Hob sneezes." }));

  add_money (random(300) + 1);
}

is_legal_item(object o) { return o->is_food(); }

create_shop ()
{
  set_sell_percent(1.5);
}
