/* Do not remove the headers from this file! see /USAGE for more info. */

inherit FOOD;
inherit M_DECAY;

int state_cnt = 0;

void setup()
{
   string id = query_id()[0];
   set_adj("freshly made");
   set_eat_action("$N $vtake a bite out of $p "+id+".");
   set_last_eat_action("$N $veat the final piece of $p "+id+".");
   set_decay_action("Your "+id+" looks less appetizing.");
   set_last_decay_action("Mold grows on your "+id+".");
   m_decay::mudlib_setup();
}

void set_food_long(string s)
{
   string id=query_id()[0];
   s=replace_string(s,"$AS",capitalize(add_article(id)));
   s=replace_string(s,"$as",add_article(id));
   s=replace_string(s,"$s",id);
   s=replace_string(s,"$S",capitalize(id));

   ::set_long(s);
}

int state_update()
{
   string id = query_id()[0];
   switch (state_cnt)
   {
   case 0:
      break;
   case 1:
      set_adj("soggy");
      set_food_long("$AS that is starting to look a bit old. Better eat it soon?");
      break;
   case 2:
      set_adj("nasty");
      set_food_long("$AS that is starting to look a cold and nasty?");
   case 3..4:
      set_adj("suspicious");
      set_food_long("A suspicious looking $s that is starting to look like trash.");
      set_poisonous(2);
   case 5:
      set_adj("moldy");
      set_food_long("A suspicious $s with mold on it. This may not be safe to eat anymore.");
      set_poisonous(5);
   }
   state_cnt++;

   return ::state_update();
}