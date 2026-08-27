inherit "/std/raza";
#include "light_defs.inc"

void setup() {
   	set_long("Un poderoso inmortal, muestra tus respetos.\n");
   	set_name("inmortal");
	set_limbs(4);
   	set_light_limits(LIGHT_BOUNDS_LOW,LIGHT_BOUNDS_HIGH);
	}

string query_desc(object ob) {
 	if((int)ob->query_gender() == 1) return "Un poderoso inmortal.\n";
 	return "Una bella inmortal.\n";
	}
