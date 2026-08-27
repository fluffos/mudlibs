inherit "/std/races/standard";
#include "light_defs.inc"

void setup() {
  	set_long("Un medio-drow es parte drow, parte humano.\n");
  	set_name("medio-drow");
  	set_light_limits(LIGHT_HALFDROW_LOW, LIGHT_HALFDROW_HIGH);
	}

void set_racial_bonuses() {
  	previous_object()->adjust_bonus_dex(1);
  	previous_object()->adjust_bonus_str(-1);
	}

string query_desc(object ob) {
 	switch((int)ob->query_gender()) {
   		case 1 : return("Un varon medio-drow.\n");
   		case 2 : return("Una mujer medio-drow.\n");
   		case 3 : return("Un bisexual medio-drow.\n");
   		default: return("Un asexual medio-drow.\n");
 		}
	}
