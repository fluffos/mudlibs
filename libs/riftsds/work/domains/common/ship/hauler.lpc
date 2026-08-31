inherit SPACESHIP;

string query_owner();

void setup()
{
   ::setup();
   set_brief("A astro-cargo hauler");
   set_ship_long("A bulky vessel of limited speed but with ample space for hauling goods. ");
   set_ship_cost(50);
   set_ship_size(3);
   set_ship_type("astro-cargo hauler");
}

//Must be in a spaceship to handle the virtualization
object virtual_create(string arg)
{
   return ::virtual_create(__FILE__, arg);
}