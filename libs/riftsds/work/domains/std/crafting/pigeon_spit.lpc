inherit FOOD;

//CRAFTING:pigeon on a spit

void setup()
{
  set_id("pigeon on a spit","spit","pigeon");
  set_adj("roasted");
  set_long("Two small pieces of pigeon breast, spit roasted to perfection. Not a large meal, but looks delicious.");
  set_num_eats(1+random(2));
  set_heal_value(2);
  set_weight(0.4);
}

mapping query_recipe()
{
  return (["wood scrap":1, "piece of pigeon meat":2]);
}

int is_material()
{
  return 1;
}

string query_station()
{
  return "cooking";
}