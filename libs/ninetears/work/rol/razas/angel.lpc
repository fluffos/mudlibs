#include "light_defs.inc"
inherit "/std/raza";

void setup() {
  	set_long("Un Angel es el bien, amor, honor y honestidad en forma de ser.\n");
   	set_name("angel");
  	set_light_limits(LIGHT_HUMAN_LOW, LIGHT_HUMAN_HIGH);
	}

void set_racial_bonuses() {
   	previous_object()->adjust_bonus_cha(2);
   	previous_object()->adjust_bonus_str(10);
   	previous_object()->adjust_bonus_dex(3);
   	previous_object()->adjust_bonus_int(10);
   	previous_object()->adjust_bonus_con(10);
   	previous_object()->adjust_bonus_wis(5);
	}

string query_desc(object ob) {
  	if ((int)ob->query_gender() == 1) return "Un hermoso angel en forma masculina.\n";
  	return "Un hermoso angel en forma femenina.\n";
	}
