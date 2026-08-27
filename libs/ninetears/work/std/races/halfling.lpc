inherit "/std/races/standard";
#include "light_defs.inc"

void setup() {
  	set_long("Un halfling es un pequenyo y corpulento semi-humano.\n");
  	set_name("halfling");
  	set_light_limits(LIGHT_HALFLING_LOW, LIGHT_HALFLING_HIGH);
  	set_race_size(3);
	add_alineamiento(0,1);
	add_alineamiento(0,0);
	add_alineamiento(-1,1);
	add_alineamiento(-1,-1);
	add_clase("Sacerdote");
	add_clase("Bribon");
	}

string query_desc(object ob) {
	if((int)ob->query_gender() == 1) return("Un pequenyo muchacho halfling.\n");
 	return("Una pequenya muchacha halfling.\n");
	}

int limitar_sab() { return 17; }
int limitar_des() { return 20; }
int limitar_fue() { return 17; }
