inherit MATERIAL;
inherit M_LOCKPICK;


// CRAFTING:advanced lock pick

void setup()
{
   set_id("lock pick", "lock pick", "lockpick", "pick");
   set_adj("advanced", "electric");
   set_long("A snap pick, also known as lock pick, or electric lock pick, "
            "is a tool that can be used to open a locks "
            "without using the key.");
   set_lockpick_strength(500);
   set_break_chance(10);
   set_value(500);
}

int nobody_will_buy()
{
   return 1;
}

mapping query_recipe()
{
   return (["soft pvc":10, "molded plastic":8, "circuit":10, "waste acid":5]);
}

string query_station()
{
   return "electronics";
}
