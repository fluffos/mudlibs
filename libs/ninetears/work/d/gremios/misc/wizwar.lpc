//Vilat 24.08.2002
//Actualizado para el nuevo sistema

inherit "/std/guild";

string help() {
    	return "Este es el gremio de los Barbaros del Caos, guerreros fanaticos y salvajes donde los haya, que se dedican a extender el mal por Driade en nombre de su diosa Jade, la senyora del Mal. Aunque no pueden utilizar armaduras pesadas, lo compensan gracias a sus grandes dotes para el combate y son capaces de fabricar su propio equipo.\n";
    	reset_get();
	}

int query_ac(int level);

void setup() {
    	set_name("barbarocaos");
    	set_short("Barbaro del Caos");
    	set_long("Este es el gremio de los Barbaros del Caos, guerreros fanaticos y salvajes donde los haya, que se dedican a extender el mal por Driade en nombre de su diosa Jade, la senyora del Mal. Aunque no pueden utilizar armaduras pesadas, lo compensan gracias a sus grandes dotes para el combate y son capaces de fabricar su propio equipo.\n");
    	reset_get();

	set_needed_align(({-1}),({-1}));

    	add_guild_command("aplastar",1);
    	add_guild_command("cazar", 1);
  	add_guild_command("furia", 1);
  	add_guild_command("curtir", 1);
  	add_guild_command("despellejar", 1);

	set_xp_cost(2200);
	set_thac0_step(6);
	set_clase("Guerrero");
	}

int query_legal_race(string race) {
	race=capitalize(race);
    	switch(race) {
    		case "Humano":
		case "Human":
    		case "Immortal":
    		case "Inmortal":
		return 1;
    		default:
		return 0;
    		}
	log_file("fallos_gremios","Error en el Gremio "+TO->query_name()+": No se pudo procesar la raza '"+race+"'.\n");
	return 0;
	}

//Aki las restricciones
int query_legal_armour(string str) {
	str=lower_case(str);
	switch (str) {
		case "cota":
    		case "malla":
    		case "cota_elfica":
    		case "cota_reforzada":
		case "coraza":
    		case "placas_bronce":
		case "placas":
		case "campanya":
		case "completa":
		case "yelmo":
		case "casco":
		case "yelmo_grande":
		case "brazal_metal":
		case "guantelete":
		case "greba_metal":
		case "botas_metal":
		return 0;

    		default:
    		return 1;
    		}
	log_file("fallos_gremios","Error en el Gremio "+TO->query_name()+": No se pudo procesar la armadura '"+str+"'.\n");
	return;
	}

int query_hp_dice(object myp) 	{ return 4; }
int query_hp_min(object myp)  	{ return 7; }
int query_gp_dice(object myp) 	{ return 3; }
int query_gp_min(object myp)  	{ return 2; }
int query_ep_dice(object myp) 	{ return 3; }
int query_ep_min(object myp)  	{ return 4; }
int query_sp_dice(object myp) 	{ return 3; }
int query_sp_min(object myp)  	{ return 4; }


string query_title(object ob) {
	if (ob->query_gender() == 1) {
		switch(ob->query_level()) {
			case 0..10:
				return "Servidor de la Tribu";
			case 11..15:
				return "Soldado de la Tribu";
			case 16..20:
				return "Guardian de la Tribu";
			case 21..25:
				return "Consejero de la Tribu";
			case 26..30:
				return "Anciano de la Tribu";
			case 31..35:
				return "Aniquilador del Bien";
			case 36..40:
				return "Famoso Barbaro del Caos";
			case 41..45:
				return "Senyor de la Guerra del Caos";
			case 46..50:
				return "Conquistador de Reinos";
			case 51..55:
			case 56..60:
			case 61..1000:
				return "%^BOLD%^BLACK%^Caudillo Oscuro %^RESET%^del %^BOLD%^RED%^Caos%^RESET%^";
			default:
				return "Bug";
			}
		}
	else {
		switch(ob->query_level()) {
			case 0..10:
				return "Servidora de la Tribu";
			case 11..15:
				return "Soldado de la Tribu";
			case 16..20:
				return "Guardiana de la Tribu";
			case 21..25:
				return "Consejera de la Tribu";
			case 26..30:
				return "Anciana de la Tribu";
			case 31..35:
				return "Aniquiladora del Bien";
			case 36..40:
				return "Famosa Valquiria del Caos";
			case 41..45:
				return "Senyora de la Guerra del Caos";
			case 46..50:
				return "Conquistadora de Reinos";
			case 51..55:
			case 56..60:
			case 61..1000:
				return "%^BOLD%^BLACK%^Caudilla Oscura %^RESET%^del %^BOLD%^RED%^Caos%^RESET%^";
			default:
				return "Bug";
			}
		}
	}

int query_dual_wield_penalty(object me, object w1, object w2) {
  	int bon;

  	bon = 50 - me->query_level()*2;
  	if (bon<0) bon=0;
  	return bon;
	}

