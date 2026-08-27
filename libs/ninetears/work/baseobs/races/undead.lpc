inherit "/std/races/standard";
#include "light_defs.inc"

void setup() 
{
   set_long("It was once alive, then it was dead, now its alive again.\n");
  set_name("undead");
   set_light_limits(0,200);
   add_property("undead",1);
  reset_get();
}

void set_racial_bonuses() 
{
  previous_object()->adjust_bonus_str(1);
  previous_object()->adjust_bonus_con(1);
}

int query_skill_bonus(int lvl, string skill) 
{
  return 0;
}

string query_desc(object ob) 
{
 if((int)ob->query_gender() == 1)
   return "This fiend once lived, died, and now lives again!\n";
   return "This fiend once lived, died, and now lives again!\n";
}
