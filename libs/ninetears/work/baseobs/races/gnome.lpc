inherit "/std/races/standard";
#include "light_defs.inc"

void setup() 
{
  set_long("A small Gnome.\n");
  set_name("gnome");
  set_light_limits(LIGHT_GNOME_LOW, LIGHT_GNOME_HIGH);
  set_race_size(3);
  reset_get();
}

void set_racial_bonuses() 
{
  previous_object()->adjust_bonus_int(2);
  previous_object()->adjust_bonus_wis(-1);
}

int query_skill_bonus(int lvl, string skill) 
{
  return 0;
}

string query_desc(object ob) 
{
 if((int)ob->query_gender() == 1)
  return "A funny, bearded gnome.\n";
 return "A female gnome.\n";
}
