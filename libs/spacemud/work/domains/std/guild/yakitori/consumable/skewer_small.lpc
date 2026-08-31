/* Do not remove the headers from this file! see /USAGE for more info. */

inherit FOOD;
inherit M_DECAY;

int state_cnt = 0;

void setup()
{
   set_id("chicken skewer", "skewer", "chicken");
   set_adj("small");
   set_long("A freshly made chicken skewer with hot and sweet spicy saucy.");
   set_num_eats(3);
   set_heal_value(8);
   set_weight(0.8);
   set_eat_action("$N $vtake a bite out of $p small chicken skewer.");
   set_last_eat_action("$N $veat the final piece of $p chicken skewer.");
   set_num_decays(5);
   set_decay_action("Your chicken skewer looks less appetizing.");
   set_last_decay_action("Mold grows on your chicken skewer.");
   set_decay_time(10);
}

int state_update()
{
   switch (state_cnt)
   {
   case 0:
      break;
   case 1:
      set_adj("sad");
      set_long("A chicken skewer that is starting to look a bit old. Better eat it soon?");
      break;
   case 2:
      set_adj("nasty");
      set_long("A chicken skewer that is starting to look a cold and nasty?");
      break;
   case 3..4:
      set_adj("suspicious");
      set_long("A suspicious looking chicken skewer that is starting to look like trash.");
      set_poisonous(2);
      break;
   case 5:
      set_adj("moldy");
      set_long("A suspicious chicken skewer with mold on it. This may not be safe to eat anymore.");
      set_poisonous(5);
      break;
   case 10:
      this_object()->remove();
      break;
   }
   state_cnt++;

   return ::state_update();
}