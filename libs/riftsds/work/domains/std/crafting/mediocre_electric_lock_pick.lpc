inherit MATERIAL;
inherit M_LOCKPICK;


//CRAFTING:mediocre lock pick

void setup()
{
  set_id("lock pick", "lock pick", "lockpick", "pick");
  set_adj("mediocre", "electric");
  set_long("A snap pick, also known as lock pick, or electric lock pick, "
           "is a tool that can be used to open a locks "
           "without using the key.");
  set_lockpick_strength(200);
  set_break_chance(20);
  set_value(200);
}

int nobody_will_buy()
{
  return 1;
}

mapping query_recipe()
{
  return (["soft pvc":6, "molded plastic":4, "circuit":7, "waste acid":2]);
}

string query_station()
{
  return "electronics";
}
