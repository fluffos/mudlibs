inherit "/std/races/standard";
#include "light_defs.inc"

void setup()  {
  	set_long("Un Ent es un ser del bosque, un arbol pero no.. no se si me explico...\n");
  	set_name("ent");
  	set_light_limits(LIGHT_ORC_LOW, LIGHT_ORC_HIGH);
	}

void set_racial_bonuses() {
  	previous_object()->adjust_bonus_str(2);
  	previous_object()->adjust_bonus_con(2);
  	previous_object()->adjust_bonus_dex(-2);
  	previous_object()->adjust_bonus_cha(-2);
  	previous_object()->adjust_bonus_wis(-2);
  	previous_object()->adjust_bonus_int(0);
	}

string query_desc(object ob) {
 	if((int)ob->query_gender() == 1) return "Un feo ent.\n";
 	return "Un feo ent.\n";
	}
