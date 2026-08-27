#include "light_defs.inc"
inherit "/std/races/standard";

void setup() {
  	set_long("Los Elfos son una noble raza de habiles habitantes del bosque.\n");
  	set_name("elfo");
  	set_light_limits(LIGHT_ELF_LOW, LIGHT_ELF_HIGH);
	add_alineamiento(1,1);
	add_alineamiento(1,0);
	add_alineamiento(0,1);
	add_alineamiento(0,0);
	add_alineamiento(-1,1);
	add_alineamiento(-1,0);
	add_clase("Sacerdote");
	add_clase("Guerrero");
	add_clase("Hechicero");
	add_clase("Bribon");
	}

string query_desc(object ob) {
 	if((int)ob->query_gender() == 1) return("Un orgulloso elfo.\n");
 	return("Una coqueta elfa.\n"); // Y si le pongo lefa? xDDD
	}

int limitar_int() { return 19; }
int limitar_des() { return 19; }
int limitar_con() { return 17; }
