inherit "/std/raza";
#include "light_defs.inc"

void setup() {
    	set_long("Un hombre-lagarto verde y con escamas.\n");
    	set_name("hombre-lagarto");
    	set_light_limits(LIGHT_LIZARDMAN_LOW, LIGHT_LIZARDMAN_HIGH);
    	set_limbs(3);
	add_alineamiento(0,0);
	add_alineamiento(0,-1);
	add_alineamiento(-1,-1);
	add_alineamiento(-1,-1);
	add_clase("Guerrero");
	add_clase("Sacerdote");
	}

string query_desc(object ob) {
    	switch((int)ob->query_gender()) {
    		case 1 : return("Un hombre-lagarto.\n");
    		case 2 : return("Una mujer-lagarto.\n");
    		case 3 : return("Un bisexual hombre-lagarto.\n");
    		default: return("Un asexual hombre-lagarto.\n");
    		}
	}

int limitar_fue() { return 19; }
int limitar_int() { return 17; }
int limitar_sab() { return 19; }
int ajustar_reputacion() { return -1; }
