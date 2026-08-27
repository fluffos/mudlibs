inherit "/std/races/standard";
#include "light_defs.inc"

void setup() {
  	set_long("Un medio-orco es un humano de mal aspecto con dientes afilados.\n");
  	set_name("medio-orco");
  	set_light_limits(LIGHT_HALFORC_LOW, LIGHT_HALFORC_HIGH);
	}

void set_racial_bonuses() {
  	previous_object()->adjust_bonus_str(1);
  	previous_object()->adjust_bonus_wis(-1);
	}

string query_desc(object ob) {
 	if((int)ob->query_gender() == 1) return "Un feo medio-orco.\n";
 	return "Una horrible mujer medio-orco.\n";
	}
