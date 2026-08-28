inherit SHOP;

#include "../path.h"
#define say(x) "/command/mortal/say"->main(x)

create_monster()
{
     set_name(({ "Barcos", "barcos", "halfling", "merchant", "halfling merchant" }));
     set_short("Barcos, a halfling merchant");
     set_long(wrap("Barcos is a halfing who must have quite a bit of money, for he is dressed "+
      "very well. He is wearing a fancy blue vest with gold buttons and deep blue trousers, "+
      "also with gold trim. His hat is black and has the symbol of a member of the halfling "+
      "traders union.  Plus, he has a nice pair of leather boots on, strapped all the way up "+
      "to his knees.\n"));

     set_emote(({"Barcos rearranges some fruit in the cart.",
                 "Barcos wipes some sweat from his brow.",
                 "Barcos takes a some food from the cart and eats it."}));

     set_language ("palen");

     set_talk(({"Fresh food here! Get yer fresh food!",
                "Your favorite foods, clean and fresh, for sale here!"}));

     set_race("halfling");

     set_levels(([ "fighter" : 5 ]));

     set_gender (1);
}

is_legal_item (object o)
{
  if (o->query_material() == "food")
    return 0;

  return 1; /* the shopkeeper will buy anything below worth 500 copper coins,
               if this function returns 0 then the keeper won't buy the item */
}

create_shop ()
{
  set_max_value (100000);  
}
