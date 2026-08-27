inherit "/std/races/standard";
#include "light_defs.inc"

void setup() 
{
   set_long("An Evil ball of flame.\n");
  set_name("fire elemental");
  set_light_limits(LIGHT_GOBLIN_LOW, LIGHT_GOBLIN_HIGH);
  reset_get();
}

void set_racial_bonuses() 
{
  previous_object()->adjust_bonus_str(10);
  previous_object()->adjust_bonus_con(10);
  previous_object()->adjust_bonus_dex(10);
}

int query_skill_bonus(int lvl, string skill) 
{
  return 0;
}

string query_desc(object ob) 
{
 if((int)ob->query_gender() == 1)
    return "This entity is comprised entirely of Flames.\n";
   return "This entity is comprised entirely of Flames.\n";
}
