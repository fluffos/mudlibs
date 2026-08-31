inherit DRINK;

//CRAFTING:boiled water

void setup()
{
  set_id("boiled water","water");
  set_long("This is a bottle of boiled. There are little pieces in here, but it should be safe to drink.");
  set_num_drinks(4);
  set_heal_value(1);
  set_weight(1);
}

mapping query_recipe()
{
  return (["wood scrap":1, "dirty water":2]);
}

int is_material()
{
  return 1;
}

string query_station()
{
  return "cooking";
}