inherit DRINK;

//CRAFTING:blackberry cider

void setup()
{
  set_id("blackberry cider", "cider");
  set_long("A bottle of blackberry cider - lightly fermented. Smells quite good!.");
  set_num_drinks(4);
  set_heal_value(3);
  set_weight(1);
  set_drink_action("$N $vtake a swig of blackberry cider.");
  set_last_drink_action("$N $vtake a drink of blackberry cider, finishing the bottle off.");
}

mapping query_recipe()
{
  return (["boiled water":1, "wild blackberry":1, "wood scrap":1]);
}

string query_station()
{
  return "cooking";
}

string get_extra_long()
{
    return ::get_extra_long();
}
