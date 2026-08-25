inherit "/std/races/standard";
#include "light_defs.inc"

string *inedible;

void setup() {
  set_long("A Demi-God is the second most powerful being in FR-MUD.\n");
  set_name("demi-god");
  /*new light handling */
  set_light_limits(LIGHT_DEMIGOD_LOW, LIGHT_DEMIGOD_HIGH);
  reset_get();
}

void set_racial_bonuses() {
  previous_object()->adjust_bonus_int(15);
  previous_object()->adjust_bonus_dex(15);
  previous_object()->adjust_bonus_str(15);
  previous_object()->adjust_bonus_wis(15);
  previous_object()->adjust_bonus_con(15);
  inedible = ({ "skull", "teeth" });
}

int query_skill_bonus(int lvl, string skill) {
  return 50;
}

string query_desc(object ob) {
  switch((int)ob->query_gender())
  {
   case 1 : return "Before you stands one of the most powerful immortals, a Demi-God.\n";
    case 2 : return "You are stunned by the beauty of a Demi-Goddess.\n";
    case 3 : return "This Demi-God is Bisexual... wow!\n";
    default:return "This Demi-God has no sex whatsoever.\n";
  }
}

int query_eat(string type) {
  return (member_array(type, inedible) == -1); 
}
