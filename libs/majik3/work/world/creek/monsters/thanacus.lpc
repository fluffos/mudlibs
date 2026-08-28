#include "../path.h"

inherit SHOP;

create_monster ()
{
  set_name (({ "thanacus", "shopkeeper" }));

  set_short ("Thanacus the book salesman is standing here");
  set_long (
    "Thanacus is a man in his thirties. He has a brown curled hair "
  + "and mustaches. He is wearing his reading glasses and reading the "
  + "Reader's Digest.");

  set_race ("thari");
  set_levels ((["fighter":5]));
  set_gender (1);
  set_alignx (200 + random(500));
  set_aligny (200 + random(500));

  set_talk (({ "Humdidum...",
               "Have you heard the latest gossip?" }));

  set_emote (({ "Thanacus adjusts his reading glasses.",
                "Thanacus raises his eyebrow.",
                "Thanacus cackles." }));

  add_money (random(300) + 1);
}

is_legal_item(object o) { return o->is_book(); }

create_shop ()
{
  int k;
  string *items;

  items = ({ ITEM_PATH + "jormap_book",
             ITEM_PATH + "riddle_book",
             ITEM_PATH + "map" });

  for (int i=0;i<sizeof(items);i++)
    {
      k = random(3);
      for (int j=0;j<k;j++)
        THOB->send_item_to_store (clone_object (items[i]));
    }
}
