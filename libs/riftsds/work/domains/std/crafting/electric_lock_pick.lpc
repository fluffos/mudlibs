inherit MATERIAL;
inherit M_LOCKPICK;


//CRAFTING:simple lock pick

void setup()
{
  set_id("lock pick", "lock pick", "lockpick", "pick");
  set_adj("simple", "electric");
  set_long("A snap pick, also known as lock pick, or electric lock pick, "
           "is a tool that can be used to open a locks "
           "without using the key.");
  set_lockpick_strength(50);
  set_break_chance(30);
  set_value(50);
}

int nobody_will_buy()
{
  return 1;
}

mapping query_recipe()
{
  return (["soft pvc":4, "molded plastic":2, "circuit":5, "waste acid":1]);
}

string query_station()
{
  return "electronics";
}
