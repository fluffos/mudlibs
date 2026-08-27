#include "light_defs.inc"
inherit "/std/races/standard";

void setup() 
{
  set_long("A stout dwarf.\n");
  set_name("dwarf");
  set_light_limits(LIGHT_DWARF_LOW, LIGHT_DWARF_HIGH);
  set_race_size(3);
  reset_get();
}

/* This is makeing a mess for me. */
void set_racial_bonuses() 
{
  previous_object()->adjust_bonus_str(1);
  previous_object()->adjust_bonus_con(1);
  previous_object()->adjust_bonus_dex(-1);
}

int query_skill_bonus(int lvl, string skill) 
{
  return 0;
}

/*
string query_desc(object ob) 
{
 if((int)ob->query_gender() == 1)
  return "A stout dwarven man.\n";
 return "A bearded dwarven wench.\n";
}
*/
