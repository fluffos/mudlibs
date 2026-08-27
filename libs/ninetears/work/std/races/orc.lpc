inherit "/std/races/standard";
#include "light_defs.inc"

void setup() {
  	set_long("Un Orco es un semi-humano carnivoro y de piel verde.\n");
  	set_name("orco");
  	set_light_limits(LIGHT_ORC_LOW, LIGHT_ORC_HIGH);
	add_alineamiento(0,-1);
	add_alineamiento(-1,-1);
	add_clase("Sacerdote");
	add_clase("Guerrero");
  	}

int limitar_fue() { return 20; }
int limitar_sab() { return 17; }

string query_desc(object ob) {
 	if((int)ob->query_gender() == 1) return "Un feo varon orco.\n";
 	return "Una horrible mujer orco.\n";
	}

int ajustar_reputacion() { return -3; }
