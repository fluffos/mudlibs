#include "light_defs.inc"
inherit "/std/races/standard";

void setup() {
  	set_long("Un robusto enano.\n");
  	set_name("enano");
  	set_light_limits(LIGHT_DWARF_LOW, LIGHT_DWARF_HIGH);
  	set_race_size(3);
	add_alineamiento(1,1);
	add_alineamiento(0,1);
	add_alineamiento(1,0);
	add_alineamiento(0,0);
	add_clase("Sacerdote");
	add_clase("Guerrero");
  	}

string query_desc(object ob) {
 	if((int)ob->query_gender() == 1) return "Un robusto enano.\n";
 	return "Una barbuda enana.\n";
	}

int limitar_fue() { return 19; }
int limitar_con() { return 19; }
int limitar_des() { return 17; }
