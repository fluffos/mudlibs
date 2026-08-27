inherit "/std/raza";
#include "light_defs.inc"
#include <tiempo.h>
#define STONE "/d/gremios/hechizos/cleric/stoned"

void setup() {
    	set_long("Uno de los feos Troll que Leviathan quiere poner en juego.\n");
    	set_name("troll");
    	set_light_limits(LIGHT_TROLL_LOW, LIGHT_TROLL_HIGH);
	}

void set_racial_bonuses() {
    	previous_object()->adjust_bonus_con(3);
    	previous_object()->adjust_bonus_int(-3);
    	previous_object()->adjust_bonus_str(5);
    	previous_object()->adjust_bonus_wis(-3);
    	previous_object()->adjust_bonus_cha(-(previous_object()->query_cha()-3));
	} /* set_racial_bonuses() */

string query_desc(object ob) { return "Un Troll realmente feo.\n"; }

void race_heartbeat(object player) {
    	object stone, *obs;
    	int i;

    	if(!player || !ENV(player) || player->query_dead()) return;
    	if(!ENV(player)->query_property("noguild")) {
	    	obs = all_inventory(ENV(player));
	    	obs -= ({ player });
	    	tell_room(ENV(player),player->query_cap_name()+" lo revuelve todo atacando a cualquier cosa que se mueva.\n",player);
	    	for(i=0;i<sizeof(obs);i++) {
			if(!living(obs[i])) continue;
			if(obs[i]->query_race() != "troll") player->attack_ob(obs[i]);
	    		}

		if(ENV(player)->query_outside() && !CICLO_HANDLER->query_noche() ) {
	    		if(player->query_property("stoned")) return;
			tell_object(player, "Te sientes lento, sientes tu cuerpo pesar toneladas en cada movimiento. Tu piel se vuelve dura hasta que ya no pudes moverte\n");
	    		stone = clone_object(STONE);
	    		player->add_static_property("stoned",1);
	    		stone->move(player);
	    		stone->reset_get();
	    		stone->setup_shadow(player);
	    		return;
			}
		else if(player->query_static_property("stoned")) {
	    		tell_object(player, "Al apartarte del sol ardiente, te empiezas a sentir mas ligero y tu piel vuelve a ser normal.\n");
	    		player->remove_static_property("stoned");
	    		player->dispell_me();
			}
		}
	player->add_static_property("fire",-100);
    	}

