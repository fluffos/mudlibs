#include "light_defs.inc"
inherit "/std/races/standard";

void setup() {
  set_long("The human race.  The standard by which all the races are set, "
           "this is race can be considered the norm.\n");
   set_name("human");
  set_light_limits(LIGHT_HUMAN_LOW, LIGHT_HUMAN_HIGH);
}

void set_racial_bonuses()
{
   previous_object()->adjust_bonus_cha(2);
}
/*
string query_desc(object ob) {
  if ((int)ob->query_gender() == 1)
    return "A strapping young human lad.\n";
  return "A strapping young human lass.\n";
}
*/
