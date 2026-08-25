inherit "/std/races/standard";
#include "light_defs.inc"

void setup() 
{
   set_long("A mighty Lord of the Undead.\n");
  set_name("undead lord");
   set_light_limits(0,200);
  reset_get();
}

void set_racial_bonuses() 
{
  previous_object()->adjust_bonus_str(15);
  previous_object()->adjust_bonus_con(15);
  previous_object()->adjust_bonus_dex(15);
  previous_object()->adjust_bonus_int(15);
  previous_object()->adjust_bonus_wis(15);
  previous_object()->adjust_bonus_cha(15);
}

int query_skill_bonus(int lvl, string skill) 
{
  return 0;
}

string query_desc(object ob) 
{
 if((int)ob->query_gender() == 1)
   return "This fearsome creature is a Lord of the Underworld, dark and terrible.\n";
  return "This fearsome creature is a Lord of the Underworld, dark and terrible.\n";
}
