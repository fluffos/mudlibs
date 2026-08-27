inherit "/std/races/standard";
#include "light_defs.inc"

void setup() 
{
   set_long("A crafty white monkey.\n");
  set_name("monkey");
  set_light_limits(LIGHT_BOUNDS_LOW,LIGHT_BOUNDS_HIGH);
  reset_get();
}

/* This is makeing a mess for me. */
void set_racial_bonuses() 
{
  previous_object()->adjust_bonus_str(2);
  previous_object()->adjust_bonus_con(1);
  previous_object()->adjust_bonus_dex(10);
}

int query_skill_bonus(int lvl, string skill) 
{
  return 0;
}

string query_desc(object ob) 
{
 if((int)ob->query_gender() == 1)
  return "A crafty male monkey.\n";
 return "A lithe female monkey.\n";
}
