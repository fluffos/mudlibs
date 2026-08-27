inherit "/std/raza";
#include "light_defs.inc"

void setup() {
  	set_long("Un medio-elfo es parte elfo, parte humano.\n");
  	set_name("medio-elfo");
  	set_light_limits(LIGHT_HALFELF_LOW, LIGHT_HALFELF_HIGH);
	add_alineamiento(1,1);
	add_alineamiento(1,0);
	add_alineamiento(0,1);
	add_alineamiento(0,0);
	add_alineamiento(-1,1);
	add_alineamiento(-1,0);
	add_clase("Guerrero");
	add_clase("Sacerdote");
	add_clase("Hechicero");
	add_clase("Bribon");
	}

string query_desc(object ob) {
 	switch((int)ob->query_gender()) {
   		case 1 : return("Un varon medio-elfo.\n");
   		case 2 : return("Una mujer medio-elfa.\n");
   		case 3 : return("Un bisexual half-elfo.\n");
   		default: return("Un asexual medio-elfo.\n");
 		}
	}

int limitar_des() { return 19; }
int limitar_car() { return 19; }
