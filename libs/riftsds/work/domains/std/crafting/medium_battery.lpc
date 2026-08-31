/* Do not remove the headers from this file! see /USAGE for more info. */

//CRAFTING:medium battery

inherit BATTERY;

void setup()
{
    set_id("battery");
    add_adj("medium","6-volt");
    set_long("This is a medium-sized improvised 6-volt battery for an electronic device or other low volt equipment. The typical capacity would be between 2000-3000 mAh when it was made.");
    set_max_mah(3000);
    set_random_mah();
}

mapping query_recipe()
{
  return (["molded plastic":3, "waste acid":2, "lead scrap":2, "copper scrap":2, "steel scrap":4]);
}

string query_station()
{
  return "chemistry";
}
