inherit "/std/races/standard";
#include "light_defs.inc"

void setup() 
{
  set_long("A halfling is a short, plump demi-human.\n");
  set_name("halfling");
  set_light_limits(LIGHT_HALFLING_LOW, LIGHT_HALFLING_HIGH);
  set_race_size(3);
  reset_get();
}

void set_racial_bonuses() 
{
  previous_object()->adjust_bonus_wis(-1);
  previous_object()->adjust_bonus_dex(2);
  previous_object()->adjust_bonus_str(-1);
}

int query_skill_bonus(int lvl, string skill) 
{
  return 0;
}

string query_desc(object ob) 
{
if((int)ob->query_gender() == 1)
   return("A short halfling lad.\n");
 return("A short halfling lass.\n");
}
