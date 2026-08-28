inherit SHOP;

#include "../path.h"

create_monster()
{
     set_name(({ "velinax", "thari","shopkeeper" }));
     set_short("Velinax Belmonte, the shopkeeper");
     set_long(wrap("Velinax is here clothed in a red, longsleeved shirt and dark pants. "+
      "He has a long beard which covers most of his face and neck. He is an average height "+
      "Thari with big green eyes.\n"));

     set_emote(({"Velinax picks his nose a bit.",
                 "Velinax looks through a brown sack in his hand."}));

     set_language ("sartog");
     set_gender (1);

     set_talk(({"Well, are you gonna buy something or not?",
                "Everything I sell is listed on the sign."}));

     set_race("thari");

     set_levels(([ "fighter" : 35 ]));

     set_pick(15);
}

is_legal_item ()
{
  return 0;
}

create_shop ()
{
  int k;
  string *items;

  items = ({ ITEM_PATH + "harvester",
             ITEM_PATH + "plow",
             ITEM_PATH + "hoe",
             ITEM_PATH + "sicle",
             ITEM_PATH + "jar",
             ITEM_PATH + "vial",
             ITEM_PATH + "jug",
             ITEM_PATH + "rusack",
             ITEM_PATH + "ownership_seal" });

  for (int i=0;i<sizeof(items);i++)
    {
      k = random(3);
      for (int j=0;j<k;j++)
        THOB->send_item_to_store (clone_object (items[i]));
    }
}
