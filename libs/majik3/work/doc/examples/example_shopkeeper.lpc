inherit SHOP;

create_monster ()
{
  set_name (({"a shopkeeper", "shopkeeper", "thari", "man" }));
  set_short ("a shopkeeper is selling his wares here");
  set_gender (1);
}

is_legal_item (object o)
{
  if (o->query_value() > 500)
    return 0;

  return 1; /* the shopkeeper will buy anything below worth 500 copper coins,
               if this function returns 0 then the keeper won't buy the item */
}

create_shop ()
{
  set_buy_percent(0.5); /* the shopkeeper will give only 0.5 of real
                           worth when player is selling something */

  set_sell_percent(1.5); /* the shopkeeper will sell items with 1.5x
                            price of total worth */

  set_produce (({"/doc/examples/example_item"})); /* the shopkeeper will
                                                   produce example_item's
                                                   with no limits */
}
