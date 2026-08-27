#include "light_defs.inc"
inherit "/std/races/standard";

void setup() {
  set_long("Un Demonio es el mal, odio, destruccion y perversion en forma de ser.\n");
  set_name("espiritu ancestral");
  set_light_limits(LIGHT_HUMAN_LOW, LIGHT_HUMAN_HIGH);
}

void set_racial_bonuses()
{
   previous_object()->adjust_bonus_cha(2);
   previous_object()->adjust_bonus_str(10);
   previous_object()->adjust_bonus_dex(3);
   previous_object()->adjust_bonus_int(10);
   previous_object()->adjust_bonus_con(10);
   previous_object()->adjust_bonus_wis(5);
}

string query_desc(object ob) {
  if ((int)ob->query_gender() == 1)
    return "Un terrible demonio en forma masculina.\n";
  return "Un terrible demonio en forma femenina.\n";
}
