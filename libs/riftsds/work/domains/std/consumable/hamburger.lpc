/* Do not remove the headers from this file! see /USAGE for more info. */

inherit FOOD;
inherit M_DECAY;

int state_cnt = 0;

void setup()
{
   set_id("hamburger", "burger");
   set_adj("freshly made");
   set_long("A freshly made hamburger with cheese.");
   set_num_eats(5);
   set_heal_value(3);
   set_weight(0.8);
   set_eat_action("$N $vtake a bite out of $p hamburger.");
   set_last_eat_action("$N $veat the final piece of $p hamburger.");
   set_num_decays(5);
   set_decay_action("Your hamburger looks less appetizing.");
   set_last_decay_action("Mold grows on your hamburger.");
   set_decay_time(10);
}

int state_update()
{
   switch (state_cnt)
   {
   case 0:
      break;
   case 1:
      set_adj("soggy");
      set_long("A hamburger that is starting to look a bit old. Better eat it soon?");
      break;
   case 2:
      set_adj("nasty");
      set_long("A hamburger that is starting to look a cold and nasty?");
   case 3..4:
      set_adj("suspicious");
      set_long("A suspicious looking hamburger that is starting to look like trash.");
      set_poisonous(2);
   case 5:
      set_adj("moldy");
      set_long("A suspicious hamburger with mold on it. This may not be safe to eat anymore.");
      set_poisonous(5);
   }
   state_cnt++;

   return ::state_update();
}