inherit FOOD;

//CRAFTING:mongoose cobbler

void setup()
{
    set_id("mongoose cobbler","cobbler");
    set_long("A thick-crusted pie that uses mongoose berries. The lite yellow mongoose berries gives the cobbler a beuatiful yellow shine.");
    set_adj("fresh");
    set_num_eats(5);
    set_heal_value(3);
    set_weight(1);
    set_last_eat_action("$N $vgrab a quick piece of mongoose cobbler, and $vchuck it into $p mouth.");
}

mapping query_recipe()
{
  return (["wood scrap":1, "mongoose berry":5]);
}

string query_station()
{
  return "cooking";
}