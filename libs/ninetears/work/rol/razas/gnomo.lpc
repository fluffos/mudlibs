inherit "/std/raza";
#include "light_defs.inc"

void setup() {
  	set_long("Un pequenyo Gnomo.\n");
  	set_name("gnomo");
  	set_light_limits(LIGHT_GNOME_LOW, LIGHT_GNOME_HIGH);
  	set_race_size(3);
	add_alineamiento(1,1);
	add_alineamiento(1,0);
	add_alineamiento(0,1);
	add_alineamiento(0,0);
	add_alineamiento(-1,1);
	add_alineamiento(-1,0);
	add_clase("Bribon");
	add_clase("Guerrero");
	add_clase("Sacerdote");
	add_clase("Hechicero");
	}

string query_desc(object ob) {
 	if((int)ob->query_gender() == 1) return "Un barbudo gnomo con aspecto divertido.\n";
 	return "Una gnoma con aspecto divertido.\n";
	}

int limitar_int() { return 20; }
int limitar_sab() { return 17; }
