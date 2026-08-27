inherit "/std/raza";
#include "light_defs.inc"

void setup() {
  	set_long("Los drow son una raza peligrosa y malvada.\n");
  	set_name("drow");
  	set_light_limits(LIGHT_DROW_LOW, LIGHT_DROW_HIGH);
	add_alineamiento(0,-1);
	add_alineamiento(-1,-1);
	add_clase("Sacerdote");
	add_clase("Guerrero");
	add_clase("Hechicero");
  	}

int limitar_int() { return 19; }
int limitar_des() { return 19; }
int limitar_con() { return 17; }

int ajustar_reputacion() { return -5; }

string query_desc(object ob) {
 	if((int)ob->query_gender() == 1) return("Un malvado elfo oscuro.\n");
 	return("Una bella pero malvada elfa oscura.\n");
	}
