inherit "/std/races/standard";
#include "light_defs.inc"

void setup() 
{
  set_long("An Orc is a carnivorous demi-human.\n");
  set_name("orc");
  set_light_limits(LIGHT_ORC_LOW, LIGHT_ORC_HIGH);
  reset_get();
}

void set_racial_bonuses() 
{
  previous_object()->adjust_bonus_str(2);
  previous_object()->adjust_bonus_wis(-1);
}

int query_skill_bonus(int lvl, string skill) 
{
  if (skill == "fighting.meelee")
    return 20;
  if (skill == "fighting.melee.sharp")
    return 30;
  return 0;
}

string query_desc(object ob) 
{
 if((int)ob->query_gender() == 1)
  return "An ugly male orc.\n";
 return "A disgusting female orc.\n";
}
