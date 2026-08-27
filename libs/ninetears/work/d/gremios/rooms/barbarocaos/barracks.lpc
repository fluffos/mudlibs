inherit "/std/guildroom";
#include "definepage.h"

void setup() {
  set_short(GUILDTITLE);
  set_long(GUILDTITLE+"\nEste es el impresionante gremio de los aguerridos Barbaros del Caos, aqui es donde se entrenan bajo las ordenes de Espartaco y maquinan la forma de conquistar Driade para su Diosa. Si has venido a atacar el gremio, deberias irte antes de que Espartaco se enfade...\n\n");
  add_sign("Un grotesco tablon hecho con piel humana.\nTiene unas letras escritas con sangre.\n",
           	"\t________________________________________  \n"
           	"\t|\\______________________________________/| \n"
           	"\t||                                      || \n"
           	"\t||        BIENVENIDO AL GREMIO          || \n"
		"\t||      DE LOS BARBAROS DEL CAOS        || \n"
	        "\t||                                      || \n"
           	"\t||   -- Usa 'alistarse' para unirte     || \n"
           	"\t||      a este gremio.                  || \n"
           	"\t||   -- Para mas informacion sobre      || \n"
           	"\t||      ellos usa 'info'.               || \n"
           	"\t||                                      || \n"
           	"\t||______________________________________|| \n"
           	"\t|/______________________________________\\| \n\n","Piel","piel");
  	add_exit(O, "/room/plaza/campo_discordia_35", "door");
    	add_exit (E,GUILDDIR"hall","standard");
    	modify_exit(E,({"function", "guildmaster"}));
  	set_guild("barbarocaos");
	set_guildmaster(GUILDMASTER);
	}

int piedra(string str) {
	if (!str) return notify_fail("Arrodillarse ante quien?\n");
	str=lower_case(str);
	if (str!="espartaco" || !guildmaster) return notify_fail("Arrodillarse ante quien?\n");
	tell_room(environment(TP),TP->query_cap_name()+" se arrodilla ante el cetro de poder de Espartaco.\n",TP);
	if (TP->query_guild_ob()!="/rol/gremios/barbarocaos") return notify_fail("Espartaco solo da Piedras de Curtir a los miembros de su gremio.\n");
	if (TP->query_property("piedra")) return notify_fail("Espartaco ya te dio una Piedra de Curtir hace poco.\n");
	
	tell_object(TP, "Espartaco te dice: Aqui tienes tu Piedra de Curtir.\n");
	clone_object("/baseobs/misc/piedra")->move(TP);
	TP->add_timed_property("piedra",1,1800);
	return 1;
	}	

int guildmaster() {
        if (TP->query_guild_ob()==GUILDOWNER) return 1;
        if (!guildmaster) {
                tell_object(TP,"Te aprovechas de que no esta el jefe del gremio para colarte en el.\n");
                return 1;
        	}
	return notify_fail("El jefe del gremio te impide la entrada al gremio.\n");
	}

void init() {
    ::init();
    add_action("piedra","bow");
    }