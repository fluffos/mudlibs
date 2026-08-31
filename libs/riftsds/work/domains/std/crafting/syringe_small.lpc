inherit MATERIAL;

//CRAFTING:small syringe

void setup()
{
    set_id("syringe");
    set_adj("small");
    set_long("This is a pump consisting of a sliding plunger that fits tightly in a tube. "
             "The plunger can be pulled and pushed inside the precise cylindrical tube, or "
             "barrel, letting the syringe draw in or expel a liquid.");
}

mapping query_recipe()
{
    return (["soft pvc":2, "molded plastic":1, "raw fertilizer":1]);
}

string query_station()
{
  return "chemistry";
}