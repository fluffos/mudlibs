#include "light_defs.inc"
inherit "/std/raza";

void setup() {
  	set_long("Los Shades son una misteriosa raza de humanos contaminados por el poder de la oscuridad, traidos por la maligna diosa Jade desde otro plano de existencia.\n");
  	set_name("shade");
  	set_light_limits(LIGHT_HUMAN_LOW-10, LIGHT_HUMAN_HIGH-10);
	add_alineamiento(1,-1);
	add_alineamiento(-1,-1);
	add_alineamiento(0,-1);
	add_clase("Hechicero");
	add_clase("Bribon");
	}

string query_desc(object ob) {
 	if((int)ob->query_gender() == 1) return("Un misterioso shade.\n");
 	return("Una misteriosa shade.\n"); // Y si le pongo lefa? xDDD
	}

int limitar_int() { return 20; }
int limitar_des() { return 19; }
int limitar_con() { return 16; }
int limitar_car() { return 17; }

int ajustar_reputacion() { return -2; }