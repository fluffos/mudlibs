inherit "/std/races/standard";
#include "light_defs.inc"

void setup() {
   	set_long("Una vez vivio, luego murio, y ahora vuelve a estar vivo.\n");
  	set_name("no muerto");
   	set_light_limits(LIGHT_BOUNDS_LOW,LIGHT_BOUNDS_HIGH);
   	add_property("undead",1);
	}

void set_racial_bonuses() {
  	previous_object()->adjust_bonus_str(1);
  	previous_object()->adjust_bonus_con(1);
	}

string query_desc(object ob) { return "Este diabolico ser vivio, murio, y ahora vive otra vez!\n"; }
