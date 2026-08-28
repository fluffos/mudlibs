#include "../path.h"

inherit SHOP;

create_monster ()
{
  set_name (({ "joel", "man", "grocer", "shopkeeper" }));

  set_short ("Joel the old grocer is standing here behind the desk");
  set_long (
    "Joel is an old man already, he hasn't got much hair left "
  + "and the remaining hair is snow white with spots of grey. Joel "
  + "is thin, which you couldn't believe about a grocer.\n");

  set_race ("thari");
  set_levels ((["fighter":5]));
  set_gender (1);
  set_alignx (250 + random(500));
  set_aligny (250 + random(500));

  set_emote (({ "Joel sorts out his items.",
                "Joel polishes some of his items.",
                "Joel yawns tiredly." }));

  add_money (random(300) + 1);
}

is_legal_item (object o)
{
  if (o->is_armour())
    return 0;
  if (o->is_weapon())
    return 0;
  if (o->is_food())
    return 0;
  if (o->query_value() > 10000)
    return 0;

  return 1;
}

create_shop ()
{
  int k;
  string *items;

  items = ({ "/obj/generic/torch",
             "/obj/generic/canteen" });

  for (int i=0;i<sizeof(items);i++)   
    {
      k = random(3);
      for (int j=0;j<k;j++)
        THOB->send_item_to_store (clone_object (items[i]));
    }
}
