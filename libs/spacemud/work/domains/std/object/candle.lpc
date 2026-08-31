/* Do not remove the headers from this file! see /USAGE for more info. */

inherit OBJ;
inherit LIGHT_OBJECT;
inherit M_GETTABLE;

void setup()
{
   set_id("candle");
   set_adj("wax", "red");
   set_long("A red wax candle.");
   // Use fuel every 2 minutes
   set_call_interval(2);
   // Fuel for 10 decays, so 20 minutes all in all.
   set_fuel(10);
   set_die_msg("The $o burns up and a small pillar of smoke rises from the wick.");
   set_decay_action("$P $o flickers and sputters a little.");
}

string get_extra_long()
{
   int time_left = this_object()->query_num_decays() * this_object()->query_call_interval();
   return "The candle will probably burn another " + time_left + " minutes or so.";
}