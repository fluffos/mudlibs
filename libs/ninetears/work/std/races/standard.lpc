// Vilat metiendole mano a las luces O_o
inherit "/std/object";

#include "light_defs.inc"
#include "race_weights.h"

nosave int min_light_limit;
nosave int max_light_limit;

int race_size;
int limbs;

mixed alineamientos=({});
string *clases=({});

void add_alineamiento(int e,int m) { if(member_array(({e,m}),alineamientos)==-1) alineamientos+=({({e,m})}); }
void add_clase(string clase) { if(member_array(clase,clases)==-1) clases+=({clase}); }

mixed query_alineamientos() { return alineamientos; }
string* query_clases() { return clases; }

void create() {
    	set_long("La raza estandar... Deberias conseguir pronto una mejor.\n");
    	reset_get();
    	race_size = 4;
    	limbs = 2;
    	::create();
    	set_name("unknown creature");
    	}

void set_race_size(int i) { race_size = i; }
int query_race_size() { return race_size; }

void set_limbs(int i) { limbs = i; }
int query_limbs() { return limbs; }

string query_desc(object ob) { return "Una pequenya persona sin descripcion.\n"; }

int player_start(object player) { return 1; }
int player_quit(object player) { return 1; }

// Modificado por Zonzamas '02
int query_dark(int i) {
  	if ((i> min_light_limit)&&(i<max_light_limit)) return 0 ; /* Limites normales */
  	if( i < (min_light_limit-5) ) return 1; /* Demasiado oscuro */
  	if(i < min_light_limit) return 2; /* La oscuridad empieza a molestar */
  	if(i > (max_light_limit + 5) ) return 6; /* Cegado por la luz */
  	if(i > max_light_limit) return 4; /* La luz comienza a molestar */
  	return 0;
	}

void set_level(int lvl, object ob) { return; }

void start_player(object ob) {
    	string p_race;
    	if(ob) {
        	p_race = ob->query_race();
        	ob->add_language(p_race);
    		}
    	else return;
    	switch(p_race) {
    		case "elfo":
    		case "drow":
        	ob->set_weight(ELF_WEIGHT);
        	break;
    		case "enano":
    		case "duergar":
      		ob->set_weight(DWARF_WEIGHT);
        	break;
    		case "gnomo":
        	ob->set_weight(GNOME_WEIGHT);
        	break;
    		case "halfling":
        	ob->set_weight(HALFLING_WEIGHT);
        	break;
    		case "orco":
        	ob->set_weight(ORC_WEIGHT);
        	break;
    		case "goblin":
        	ob->set_weight(GOBLIN_WEIGHT);
        	break;
    		case "hombre-lagarto":
        	ob->set_weight(LIZARD_MAN_WEIGHT);
        	break;
    		case "medio-elfo":
        	ob->set_weight(HALF_ELF_WEIGHT);
        	ob->add_language("humano");
        	ob->add_language("elfo");
        	break;
    		case "medio-drow":
        	ob->set_weight(HALF_ELF_WEIGHT);
        	ob->add_language("humano");
        	ob->add_language("drow");
        	break;
    		case "medio-orco":
        	ob->set_weight(HALF_ORC_WEIGHT);
        	ob->add_language("humano");
        	ob->add_language("orco");
        	break;
    		case "humano":
        	ob->set_weight(HUMAN_WEIGHT);
        	break;
    		default:
        	ob->set_weight(1700);
        	break;
    		}
	}


void on_death(object player,object killer) { return; }

int set_light_limits(int lower, int upper) {
    	min_light_limit = lower;
    	max_light_limit = upper;
    	return 1;
	}

int query_light_limith() {
    	return max_light_limit;
	}

int query_light_limitl() {
    	return min_light_limit;
	}

int limitar_fue() { return 18; }
int limitar_des() { return 18; }
int limitar_con() { return 18; }
int limitar_sab() { return 18; }
int limitar_int() { return 18; }
int limitar_car() { return 18; }

int ajustar_reputacion() { return 0; }
