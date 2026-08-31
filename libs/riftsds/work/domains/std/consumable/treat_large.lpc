/* Do not remove the headers from this file! see /USAGE for more info. */

inherit FOOD;

void setup()
{
   set_id("pet treat", "treat");
   set_adj("large");
   set_long("A treat for a pet or an animal.");
   set_num_eats(1);
   set_weight(0.4);
   set_heal_value(4);
   set_eat_action("$N $vsnack a large pet treat.");
   set_last_eat_action("$N $vsnack a large pet treat.");
}

float query_value()
{
   return ::query_value() * 5;
}

int is_pet_treat()
{
   return 1;
}