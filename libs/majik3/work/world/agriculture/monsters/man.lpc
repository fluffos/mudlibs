inherit SHOP;

#include "../path.h"

create_monster()
{
  set_name(({"bob","shopkeeper","bob weir","keeper"}));
  set_short("Bob Weir, the keeper of the shop");
  set_long(wrap("Bob is a man of average height and build. His "+
  "eyes seem a bit glazed over. He is here watching over his "+
  "seed shop.\n"));
  set_race("thari");
  set_levels((["fighter" : 50 ]));
  set_language("sartog");
  set_wimpy(50,100);
  set_talk_delay(20);
  set_emote_delay(20);
  set_emote(({"Bob leans back with a wide grin on his face.",
              "The shopkeeper stares off into the distance.",
              "Bob sings a little song.",
              "Bob throws a seed into the air and catches it in his mouth.",
              "Bob coughs deeply."}));
  set_talk(({"Sure don't know what I'm goin' for, but I'm gonna go for it "+
             "for sure.",
             "If its seeds you're after, I'm the man you want.",
             "I know everthing about seeds.",
             "Have you talked to my friend Jerry Garcia?",
             "Farmers are the best people in the world.",
             "How have the plants been looking this season?"}));
}

is_legal_item ()
{
  return 0;
}

create_shop ()
{
  int k;
  string *items;

  items = ({ ITEM_PATH + "corn_seeds",
             ITEM_PATH + "barley_seeds",
             ITEM_PATH + "cabbage_seeds",
             ITEM_PATH + "carrot_seeds",
             ITEM_PATH + "green_bean_seeds",
             ITEM_PATH + "tobacco_seeds",
             ITEM_PATH + "tomato_seeds",
             ITEM_PATH + "wheat_seeds",
             ITEM_PATH + "potato_seeds" });

  for (int i=0;i<sizeof(items);i++)
    {
      k = random(3);
      for (int j=0;j<k;j++)
        THOB->send_item_to_store (clone_object (items[i]));
    }
}
