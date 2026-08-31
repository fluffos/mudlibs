/* Do not remove the headers from this file! see /USAGE for more info. */

//CRAFTING:small battery

inherit BATTERY;

void setup()
{
    set_id("battery");
    add_adj("small","6-volt");
    set_long("This is a small improvised 6-volt battery for an electronic device or other low volt equipment. The typical capacity would be between 500-1000 mAh when it was made.");
    set_max_mah(1000);
    set_random_mah();
}

mapping query_recipe()
{
  return (["molded plastic":2, "waste acid":1, "lead scrap":1, "copper scrap":1, "steel scrap":2]);
}

string query_station()
{
  return "chemistry";
}
