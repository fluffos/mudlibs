inherit "/std/raza";
#include "light_defs.inc"

void setup() {
  	set_long("Un feo y sucio goblin.\n");
  	set_name("goblin");
  	set_light_limits(LIGHT_GOBLIN_LOW, LIGHT_GOBLIN_HIGH);
  	set_race_size(3);
	add_alineamiento(0,-1);
	add_alineamiento(-1,-1);
	add_clase("Sacerdote");
	add_clase("Guerrero");
	add_clase("Bribon");
	}

int limitar_int() { return 16; }
int limitar_con() { return 19; }
int limitar_des() { return 19; }

string query_desc(object ob) {
 	if((int)ob->query_gender() == 1) return "Un feo y sucio goblin de piel verde.\n";
 	return "Una repugnante goblin de piel verde.\n";
	}

int ajustar_reputacion() { return -2; }