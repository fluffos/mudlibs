inherit SPACESHIP;

string query_owner();

void setup()
{
   set_id("cruiser", "spacecruiser", "ship");
   set_brief("A small spacecruiser");
   set_long("This ship is a sleek and solitary machine that can take 2 people anywhere, fast. It is a cozy and "
            "reliable vessel. A navigation terminal and a weapons terminal is available at the two seats at the "
            "front of the cabin.\n"
            "An airlock is set in the wall leading outside.");
   set_ship_cost(50);
   set_ship_size(1);
   set_ship_type("excalibur spacecruiser");
   set_objects((["^common/item/airlock":1, "^common/item/ship_nav":1]));
}

// Must be in a spaceship to handle the virtualization
object virtual_create(string arg)
{
   return ::virtual_create(__FILE__, arg);
}