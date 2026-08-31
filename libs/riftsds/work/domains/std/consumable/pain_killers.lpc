/* Do not remove the headers from this file! see /USAGE for more info. */

inherit SLOWHEAL;

void setup()
{
   set_id("pain killers", "pills", "advil", "vial");
   set_adj("vial of");
   set_long("A small blue bottle of pain killers. It says it comes with 10 per vial.");
   set_heal_value(2);
   set_fuel(10);
   set_heal_value(4);
   set_weight(0.8);
   set_consume_message("$N $vpop the pain killers from the vial and $vtoss the bottle.");
   set_heal_message("You feel the pain killers relieving your pains.");
   set_expire_message("$N $vseem to get a slight headache again.");
}

int direct_eat_obj()
{
   return 1;
}

void do_eat()
{
   do_consume();
}
