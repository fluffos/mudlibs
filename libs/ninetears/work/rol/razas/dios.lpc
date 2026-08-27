inherit "/std/raza";
#include "light_defs.inc"

void setup() {
  	set_long("Un Dios es el gobernador de un MUD.\n");
  	set_name("dios");
  	set_light_limits(LIGHT_GOD_LOW, LIGHT_GOD_HIGH);
	}

void set_racial_bonuses() {
  	previous_object()->adjust_bonus_int(97);
  	previous_object()->adjust_bonus_dex(97);
  	previous_object()->adjust_bonus_str(97);
  	previous_object()->adjust_bonus_wis(97);
  	previous_object()->adjust_bonus_con(97);
  	}

string query_desc(object ob) {
  	switch((int)ob->query_gender()) {
    		case 1 : return "Te quedas maravillado por la grandeza de un Dios.\n";
    		case 2 : return "Pierdes el sentido por la sobrenatural belleza de una Diosa.\n";
    		case 3 : return "Ves a un raro Dios hermafrodita.\n";
    		default: return "Ves un Dios aparentemente asexual.\n";
  		}
	}
