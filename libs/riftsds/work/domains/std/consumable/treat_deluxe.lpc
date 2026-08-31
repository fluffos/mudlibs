/* Do not remove the headers from this file! see /USAGE for more info. */

inherit FOOD;

void setup()
{
   set_id("pet treat", "treat");
   set_adj("deluxe");
   set_long("A treat for a pet or an animal.");
   set_num_eats(2);
   set_weight(1);
   set_heal_value(10);
   set_eat_action("$N $vsnack a *deluxe* pet treat.");
   set_last_eat_action("$N $vsnack a *deluxe* pet treat.");
}

float query_value()
{
   return ::query_value() * 5;
}

int is_pet_treat()
{
   return 1;
}