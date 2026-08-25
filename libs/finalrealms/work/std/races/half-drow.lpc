inherit "/std/races/standard";
#include "light_defs.inc"

void setup() 
{
  set_long("A half-drow is part drow, part human.\n");
  set_name("half-drow");
  set_light_limits(LIGHT_HALFDROW_LOW, LIGHT_HALFDROW_HIGH);
  reset_get();
}

void set_racial_bonuses() 
{
  previous_object()->adjust_bonus_dex(1);
  previous_object()->adjust_bonus_str(-1);
}

int query_skill_bonus(int lvl, string skill) 
{
  if (skill == "dex.stealth")
    return 20;
  return 0;
}

string query_desc(object ob) 
{
 switch((int)ob->query_gender())
 {
   case 1 : return("A half-drow male.\n");
   case 2 : return("A half-drow female.\n");
   case 3 : return("A bisexual half-drow.\n");
   default: return("An non-sexual half-drow.\n");
 }
}
