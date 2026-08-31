inherit DRINK;

void setup()
{
   set_id("water", "dirty water");
   set_adj("dirty");
   set_num_drinks(4);
   set_heal_value(1);
   set_weight(1);
   set_long("This is a carton of dirty water. Should probably boil it before drinking it ...");
   set_drink_action("$N $vtake a swig of dirty water.");
   set_last_drink_action("$N $vtake a drink of dirty water, finishing the bottle off.");
   if (random(2))
      set_poisonous(2);
}

string get_extra_long()
{
   return ::get_extra_long();
}

int is_material()
{
   return 1;
}