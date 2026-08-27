inherit "/std/races/standard";
#include "light_defs.inc"

void setup() {
  	set_long("Un robusto enano de complexion oscura.\n");
  	set_name("duergar");
  	set_light_limits(LIGHT_DUERGAR_LOW, LIGHT_DUERGAR_HIGH);
  	set_race_size(3);
	add_alineamiento(1,-1);
	add_alineamiento(0,-1);
	add_clase("Sacerdote");
	add_clase("Guerrero");
	}

int limitar_fue() { return 19; }
int limitar_con() { return 19; }
int limitar_des() { return 17; }

string query_desc(object ob) {
 	if((int)ob->query_gender() == 1) return "Un robusto enano de complexion oscura.\n";
 	return "Una robusta enana de complexion oscura.\n";
	}

int ajustar_reputacion() { return -2; }
