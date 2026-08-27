inherit "/std/races/standard";
#include "light_defs.inc"

void setup() 
{
   set_long("Un temible ogro.\n");
  set_name("ogro");
  set_light_limits(LIGHT_BOUNDS_LOW,LIGHT_BOUNDS_HIGH);
  reset_get();
}

/* This is makeing a mess for me. */
void set_racial_bonuses() 
{
  previous_object()->adjust_bonus_str(5);
  previous_object()->adjust_bonus_con(5);
  previous_object()->adjust_bonus_dex(-5);
}

int query_skill_bonus(int lvl, string skill) 
{
  return 0;
}

string query_desc(object ob) 
{
 if((int)ob->query_gender() == 1)
  return "Un temible y horrible ogro.\n";
 return "Una temible y horrible ogro hembra.\n";
}
