inherit MATERIAL;

//CRAFTING:simple electronics kit

void setup()
{
    set_id("electronics kit","kit");
    set_adj("simple");
    set_long("This small electronics kit can be used to upgrade simple electronics.");
}

mapping query_recipe()
{
    return (["molded plastic":1, "circuit":5,"waste acid":1]);
}

int nobody_will_buy()
{
  return 1;
}

string query_station()
{
  return "workshop";
}