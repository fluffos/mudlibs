inherit "/std/races/standard";
#include "light_defs.inc"

void setup() 
{
  set_long("A half-elf is part elf, part human.\n");
  set_name("half-elf");
  set_light_limits(LIGHT_HALFELF_LOW, LIGHT_HALFELF_HIGH);
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
   case 1 : return("A half-elfin man.\n");
   case 2 : return("A half-elfin lady.\n");
   case 3 : return("A bisexual half-elf.\n");
   default: return("An non-sexual half-elf.\n");
 }
}
