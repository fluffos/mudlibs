#include "light_defs.inc"
inherit "/std/races/standard";

void setup() 
{
  set_long("The Elves are a noble race of swift forest-people.\n");
  set_name("elf");
  set_light_limits(LIGHT_ELF_LOW, LIGHT_ELF_HIGH);
  reset_get();
}

void set_racial_bonuses() 
{
  previous_object()->adjust_bonus_int(1);
  previous_object()->adjust_bonus_dex(1);
  previous_object()->adjust_bonus_str(-1);
}

int query_skill_bonus(int lvl, string skill) 
{
  return 0;
}

string query_desc(object ob) 
{
 if((int)ob->query_gender() == 1) 
   return("An elfin man.\n");
 return("An elfin lady.\n");
}
