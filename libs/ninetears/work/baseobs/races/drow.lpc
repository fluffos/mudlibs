inherit "/std/races/standard";
#include "light_defs.inc"

void setup()
{
  set_long("The drow are a dangerous and devious race.\n");
  set_name("drow");
  /* new thing for light */
  set_light_limits(LIGHT_DROW_LOW, LIGHT_DROW_HIGH);
  reset_get();
}

void set_racial_bonuses()
{
  previous_object()->adjust_bonus_int(1);
  previous_object()->adjust_bonus_dex(1);
  previous_object()->adjust_bonus_con(-1);
}

int query_skill_bonus(int lvl, string skill)
{
  return 0;
}

string query_desc(object ob)
{
 if((int)ob->query_gender() == 1)
   return("A devious dark elven male.\n");
 return("A beautiful yet devious dark elven female.\n");
}
