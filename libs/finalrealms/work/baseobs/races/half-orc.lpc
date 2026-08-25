inherit "/std/races/standard";
#include "light_defs.inc"

void setup() 
{
  set_long("A half-orc looks like a very ugly human with sharp teeth.\n");
  set_name("half-orc");
  set_light_limits(LIGHT_HALFORC_LOW, LIGHT_HALFORC_HIGH);
  reset_get();
}

void set_racial_bonuses() 
{
  previous_object()->adjust_bonus_str(1);
  previous_object()->adjust_bonus_wis(-1);
}

int query_skill_bonus(int lvl, string skill) 
{
  if (skill == "fighting.meelee")
    return 20;
  if (skill == "fighting.melee.sharp")
    return 20;
  return 0;
}

string query_desc(object ob) 
{
 if((int)ob->query_gender() == 1)
  return "An ugly half-orc.\n";
 return "A disgusting female half-orc.\n";
}
