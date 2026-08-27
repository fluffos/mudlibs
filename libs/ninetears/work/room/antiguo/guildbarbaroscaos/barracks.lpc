inherit "/std/guildroom";
#include "definepage.h"

object guildmaster;

void setup() {
  set_short(GUILDTITLE);
  set_long(GUILDTITLE+"Este es el impresionante gremio de los aguerridos Barbaros del Caos, aqui es donde se entrenan bajo las ordenes de Espartaco y maquinan la forma de conquistar Driade para su Diosa. Si has venido a atacar el gremio, deberias irte antes de que Espartaco se enfade...\n\n");
  add_sign("Un grotesco tablon hecho con piel humana.\nTiene unas letras escritas con sangre.\n",
           	"\t________________________________________  \n"
           	"\t|\\______________________________________/| \n"
           	"\t||                                      || \n"
           	"\t||        BIENVENIDO AL GREMIO          || \n"
		"\t||      DE LOS BARBAROS DEL CAOS        || \n"
	        "\t||                                      || \n"
           	"\t||   -- Usa 'alistar' para unirte a     || \n"
           	"\t||      este gremio.                    || \n"
           	"\t||   -- Para mas informacion sobre      || \n"
           	"\t||      ellos usa 'info'.               || \n"
           	"\t||   -- Para subir de nivel escribe     || \n"
           	"\t||      'avanzar'.                      || \n"
           	"\t||   -- Si quieres saber lo que te      || \n"
           	"\t||      costara subir de nivel, usa     || \n"
           	"\t||      'coste'.                        || \n"
           	"\t||                                      || \n"
           	"\t||______________________________________|| \n"
           	"\t|/______________________________________\\| \n\n","Piel","piel");
  	set_light (LUZ);
  	add_exit(S, ROOMDESALIDA, "door");
  	set_guild(GUILD);
	set_teaching_person(TEACHINGPERSON);

    	add_exit (E,GUILDDIR"hall","standard");
    	modify_exit(E,({"function", "guildmaster"}));
	}

void reset() {
	if (!guildmaster) {
		guildmaster=clone_object(GUILDMASTER);
		guildmaster->move(TO);
		}
	}
	
void init() {
	add_action("piedra","kneeldown");
	::init();
	}
	
int piedra(string str) {
	if (!str) return notify_fail("Arrodillarse ante quien?\n");
	str=capitalize(str);
	if (str!="Espartaco" || !guildmaster) return notify_fail("Arrodillarse ante quien?\n");
	tell_room(environment(TP),TP->query_cap_name()+" se arrodilla ante el cetro de poder de Espartaco.\n",TP);
	if (TP->query_guild_ob()!="/d/gremios/guerreros/barbarocaos") return notify_fail("Espartaco solo da Piedras de Curtir a los miembros de su gremio.\n");
	if (TP->query_property("piedra")) return notify_fail("Espartaco ya te dio una Piedra de Curtir hace poco.\n");
	
	tell_object(TP, "Espartaco te dice: Aqui tienes tu Piedra de Curtir.\n");
	clone_object("/room/guildbarbaroscaos/items/piedra")->move(TP);
	TP->add_timed_property("piedra",1,1800);
	return 1;
	}	

int do_join(string str) {
	if (!guildmaster) return notify_fail("No hay nadie que te pueda alistar al gremio en este momento.\n");
	if (guildmaster->query_fighting()) return notify_fail("El jefe del gremio no te puede alistar, esta ocupado pensando en sus enemigos.\n");
	TP->set_kill_xp((TP->query_level() / 2) * 1000000);
	return ::do_join(str);
	}

int guildmaster() {
        if (TP->query_guild_ob()==GUILDOWNER) return 1;
        if (!guildmaster) {
                tell_object(TP,"Te aprovechas de que no esta el jefe del gremio para colarte en el.\n");
                return 1;
        	}
	return notify_fail("El jefe del gremio te impide la entrada al gremio.\n");
	}


