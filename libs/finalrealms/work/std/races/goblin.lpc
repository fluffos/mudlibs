inherit "/std/races/standard";
#include "light_defs.inc"

void setup() 
{
  set_long("A small and ugly demi-human.\n");
  set_name("goblin");
  set_light_limits(LIGHT_GOBLIN_LOW, LIGHT_GOBLIN_HIGH);
  set_race_size(3);
  reset_get();
}

void set_racial_bonuses() 
{
  previous_object()->adjust_bonus_int(-2);
  previous_object()->adjust_bonus_con(1);
  previous_object()->adjust_bonus_dex(1);
}

int query_skill_bonus(int lvl, string skill) 
{
  return 0;
}

string query_desc(object ob) 
{
 if((int)ob->query_gender() == 1)
  return "A dirty-looking male goblin\n";
 return "A dirty-looking female goblin\n";
}
